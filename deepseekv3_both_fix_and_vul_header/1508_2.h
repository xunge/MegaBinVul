#include <stdint.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <assert.h>
#include <endian.h>
#include <sys/uio.h>

typedef struct sd_event_source sd_event_source;
typedef struct DnsStream DnsStream;
typedef struct DnsPacket DnsPacket;

#define _cleanup_(x)
#define dns_stream_ref(x) (x)
#define dns_stream_unrefp
#define DNS_PACKET_HEADER_SIZE 12
#define DNS_PACKET_SIZE_MAX 65535
#define ENABLE_DNS_OVER_TLS 0
#define DNSTLS_STREAM_CLOSED 0
#define IOVEC_MAKE(a, b) (struct iovec){ .iov_base = (a), .iov_len = (b) }
#define IN_SET(x, ...) 0
#define DNS_PACKET_DATA(x) ((void*)0)
#define IOVEC_INCREMENT(iov, count, offset) \
    do { \
        for (int _i = 0; _i < (count); _i++) { \
            if ((offset) >= (iov)[_i].iov_len) { \
                (offset) -= (iov)[_i].iov_len; \
                (iov)[_i].iov_len = 0; \
            } else { \
                (iov)[_i].iov_base = (char*)(iov)[_i].iov_base + (offset); \
                (iov)[_i].iov_len -= (offset); \
                (offset) = 0; \
            } \
        } \
    } while (0)

union sockaddr_union {
    struct sockaddr sa;
    struct sockaddr_in in;
    struct sockaddr_in6 in6;
};

struct DnsPacket {
    size_t size;
    int ipproto;
    sa_family_t family;
    uint32_t ttl;
    unsigned ifindex;
    union {
        struct in_addr in;
        struct in6_addr in6;
    } sender;
    in_port_t sender_port;
    union {
        struct in_addr in;
        struct in6_addr in6;
    } destination;
    in_port_t destination_port;
};

struct DnsStream {
    int encrypted;
    union sockaddr_union peer;
    union sockaddr_union local;
    size_t tfo_salen;
    DnsPacket *write_packet;
    size_t n_written;
    DnsPacket *read_packet;
    size_t n_read;
    uint16_t read_size;
    uint16_t write_size;
    int protocol;
    uint32_t ttl;
    unsigned ifindex;
    int (*on_packet)(DnsStream *s);
};

static inline int dns_stream_identify(DnsStream *s) { return 0; }
static inline int dns_stream_complete(DnsStream *s, int error) { return 0; }
static inline ssize_t dns_stream_writev(DnsStream *s, struct iovec *iov, int iovcnt, int flags) { return 0; }
static inline int dns_stream_update_io(DnsStream *s) { return 0; }
static inline ssize_t dns_stream_read(DnsStream *s, void *buf, size_t count) { return 0; }
static inline int dns_packet_new(DnsPacket **p, int protocol, size_t min_size, size_t max_size) { return 0; }