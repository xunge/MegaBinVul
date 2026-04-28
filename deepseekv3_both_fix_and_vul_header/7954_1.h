#include <stdint.h>
#include <netinet/in.h>

typedef uint32_t __be32;

struct rds_incoming {
    struct {
        uint64_t h_sequence;
        uint32_t h_len;
        uint16_t h_sport;
        uint16_t h_dport;
    } i_hdr;
};

struct rds_info_iterator;
struct rds_info_message {
    uint64_t seq;
    uint32_t len;
    __be32 laddr;
    __be32 faddr;
    uint16_t lport;
    uint16_t fport;
    uint32_t flags;
};

void rds_info_copy(struct rds_info_iterator *iter, void *data, size_t len);