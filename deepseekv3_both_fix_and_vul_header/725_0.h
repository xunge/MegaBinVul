#include <stdint.h>
#include <netinet/in.h>

struct rds_incoming {
    struct {
        uint64_t h_sequence;
        uint32_t h_len;
        uint16_t h_sport;
        uint16_t h_dport;
    } i_hdr;
    struct {
        uint8_t c_tos;
    } *i_conn;
};

struct rds6_info_message {
    uint64_t seq;
    uint32_t len;
    uint8_t tos;
    struct in6_addr laddr;
    struct in6_addr faddr;
    uint16_t lport;
    uint16_t fport;
    uint32_t flags;
};

struct rds_info_iterator;

void rds_info_copy(struct rds_info_iterator *iter, void *data, size_t len);

uint64_t be64_to_cpu(uint64_t x);
uint32_t be32_to_cpu(uint32_t x);