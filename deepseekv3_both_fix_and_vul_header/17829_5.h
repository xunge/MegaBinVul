#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define WLog_ERR(tag, fmt, ...)
#define TAG ""

typedef struct rdpShadowServer rdpShadowServer;
typedef struct rdpShadowScreen rdpShadowScreen;
typedef struct rdpShadowCapture rdpShadowCapture;

struct rdpShadowListener {
    BOOL (*OpenLocal)(struct rdpShadowListener* listener, const char* path);
};

struct rdpShadowServer {
    rdpShadowScreen* screen;
    rdpShadowCapture* capture;
    char* ipcSocket;
    struct rdpShadowListener* listener;
    pthread_t thread;
};

extern rdpShadowScreen* shadow_screen_new(rdpShadowServer* server);
extern rdpShadowCapture* shadow_capture_new(rdpShadowServer* server);
extern BOOL open_port(rdpShadowServer* server, const char* port);
extern void* shadow_server_thread(void* arg);
extern char** CommandLineParseCommaSeparatedValuesEx(const char* str1, const char* str2, size_t* count);

extern char* bind_address;

#define MAKEWORD(a,b) ((a) | ((b) << 8))
typedef struct {
    unsigned short wVersion;
    unsigned short wHighVersion;
    char szDescription[256];
    char szSystemStatus[128];
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    char* lpVendorInfo;
} WSADATA;
int WSAStartup(unsigned short wVersionRequested, WSADATA* lpWSAData);

#define CreateThread(attr, stack, func, arg, flags, id) \
    ({ \
        pthread_t tid; \
        pthread_create(&tid, NULL, func, arg) == 0 ? tid : 0; \
    })