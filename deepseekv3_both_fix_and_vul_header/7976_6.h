#include <stddef.h>
#include <stdint.h>

#define NF_INET_NUMHOOKS 8
#define EINVAL 22

struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct xt_entry_target {
    unsigned int size;
};

struct ipt_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    unsigned int elems;
    struct xt_counters counters;
    unsigned int comefrom;
    struct {
        unsigned int version:4;
        unsigned int ihl:4;
        uint8_t tos;
        uint16_t tot_len;
        uint16_t id;
        uint16_t frag_off;
        uint8_t ttl;
        uint8_t protocol;
        uint16_t check;
        uint32_t saddr;
        uint32_t daddr;
    } ip;
};

struct xt_table_info {
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
};

static inline int ip_checkentry(const void *ip) { return 1; }
static inline int xt_check_entry_offsets(const void *e, ...) { return 0; }
static inline int check_underflow(const void *e) { return 1; }
static inline void duprintf(const char *fmt, ...) {}
static inline void pr_debug(const char *fmt, ...) {}