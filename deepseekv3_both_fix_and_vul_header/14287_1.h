#include <stdint.h>
#include <inttypes.h>

#define TH_ACK 0x10
#define STREAM_RST_INVALID_ACK 1

typedef struct TcpStream_ {
    uint32_t next_seq;
    uint32_t last_ack;
    uint32_t window;
    uint8_t os_policy;
    uint32_t flags;
} TcpStream;

typedef struct TcpSession_ {
    TcpStream client;
    TcpStream server;
    uint32_t flags;
} TcpSession;

typedef struct TcpHdr_ {
    uint8_t th_flags;
} TcpHdr;

typedef struct Packet_ {
    TcpHdr *tcph;
    uint32_t payload_len;
    struct {
        uint8_t md5_option_present;
        uint8_t ao_option_present;
    } tcpvars;
} Packet;

#define STREAMTCP_FLAG_TIMESTAMP (1 << 0)
#define STREAMTCP_FLAG_ASYNC (1 << 1)
#define STREAMTCP_STREAM_FLAG_RST_RECV (1 << 2)

#define OS_POLICY_HPUX11 1
#define OS_POLICY_OLD_LINUX 2
#define OS_POLICY_LINUX 3
#define OS_POLICY_SOLARIS 4
#define OS_POLICY_BSD 5
#define OS_POLICY_FIRST 6
#define OS_POLICY_HPUX10 7
#define OS_POLICY_IRIX 8
#define OS_POLICY_MACOS 9
#define OS_POLICY_LAST 10
#define OS_POLICY_WINDOWS 11
#define OS_POLICY_WINDOWS2K3 12
#define OS_POLICY_VISTA 13

#define PKT_IS_TOSERVER(p) (0)
#define TCP_GET_SEQ(p) (0)
#define TCP_GET_ACK(p) (0)
#define SEQ_GEQ(a, b) ((a) >= (b))
#define SEQ_LT(a, b) ((a) < (b))
#define SEQ_EQ(a, b) ((a) == (b))

#define SCReturnInt(x) return (x)
#define SCLogDebug(...)

int StreamTcpValidateTimestamp(TcpSession *ssn, Packet *p);
void StreamTcpSetOSPolicy(TcpStream *stream, Packet *p);
int StreamTcpValidateAck(TcpSession *ssn, TcpStream *stream, Packet *p);
void StreamTcpSetEvent(Packet *p, int event);