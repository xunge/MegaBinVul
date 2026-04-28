#include <stdint.h>
#include <stddef.h>

#define PICO_TCP_SUPPORT_SOCKET_STATS
#define PICO_SUPPORT_IPV4
#define PICO_SUPPORT_IPV6
#define PICO_SIZE_TCPHDR 20
#define PICO_TCP_MIN_MSS 536
#define PICO_DEFAULT_SOCKETQ 8192
#define PICO_TCP_IW 4380
#define PICO_SOCKET_LINGER_TIMEOUT 10000
#define PICO_TCP_RTO_MIN 200

#define PICO_SOCKET_STATE_BOUND     (1 << 0)
#define PICO_SOCKET_STATE_CONNECTED (1 << 1)
#define PICO_SOCKET_STATE_TCP_SYN_RECV (1 << 2)

struct pico_ip4 {
    uint32_t addr;
};

struct pico_ip6 {
    uint8_t addr[16];
};

struct pico_ipv4_hdr {
    struct pico_ip4 src;
    struct pico_ip4 dst;
};

struct pico_ipv6_hdr {
    struct pico_ip6 src;
    struct pico_ip6 dst;
};

struct pico_trans {
    uint16_t sport;
};

struct pico_tcp_hdr {
    uint32_t seq;
    uint16_t rwnd;
};

struct pico_socket {
    uint16_t number_of_pending_conn;
    uint16_t max_backlog;
    void *stack;
    void *wakeup;
    struct pico_socket *parent;
    uint16_t remote_port;
    union {
        struct pico_ip4 ip4;
        struct pico_ip6 ip6;
    } remote_addr;
    union {
        struct pico_ip4 ip4;
        struct pico_ip6 ip6;
    } local_addr;
    uint32_t state;
};

struct pico_socket_tcp {
    struct pico_socket sock;
    uint16_t mss;
    uint32_t rcv_nxt;
    uint32_t snd_nxt;
    uint32_t snd_last;
    uint16_t cwnd;
    uint16_t ssthresh;
    uint16_t recv_wnd;
    uint32_t linger_timeout;
    struct {
        uint16_t max_size;
    } tcpq_in, tcpq_out, tcpq_hold;
};

struct pico_frame {
    void *transport_hdr;
    void *net_hdr;
    struct pico_socket *sock;
};

uint32_t pico_paws(void);
int tcp_parse_options(struct pico_frame *f);
void tcp_send_synack(struct pico_socket *s);
void pico_socket_add(struct pico_socket *s);
void rto_set(struct pico_socket_tcp *t, uint32_t timeout);
uint32_t long_be(uint32_t x);
uint16_t short_be(uint16_t x);
struct pico_socket *pico_socket_clone(struct pico_socket *s);
uint16_t pico_socket_get_mss(struct pico_socket *s);
int pico_timer_add(void *stack, uint32_t timeout, void (*callback)(void *), void *arg);
void tcp_dbg(const char *fmt, ...);
int IS_IPV4(struct pico_frame *f);
int IS_IPV6(struct pico_frame *f);
void sock_stats(void *arg);

#ifdef PICO_TCP_SUPPORT_SOCKET_STATS
static struct pico_socket_tcp *t;
#endif