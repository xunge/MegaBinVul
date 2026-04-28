#include <stddef.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define LC_ASSERT(expr) ((void)0)
#define INVALID_SOCKET (-1)
#define CAPABILITY_DIRECT_SUBMIT (1 << 0)
#define RTP_RECV_BUFFER (0)
#define FIRST_FRAME_PORT (47998)
#define FIRST_FRAME_TIMEOUT_SEC (5)

typedef struct {
    int width;
    int height;
    int fps;
} StreamConfig_t;

typedef struct {
    void (*setup)(int format, int width, int height, int fps, void* ctx, int flags);
    int capabilities;
} VideoCallbacks_t;

extern int NegotiatedVideoFormat;
extern StreamConfig_t StreamConfig;
extern VideoCallbacks_t VideoCallbacks;
extern int rtpSocket;
extern int firstFrameSocket;
extern struct sockaddr_storage RemoteAddr;
extern socklen_t RemoteAddrLen;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern int receiveThread;
extern int decoderThread;
extern int udpPingThread;

int bindUdpSocket(int family, int bufferSize);
int LastSocketError(void);
int PltCreateThread(void* (*proc)(void*), void* arg, int* thread);
int connectTcpSocket(struct sockaddr_storage* addr, socklen_t addrLen, int port, int timeout);
int readFirstFrame(void);
void* ReceiveThreadProc(void* arg);
void* DecoderThreadProc(void* arg);
void* UdpPingThreadProc(void* arg);