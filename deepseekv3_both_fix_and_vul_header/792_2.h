#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PCAP_ERRBUF_SIZE 256
#define RPCAP_NETBUF_SIZE 1024
#define LOGPRIO_ERROR 0
#define PCAP_ERR_NOREMOTEIF 0
#define PCAP_ERR_FINDALLIF 0
#define RPCAP_MSG_FINDALLIF_REPLY 0

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

typedef struct pcap_if_t {
    struct pcap_if_t *next;
    char *name;
    char *description;
    struct pcap_addr *addresses;
    uint32_t flags;
} pcap_if_t;

typedef struct pcap_addr {
    struct pcap_addr *next;
    struct sockaddr *addr;
    struct sockaddr *netmask;
    struct sockaddr *broadaddr;
    struct sockaddr *dstaddr;
} pcap_addr;

struct daemon_slpars {
    int sockctrl;
};

struct rpcap_header {
    uint8_t ver;
    uint8_t type;
    uint16_t value;
    uint32_t plen;
};

struct rpcap_findalldevs_if {
    uint16_t namelen;
    uint16_t desclen;
    uint16_t naddr;
    uint32_t flags;
};

struct rpcap_sockaddr {
    uint16_t family;
    uint16_t port;
    uint32_t addr[4];
};

enum {
    SOCKBUF_CHECKONLY,
    SOCKBUF_BUFFERIZE
};

int rpcapd_discard(int sockctrl, uint32_t plen);
int rpcap_senderror(int sockctrl, uint8_t ver, int errcode, const char *errmsg, char *errbuf);
void rpcapd_log(int priority, const char *format, ...);
int sock_bufferize(const void *data, size_t len, char *sendbuf, int *sendbufidx, size_t bufsize, int mode, char *errmsgbuf, size_t errmsgbufsize);
void rpcap_createhdr(struct rpcap_header *header, uint8_t ver, uint8_t type, uint16_t value, uint32_t plen);
int sock_send(int sockctrl, const char *sendbuf, int sendbufidx, char *errbuf, size_t errbufsize);
void daemon_seraddr(struct sockaddr_storage *addr, struct rpcap_sockaddr *sockaddr);
int pcap_findalldevs(pcap_if_t **alldevs, char *errbuf);
void pcap_freealldevs(pcap_if_t *alldevs);