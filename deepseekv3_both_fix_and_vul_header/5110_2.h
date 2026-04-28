#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>

#define SOCK_DNS_QUERYBUF_LEN 512
#define SOCK_DNS_MAX_NAME_LEN 256
#define SOCK_DNS_RETRIES 3
#define DNS_MIN_REPLY_LEN 12

#define DNS_TYPE_A 1
#define DNS_TYPE_AAAA 28
#define DNS_CLASS_IN 1

typedef struct {
    uint16_t id;
    uint16_t flags;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
} sock_dns_hdr_t;

struct sockaddr_in sock_dns_server = {
    .sin_family = AF_INET,
    .sin_port = 0,
    .sin_addr = {0}
};

typedef struct {
    int fd;
} sock_udp_t;

static unsigned _enc_domain_name(uint8_t *bufpos, const char *domain_name) { return 0; }
static unsigned _put_short(uint8_t *bufpos, uint16_t val) { return 0; }
static int _parse_dns_reply(uint8_t *reply_buf, ssize_t res, void *addr_out, int family) { return 0; }

int sock_udp_create(sock_udp_t *sock, struct sockaddr_in *local, struct sockaddr_in *remote, int flags) { return 0; }
ssize_t sock_udp_send(sock_udp_t *sock, const void *data, size_t len, int flags) { return 0; }
ssize_t sock_udp_recv(sock_udp_t *sock, void *buf, size_t max_len, uint32_t timeout, int flags) { return 0; }
void sock_udp_close(sock_udp_t *sock) {}

// Fix for port access
#define port sin_port