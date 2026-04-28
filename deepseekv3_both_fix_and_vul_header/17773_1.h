#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define FALSE 0

typedef struct _rfbClient {
    int reverseConnection;
    void (*clientGoneHook)(struct _rfbClient*);
} rfbClient;
typedef rfbClient* rfbClientPtr;

typedef struct _rfbScreenInfo {
    char* frameBuffer;
    int port;
    int ipv6port;
} rfbScreenInfo;
typedef rfbScreenInfo* rfbScreenInfoPtr;

extern rfbScreenInfoPtr rfbGetScreen(int* argc, char** argv, int width, int height, int bitsPerSample, int samplesPerPixel, int bytesPerPixel);
extern int rfbConnectToTcpAddr(const char* host, int port);
extern rfbClientPtr rfbNewClient(rfbScreenInfoPtr screen, int sock);
extern void rfbInitServer(rfbScreenInfoPtr screen);
extern void rfbRunEventLoop(rfbScreenInfoPtr screen, long usec, int runInBackground);
extern void clientGone(rfbClientPtr cl);