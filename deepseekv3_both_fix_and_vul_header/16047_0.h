#include <stdint.h>

#define PICO_SIZE_TCPHDR 20
#define PICO_TCP_OPTION_NOOP 1
#define PICO_TCP_OPTION_END 0
#define PICO_TCP_OPTION_WS 3
#define PICO_TCP_OPTION_SACK_OK 4
#define PICO_TCP_OPTION_MSS 2
#define PICO_TCP_OPTION_TIMESTAMP 8
#define PICO_TCP_OPTION_SACK 5

struct pico_socket_tcp;
struct pico_frame {
    struct pico_socket_tcp *sock;
    uint8_t *buffer;
    uint32_t buffer_len;
    uint8_t *transport_hdr;
    uint32_t transport_len;
    uint8_t *payload;
    uint32_t timestamp;
};

extern void tcp_dbg_options(const char *fmt, ...);
extern void tcp_parse_option_ws(struct pico_socket_tcp *t, uint8_t len, uint8_t *opt, uint32_t *i);
extern void tcp_parse_option_sack_ok(struct pico_socket_tcp *t, struct pico_frame *f, uint8_t len, uint32_t *i);
extern void tcp_parse_option_mss(struct pico_socket_tcp *t, uint8_t len, uint8_t *opt, uint32_t *i);
extern void tcp_parse_option_timestamp(struct pico_socket_tcp *t, struct pico_frame *f, uint8_t len, uint8_t *opt, uint32_t *i);
extern void tcp_rcv_sack(struct pico_socket_tcp *t, uint8_t *opt, uint8_t len);