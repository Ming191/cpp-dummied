#include "ae.h"

// Event loop creation/destruction
aeEventLoop *aeCreateEventLoop(int setsize) {};
void aeDeleteEventLoop(aeEventLoop *eventLoop) {}
void aeStop(aeEventLoop *eventLoop) {}

// File events
int aeCreateFileEvent(...) {};
void aeDeleteFileEvent(aeEventLoop *eventLoop, int fd, int mask) {};
int aeGetFileEvents(aeEventLoop *eventLoop, int fd) { return 0; }

// Time events
long long aeCreateTimeEvent(aeEventLoop *eventLoop, long long milliseconds,
                            aeTimeProc *proc, void *clientData,
                            aeEventFinalizerProc *finalizerProc) { return 0; }

int aeDeleteTimeEvent(aeEventLoop *eventLoop, long long id) { return 0; }

// Processing events
int aeProcessEvents(aeEventLoop *eventLoop, int flags) { return 0; }
int aeWait(int fd, int mask, long long milliseconds) { return 0; }

// Event loop runner
void aeMain(aeEventLoop *eventLoop) {}

// Utility
char *aeGetApiName(void) { return (char*)""; }
void aeSetBeforeSleepProc(aeEventLoop *eventLoop, aeBeforeSleepProc *beforesleep) {}
