#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef int rfbBool;
#define FALSE 0
#define TRUE 1

typedef struct rfbClient {
    int sock;
} rfbClient;

#define sz_rfbProtocolVersionMsg 12
#define rfbProtocolVersionFormat "RFB %03d.%03d\n"
typedef char rfbProtocolVersionMsg[sz_rfbProtocolVersionMsg + 1];

void rfbClientLog(const char* format, ...);
int ConnectClientToTcpAddr6(const char *host, int port);
int ConnectClientToTcpAddr(unsigned int host, int port);
int StringToIPAddr(const char *host, unsigned int *ip);
int SetNonBlocking(int sock);
int ReadFromRFBServer(rfbClient *client, char *buf, int len);
int WriteToRFBServer(rfbClient *client, const char *buf, int len);