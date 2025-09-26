//
// ftpworker.cpp
//
// mt32-pi - A baremetal MIDI synthesizer for Raspberry Pi
// Copyright (C) 2020-2023 Dale Whinham <daleyo@gmail.com>
//
// This file is part of mt32-pi.
//
// mt32-pi is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// mt32-pi is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// mt32-pi. If not, see <http://www.gnu.org/licenses/>.
//

//#define FTPDAEMON_DEBUG

// #include <circle/logger.h>
// #include <circle/net/in.h>
// #include <circle/net/netsubsystem.h>
// #include <circle/sched/scheduler.h>
// #include <circle/timer.h>
// #include <circle/startup.h>
// #include <fatfs/ff.h>

// #include <cstdio>

#include "ftpworker.h"
// #include "utility.h"

// Use a per-instance name for the log macros
#define From m_LogName

constexpr u16 PassivePortBase = 9000;
constexpr size_t TextBufferSize = 512;
constexpr unsigned int SocketTimeout = 60;
constexpr unsigned int NumRetries = 3;

#ifndef MT32_PI_VERSION
#define MT32_PI_VERSION "(version unknown)"
#endif

const char MOTDBanner[] = "Welcome to the MiniDexed " MT32_PI_VERSION " embedded FTP server!";
const char* exclude_filename = "wpa_supplicant.conf";

enum class TDirectoryListEntryType
{
	File,
	Directory,
};

struct TDirectoryListEntry
{
	char Name[FF_LFN_BUF + 1];
	TDirectoryListEntryType Type;
	u32 nSize;
	u16 nLastModifedDate;
	u16 nLastModifedTime;
};

using TCommandHandler = bool (CFTPWorker::*)(const char* pArgs);

struct TFTPCommand
{
	const char* pCmdStr;
	TCommandHandler pHandler;
};

const TFTPCommand CFTPWorker::Commands[] =
{
	{ "SYST",	&CFTPWorker::System			},
	{ "USER",	&CFTPWorker::Username			},
	{ "PASS",	&CFTPWorker::Password			},
	{ "TYPE",	&CFTPWorker::Type			},
	{ "PASV",	&CFTPWorker::Passive			},
	{ "PORT",	&CFTPWorker::Port			},
	{ "RETR",	&CFTPWorker::Retrieve			},
	{ "STOR",	&CFTPWorker::Store			},
	{ "DELE",	&CFTPWorker::Delete			},
	{ "RMD",	&CFTPWorker::Delete			},
	{ "MKD",	&CFTPWorker::MakeDirectory		},
	{ "CWD",	&CFTPWorker::ChangeWorkingDirectory	},
	{ "CDUP",	&CFTPWorker::ChangeToParentDirectory	},
	{ "PWD",	&CFTPWorker::PrintWorkingDirectory	},
	{ "LIST",	&CFTPWorker::List			},
	{ "NLST",	&CFTPWorker::ListFileNames		},
	{ "RNFR",	&CFTPWorker::RenameFrom			},
	{ "RNTO",	&CFTPWorker::RenameTo			},
	{ "BYE",	&CFTPWorker::Bye			},
	{ "QUIT",	&CFTPWorker::Bye			},
	{ "NOOP",	&CFTPWorker::NoOp			},
};

u8 CFTPWorker::s_nInstanceCount = 0;

// Volume names from ffconf.h
// TODO: Share with soundfontmanager.cpp
const char* const VolumeNames[] = { FF_VOLUME_STRS };

bool ValidateVolumeName(const char* pVolumeName)
{
	for (const auto pName : VolumeNames)
	{
		if (strcasecmp(pName, pVolumeName) == 0)
			return true;
	}

	return false;
}

// Comparator for sorting directory listings
inline bool DirectoryCaseInsensitiveAscending(const TDirectoryListEntry& EntryA, const TDirectoryListEntry& EntryB)
{
	// Directories first in ascending order
	if (EntryA.Type != EntryB.Type)
		return EntryA.Type == TDirectoryListEntryType::Directory;

	return strncasecmp(EntryA.Name, EntryB.Name, sizeof(TDirectoryListEntry::Name)) < 0;
}


CFTPWorker::CFTPWorker(CSocket* pControlSocket, const char* pExpectedUser, const char* pExpectedPassword, CmDNSPublisher* pMDNSPublisher, CConfig* pConfig)
{
	++s_nInstanceCount;
	m_LogName.Format("ftpd[%d]", s_nInstanceCount);
}

CFTPWorker::~CFTPWorker()
{
	if (m_pControlSocket)
		delete m_pControlSocket;

	if (m_pDataSocket)
		delete m_pDataSocket;

	--s_nInstanceCount;

	//LOGNOTE("Instance count is now %d", s_nInstanceCount);
}

void CFTPWorker::Run()
{
}

CSocket* CFTPWorker::OpenDataConnection()
{
}

bool CFTPWorker::SendStatus(TFTPStatus StatusCode, const char* pMessage)
{
}

bool CFTPWorker::CheckLoggedIn()
{
#ifdef FTPDAEMON_DEBUG
	LOGDBG("Username compare: expected '%s', actual '%s'", static_cast<const char*>(m_pExpectedUser), static_cast<const char*>(m_User));
	LOGDBG("Password compare: expected '%s', actual '%s'", static_cast<const char*>(m_pExpectedPassword),  static_cast<const char*>(m_Password));
#endif

	if (m_User.Compare(m_pExpectedUser) == 0 && m_Password.Compare(m_pExpectedPassword) == 0)
		return true;

	SendStatus(TFTPStatus::NotLoggedIn, "Not logged in.");
	return false;
}

CString CFTPWorker::RealPath(const char* pInBuffer) const
{
	//assert(pInBuffer != nullptr);

	CString Path;
	const bool bAbsolute = pInBuffer[0] == '/';

	if (bAbsolute)
	{
		char Buffer[TextBufferSize];
		FTPPathToFatFsPath(pInBuffer, Buffer, sizeof(Buffer));
		Path = Buffer;
	}
	else
		Path.Format("%s/%s", static_cast<const char*>(m_CurrentPath), pInBuffer);

	return Path;
}

const TDirectoryListEntry* CFTPWorker::BuildDirectoryList(size_t& nOutEntries) const
{
}

bool CFTPWorker::System(const char* pArgs)
{
	// Some FTP clients (e.g. Directory Opus) will only attempt to parse LIST responses as IIS/DOS-style if we pretend to be Windows NT
	SendStatus(TFTPStatus::SystemType, "Windows_NT");
	return true;
}

bool CFTPWorker::Username(const char* pArgs)
{
	m_User = pArgs;
	char Buffer[TextBufferSize];
	snprintf(Buffer, sizeof(Buffer), "Password required for '%s'.", static_cast<const char*>(m_User));
	SendStatus(TFTPStatus::PasswordRequired, Buffer);
	return true;
}

bool CFTPWorker::Port(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	char Buffer[TextBufferSize];
	strncpy(Buffer, pArgs, sizeof(Buffer) - 1);

	if (m_pDataSocket != nullptr)
	{
		delete m_pDataSocket;
		m_pDataSocket = nullptr;
	}

	m_TransferMode = TTransferMode::Active;

	// TODO: PORT IP Address should match original IP address

	u8 PortBytes[6];
	char* pSavePtr;
	char* pToken = strtok_r(Buffer, " ,", &pSavePtr);
	bool bParseError = (pToken == nullptr);

	if (!bParseError)
	{
		PortBytes[0] = static_cast<u8>(atoi(pToken));

		for (u8 i = 0; i < 5; ++i)
		{
			pToken = strtok_r(nullptr, " ,", &pSavePtr);
			if (pToken == nullptr)
			{
				bParseError = true;
				break;
			}

			PortBytes[i + 1] = static_cast<u8>(atoi(pToken));
		}
	}

	if (bParseError)
	{
		SendStatus(TFTPStatus::SyntaxError, "Syntax error.");
		return false;
	}
}

bool CFTPWorker::Passive(const char* pArgs)
{
}

bool CFTPWorker::Password(const char* pArgs)
{
	if (m_User.GetLength() == 0)
	{
		SendStatus(TFTPStatus::AccountRequired, "Need account for login.");
		return false;
	}

	m_Password = pArgs;

	if (!CheckLoggedIn())
		return false;

	SendStatus(TFTPStatus::UserLoggedIn, "User logged in.");
	return true;
}

bool CFTPWorker::Type(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	if (strcasecmp(pArgs, "A") == 0)
	{
		m_DataType = TDataType::ASCII;
		SendStatus(TFTPStatus::Success, "Type set to ASCII.");
		return true;
	}

	if (strcasecmp(pArgs, "I") == 0)
	{
		m_DataType = TDataType::Binary;
		SendStatus(TFTPStatus::Success, "Type set to binary.");
		return true;
	}

	SendStatus(TFTPStatus::SyntaxError, "Syntax error.");
	return false;
}

bool CFTPWorker::Retrieve(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	FIL File;
	CString Path = RealPath(pArgs);

	// Disallow any file named wpa_supplicant.conf (case-insensitive) in any directory
	const char* pathStr = Path;
	const char* lastSep = nullptr;
	for (const char* p = pathStr; *p; ++p) {
		if (*p == '/' || *p == ':') lastSep = p;
	}
	const char* filename = lastSep ? lastSep + 1 : pathStr;
	// Case-insensitive compare using strcasecmp if available
	if (strcasecmp(filename, "wpa_supplicant.conf") == 0)
	{
		SendStatus(TFTPStatus::FileNameNotAllowed, "Reading this file is not allowed");
		return false;
	}
}

bool CFTPWorker::Store(const char* pArgs)
{
}

bool CFTPWorker::Delete(const char* pArgs)
{
}

bool CFTPWorker::MakeDirectory(const char* pArgs)
{
}

bool CFTPWorker::ChangeWorkingDirectory(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	char Buffer[TextBufferSize];
	bool bSuccess = false;

	const bool bAbsolute = pArgs[0] == '/';
	if (bAbsolute)
	{
		// Root
		if (pArgs[1] == '\0')
		{
			m_CurrentPath = "";
			bSuccess = true;
		}
		else
		{
		}
	}
	else
	{
		const bool bAtRoot = m_CurrentPath.GetLength() == 0;
		if (bAtRoot)
		{
			if (ValidateVolumeName(pArgs))
			{
				m_CurrentPath.Format("%s:", pArgs);
				bSuccess = true;
			}
		}
		else
		{
		}
	}

	if (bSuccess)
	{
		const bool bAtRoot = m_CurrentPath.GetLength() == 0;
		if (bAtRoot)
			strncpy(Buffer, "\"/\"", sizeof(Buffer));
		else
			FatFsPathToFTPPath(m_CurrentPath, Buffer, sizeof(Buffer));
		SendStatus(TFTPStatus::FileActionOk, Buffer);
	}
	else
		SendStatus(TFTPStatus::FileNotFound, "Directory unavailable.");

	return bSuccess;
}

bool CFTPWorker::ChangeToParentDirectory(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	char Buffer[TextBufferSize];
	bool bSuccess = false;
	bool bAtRoot = m_CurrentPath.GetLength() == 0;

	if (!bAtRoot)
	{
		DIR Dir;
		FatFsParentPath(m_CurrentPath, Buffer, sizeof(Buffer));

		bAtRoot = Buffer[0] == '\0';
		if (bAtRoot)
		{
			m_CurrentPath = Buffer;
			bSuccess = true;
		}
	}

	if (bSuccess)
	{
		bAtRoot = m_CurrentPath.GetLength() == 0;
		if (bAtRoot)
			strncpy(Buffer, "\"/\"", sizeof(Buffer));
		else
			FatFsPathToFTPPath(m_CurrentPath, Buffer, sizeof(Buffer));
		SendStatus(TFTPStatus::FileActionOk, Buffer);
	}
	else
		SendStatus(TFTPStatus::FileNotFound, "Directory unavailable.");

	return false;
}

bool CFTPWorker::PrintWorkingDirectory(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	char Buffer[TextBufferSize];

	const bool bAtRoot = m_CurrentPath.GetLength() == 0;
	if (bAtRoot)
		strncpy(Buffer, "\"/\"", sizeof(Buffer));
	else
		FatFsPathToFTPPath(m_CurrentPath, Buffer, sizeof(Buffer));

	SendStatus(TFTPStatus::PathCreated, Buffer);

	return true;
}

bool CFTPWorker::List(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	if (!SendStatus(TFTPStatus::FileStatusOk, "Command OK."))
		return false;

	CSocket* pDataSocket = OpenDataConnection();
	if (pDataSocket == nullptr)
		return false;

	char Buffer[TextBufferSize];
	char Date[9];
	char Time[8];

	size_t nEntries;
	const TDirectoryListEntry* pDirEntries = BuildDirectoryList(nEntries);

	if (pDirEntries)
	{
		for (size_t i = 0; i < nEntries; ++i)
		{
			const TDirectoryListEntry& Entry = pDirEntries[i];
			int nLength;

			// Mimic the Microsoft IIS LIST format
			FormatLastModifiedDate(Entry.nLastModifedDate, Date, sizeof(Date));
			FormatLastModifiedTime(Entry.nLastModifedTime, Time, sizeof(Time));

			if (Entry.Type == TDirectoryListEntryType::Directory)
				nLength = snprintf(Buffer, sizeof(Buffer), "%-9s %-13s %-14s %s\r\n", Date, Time, "<DIR>", Entry.Name);
			else
				nLength = snprintf(Buffer, sizeof(Buffer), "%-9s %-13s %14d %s\r\n", Date, Time, Entry.nSize, Entry.Name);

			if (1)
			{
				delete[] pDirEntries;
				delete pDataSocket;
				SendStatus(TFTPStatus::DataConnectionFailed, "Transfer error.");
				return false;
			}
		}

		delete[] pDirEntries;
	}

	delete pDataSocket;
	SendStatus(TFTPStatus::TransferComplete, "Transfer complete.");
	return true;
}

bool CFTPWorker::ListFileNames(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	if (!SendStatus(TFTPStatus::FileStatusOk, "Command OK."))
		return false;

	CSocket* pDataSocket = OpenDataConnection();
	if (pDataSocket == nullptr)
		return false;

	char Buffer[TextBufferSize];
	size_t nEntries;
	const TDirectoryListEntry* pDirEntries = BuildDirectoryList(nEntries);

	if (pDirEntries)
	{
	}

	delete pDataSocket;
	SendStatus(TFTPStatus::TransferComplete, "Transfer complete.");
	return true;
}

bool CFTPWorker::RenameFrom(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	m_RenameFrom = pArgs;
	SendStatus(TFTPStatus::PendingFurtherInfo, "Requested file action pending further information.");

	return false;
}

bool CFTPWorker::RenameTo(const char* pArgs)
{
	if (!CheckLoggedIn())
		return false;

	if (m_RenameFrom.GetLength() == 0)
	{
		SendStatus(TFTPStatus::BadCommandSequence, "Bad sequence of commands.");
		return false;
	}
	return false;
}

bool CFTPWorker::Bye(const char* pArgs)
{
}

bool CFTPWorker::NoOp(const char* pArgs)
{
	SendStatus(TFTPStatus::Success, "Command OK.");
	return true;
}

void CFTPWorker::FatFsPathToFTPPath(const char* pInBuffer, char* pOutBuffer, size_t nSize)
{
	//assert(pOutBuffer && nSize > 2);
	const char* pEnd = pOutBuffer + nSize;
	const char* pInChar = pInBuffer;
	char* pOutChar = pOutBuffer;

	*pOutChar++ = '"';
	*pOutChar++ = '/';

	while (*pInChar != '\0' && pOutChar < pEnd)
	{
		// Kill the volume colon
		if (*pInChar == ':')
		{
			*pOutChar++ = '/';
			++pInChar;

			// Kill any slashes after the colon
			while (*pInChar == '/') ++pInChar;
			continue;
		}

		// Kill duplicate slashes
		if (*pInChar == '/')
		{
			*pOutChar++ = *pInChar++;
			while (*pInChar == '/') ++pInChar;
			continue;
		}

		*pOutChar++ = *pInChar++;
	}

	// Kill trailing slash
	if (*(pOutChar - 1) == '/')
		--pOutChar;

	//assert(pOutChar < pEnd - 2);
	*pOutChar++ = '"';
	*pOutChar++ = '\0';
}

void CFTPWorker::FTPPathToFatFsPath(const char* pInBuffer, char* pOutBuffer, size_t nSize)
{
	//assert(pInBuffer && pOutBuffer);
	const char* pEnd = pOutBuffer + nSize;
	const char* pInChar = pInBuffer;
	char* pOutChar = pOutBuffer;

	// Kill leading slashes
	while (*pInChar == '/') ++pInChar;

	bool bGotVolume = false;
	while (*pInChar != '\0' && pOutChar < pEnd)
	{
		// Kill the volume colon
		if (!bGotVolume && *pInChar == '/')
		{
			bGotVolume = true;
			*pOutChar++ = ':';
			++pInChar;

			// Kill any slashes after the colon
			while (*pInChar == '/') ++pInChar;
			continue;
		}

		// Kill duplicate slashes
		if (*pInChar == '/')
		{
			*pOutChar++ = *pInChar++;
			while (*pInChar == '/') ++pInChar;
			continue;
		}

		*pOutChar++ = *pInChar++;
	}

	//assert(pOutChar < pEnd - 2);

	// Kill trailing slash
	if (*(pOutChar - 1) == '/')
		--pOutChar;

	// Add volume colon
	if (!bGotVolume)
		*pOutChar++ = ':';

	*pOutChar++ = '\0';
}

void CFTPWorker::FatFsParentPath(const char* pInBuffer, char* pOutBuffer, size_t nSize)
{
	//assert(pInBuffer != nullptr && pOutBuffer != nullptr);

	size_t nLength = strlen(pInBuffer);
	//assert(nLength > 0 && nSize >= nLength);

	const char* pLastChar = pInBuffer + nLength - 1;
	const char* pInChar = pLastChar;

	// Kill trailing slashes
	while (*pInChar == '/' && pInChar > pInBuffer) --pInChar;

	// Kill subdirectory name
	while (*pInChar != '/' && *pInChar != ':' && pInChar > pInBuffer) --pInChar;

	// Kill trailing slashes
	while (*pInChar == '/' && pInChar > pInBuffer) --pInChar;

	// Pointer didn't move (we're already at a volume root), or we reached the start of the string (path invalid)
	if (pInChar == pLastChar || pInChar == pInBuffer)
	{
		*pOutBuffer = '\0';
		return;
	}

	// Truncate string
	nLength = pInChar - pInBuffer + 1;
	memcpy(pOutBuffer, pInBuffer, nLength);
	pOutBuffer[nLength] = '\0';
}

void CFTPWorker::FormatLastModifiedDate(u16 nDate, char* pOutBuffer, size_t nSize)
{
	// 2-digit year
	const u16 nYear = (1980 + (nDate >> 9)) % 100;
	u16 nMonth = (nDate >> 5) & 0x0F;
	u16 nDay = nDate & 0x1F;

	if (nMonth == 0)
		nMonth = 1;
	if (nDay == 0)
		nDay = 1;

	snprintf(pOutBuffer, nSize, "%02d-%02d-%02d", nMonth, nDay, nYear);
}

void CFTPWorker::FormatLastModifiedTime(u16 nDate, char* pOutBuffer, size_t nSize)
{
	u16 nHour = (nDate >> 11) & 0x1F;
	const u16 nMinute = (nDate >> 5) & 0x3F;
	const char* pSuffix = nHour < 12 ? "AM" : "PM";

	if (nHour == 0)
		nHour = 12;
	else if (nHour >= 12)
		nHour -= 12;

	snprintf(pOutBuffer, nSize, "%02d:%02d%s", nHour, nMinute, pSuffix);
}