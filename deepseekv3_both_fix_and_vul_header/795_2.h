#include <stdint.h>
#include <string.h>
#include <netinet/in.h>

#define PCAP_ERRBUF_SIZE 256
#define RPCAP_NETBUF_SIZE 1024
#define LOGPRIO_ERROR 3

typedef uint8_t uint8;
typedef uint32_t uint32;

struct daemon_slpars {
    int sockctrl;
};

struct rpcap_header {
    uint8_t ver;
    uint8_t type;
    uint16_t value;
    uint32_t plen;
};

struct rpcap_openreply {
    uint32_t linktype;
    int32_t tzoff;
};

typedef struct pcap_t pcap_t;

#define RPCAP_MSG_OPEN_REPLY 2
#define PCAP_ERR_OPEN 1

#define SOCK_RECEIVEALL_YES 1
#define SOCK_EOF_IS_ERROR 2
#define SOCKBUF_CHECKONLY 1

int sock_recv(int sock, char *buf, size_t len, int flags, char *errbuf, size_t errbuflen);
int sock_bufferize(const void *data, size_t len, void *buf, int *bufidx, size_t bufsize, int flag, char *errmsgbuf, size_t errmsgbufsize);
int sock_send(int sock, const void *buf, size_t len, char *errbuf, size_t errbuflen);
int rpcap_senderror(int sockctrl, uint8_t ver, uint16_t error, const char *errormsg, char *errbuf);
int rpcapd_discard(int sockctrl, uint32_t plen);
void rpcapd_log(int priority, const char *format, ...);
void rpcap_createhdr(struct rpcap_header *header, uint8_t ver, uint8_t type, uint16_t value, uint32_t plen);
int pcap_snprintf(char *str, size_t sz, const char *format, ...);
pcap_t *pcap_open_live(const char *device, int snaplen, int promisc, int to_ms, char *errbuf);
int pcap_datalink(pcap_t *p);
void pcap_close(pcap_t *p);