//
// ftpdaemon.cpp
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

// #include <circle/logger.h>
// #include <circle/net/in.h>
// #include <circle/net/ipaddress.h>
// #include <circle/net/netsubsystem.h>
// #include <circle/string.h>

#include "ftpdaemon.h"
#include "ftpworker.h"

// LOGMODULE("ftpd");

constexpr u16 ListenPort = 21;
constexpr u8 MaxConnections = 1;

CFTPDaemon::CFTPDaemon(const char* pUser, const char* pPassword, CmDNSPublisher* pMDNSPublisher, CConfig* pConfig)
{
}

CFTPDaemon::~CFTPDaemon()
{
	if (m_pListenSocket)
		delete m_pListenSocket;
}

bool CFTPDaemon::Initialize()
{
}

void CFTPDaemon::Run()
{
}