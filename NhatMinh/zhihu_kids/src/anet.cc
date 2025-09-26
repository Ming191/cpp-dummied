#include "anet.h"

// --- ANET (network utils) ---
int anetNonBlock(char *err, int fd) {};
int anetEnableTcpNoDelay(char* err, int fd) {};
int anetTcpServer(char *err, int port, char *bindaddr, int backlog) {};
int anetUnixServer(char *err, char *path, mode_t perm, int backlog) {};
int anetTcpAccept(char *err, int serversock, char *ip, size_t ip_len, int *port) {};
int anetUnixAccept(char* err, int serversock) { return 0; }
int anetTcpConnect(char* err, const char* addr, int port) { return 0; }
int anetUnixConnect(char* err, const char* path) { return 0; }
int anetPeerToString(int fd, char *ip, size_t ip_len, int *port) {};
