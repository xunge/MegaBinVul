#include <stdint.h>
#include <stddef.h>

#define TH_RST 0x04
#define STREAMTCP_STREAM_FLAG_RST_RECV 0x01
#define TCP_CLOSED 0

typedef struct ThreadVars ThreadVars;

typedef struct PacketQueueNoLock {
    int dummy;
} PacketQueueNoLock;

typedef struct TcpHdr {
    uint8_t th_flags;
} TcpHdr;

typedef struct TcpStream {
    uint8_t flags;
} TcpStream;

typedef struct StreamTcpThread {
    PacketQueueNoLock pseudo_queue;
} StreamTcpThread;

typedef struct TcpSession {
    TcpStream client;
    TcpStream server;
    int state;
    int pstate;
} TcpSession;

typedef struct Packet {
    TcpHdr *tcph;
} Packet;

#define PKT_IS_TOSERVER(p) (0)
#define SCLogDebug(...)
extern int StreamTcpStateDispatch(ThreadVars *tv, Packet *p, StreamTcpThread *stt, TcpSession *ssn, PacketQueueNoLock *pq, int pstate);