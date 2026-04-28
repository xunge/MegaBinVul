#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define RFB_INVALID_SOCKET -1
#define Z_OK 0

typedef struct {
    char* msg;
} z_stream;

typedef struct rfbClientData {
    struct rfbClientData* next;
} rfbClientData;

typedef struct rfbClient {
    int zlibStreamActive[4];
    z_stream zlibStream[4];
    int decompStreamInited;
    z_stream decompStream;
    char* ultra_buffer;
    char* raw_buffer;
    rfbClientData* clientData;
    void* vncRec;
    int sock;
    int listenSock;
    char* desktopName;
    char* serverHost;
    char* destHost;
    int* clientAuthSchemes;
    char* saslSecret;
} rfbClient;

void rfbClientLog(const char* format, ...);
void rfbClientErr(const char* format, ...);
void rfbCloseSocket(int sock);
void FreeTLS(rfbClient* client);
int inflateEnd(z_stream* strm);