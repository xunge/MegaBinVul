#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stddef.h>

#define INVALID_SOCKET (-1)
#define INPUT_STREAM_TIMEOUT_SEC 5

extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern int inputSock;
extern struct sockaddr RemoteAddr;
extern socklen_t RemoteAddrLen;
extern void *inputSendThread;
extern int (*PltCreateThread)(void *, void *, void **);
extern int (*connectTcpSocket)(struct sockaddr *, socklen_t, int, int);
extern int (*enableNoDelay)(int);
extern int (*LastSocketFail)(void);
extern void *inputSendThreadProc;