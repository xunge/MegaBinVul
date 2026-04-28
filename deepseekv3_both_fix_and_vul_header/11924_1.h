#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdint.h>

typedef struct rfbClient rfbClient;
typedef struct rfbTightClient rfbTightClient;
typedef rfbClient* rfbClientPtr;
typedef rfbTightClient* rfbTightClientPtr;

typedef struct {
    uint16_t reasonLen;
} rfbFileDownloadCancelMsg;

typedef struct {
    rfbFileDownloadCancelMsg fdc;
} rfbClientToServerTightMsg;

extern int sz_rfbFileDownloadCancelMsg;
extern pthread_mutex_t fileDownloadMutex;

void rfbCloseClient(rfbClientPtr cl);
int rfbReadExact(rfbClientPtr cl, char* buf, int len);
void rfbLog(const char* format, ...);
uint16_t Swap16IfLE(uint16_t value);
void CloseUndoneFileTransfer(rfbClientPtr cl, rfbTightClientPtr rtcp);