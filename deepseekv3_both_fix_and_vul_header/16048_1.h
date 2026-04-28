#include <stdint.h>

#define PICO_TCPOPTLEN_MSS 4

struct pico_socket_tcp {
    uint16_t mss;
    uint8_t mss_ok;
};

static inline int tcpopt_len_check(uint32_t *idx, uint8_t len, uint8_t required_len) {
    if (len < required_len)
        return -1;
    return 0;
}

static inline uint16_t short_from(uint8_t *ptr) {
    return (uint16_t)((ptr[0] << 8) | ptr[1]);
}

static inline uint16_t short_be(uint16_t val) {
    return (uint16_t)((val >> 8) | (val << 8));
}