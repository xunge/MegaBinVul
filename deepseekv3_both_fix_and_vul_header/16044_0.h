#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

struct pico_socket {
    struct {
        struct {
            struct {
                void *out;
            } q_tcp;
        } *stack;
        struct {
            struct pico_frame *(*alloc)(void *, void *, void *, uint16_t);
        } *net;
    };
};

struct pico_socket_tcp {
    uint32_t snd_nxt;
    uint32_t snd_last;
    uint16_t cwnd;
    uint16_t mss;
    uint16_t ssthresh;
    uint16_t wnd;
    uint8_t backoff;
    struct {
        uint16_t local_port;
        uint16_t remote_port;
    } sock;
    void *retrans_tmr;
};

struct pico_frame {
    void *transport_hdr;
    struct pico_socket *sock;
    uint16_t buffer_len;
};

struct pico_tcp_hdr {
    uint32_t seq;
    uint8_t len;
    uint8_t flags;
    uint16_t rwnd;
    struct {
        uint16_t sport;
        uint16_t dport;
    } trans;
    uint16_t crc;
};

#define TCP_SOCK(s) ((struct pico_socket_tcp *)(s))
#define PICO_SIZE_TCPHDR 20
#define PICO_TCP_SYN 0x02
#define PICO_TCP_IW 1
#define PICO_DEFAULT_SOCKETQ 8192
#define PICO_TCP_SYN_TO 3000
#define PICO_TCP_MIN_MSS 536
#define PICO_FREE(ptr) free(ptr)

uint32_t long_be(uint32_t val);
uint16_t short_be(uint16_t val);
uint32_t pico_paws(void);
uint16_t pico_tcp_checksum(struct pico_frame *f);
uint16_t tcp_options_size(struct pico_socket_tcp *ts, uint8_t flags);
void tcp_set_space(struct pico_socket_tcp *ts);
void tcp_add_options(struct pico_socket_tcp *ts, struct pico_frame *f, uint8_t flags, uint16_t opt_len);
void tcp_dbg(const char *fmt, ...);
void *pico_timer_add(void *stack, uint32_t timeout, void (*timer)(void *), void *arg);
void pico_enqueue(void *queue, struct pico_frame *f);
uint16_t pico_socket_get_mss(struct pico_socket *s);
void initconn_retry(void *arg);