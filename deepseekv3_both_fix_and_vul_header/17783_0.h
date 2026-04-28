#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifdef WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

typedef int rfbBool;
#define FALSE 0
#define TRUE 1

typedef struct rfbVNCRec {
    FILE *file;
    int readTimestamp;
    int doNotSleep;
    struct timeval tv;
} rfbVNCRec;

typedef struct rfbClient {
    int serverPort;
    rfbVNCRec *vncRec;
    unsigned int buffered;
    char *bufoutptr;
    char *buf;
    int sock;
    void *tlsSession;
#ifdef LIBVNCSERVER_HAVE_SASL
    void *saslconn;
#endif
    int readTimeout;
#define RFB_BUF_SIZE 8192
} rfbClient;

extern int errorMessageOnReadFailure;
extern void rfbClientLog(const char *format, ...);
extern void rfbClientErr(const char *format, ...);
extern int ReadFromTLS(rfbClient *client, char *out, unsigned int n);
#ifdef LIBVNCSERVER_HAVE_SASL
extern int ReadFromSASL(rfbClient *client, char *out, unsigned int n);
#endif
extern void WaitForMessage(rfbClient *client, int usecs);
extern rfbBool rfbClientSwap32IfLE(int value);