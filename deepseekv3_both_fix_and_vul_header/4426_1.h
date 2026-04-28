#include <stddef.h>
#include <string.h>

#define NF_INET_NUMHOOKS 8
#define NF_MAX_VERDICT 0xFFFF
#define XT_STANDARD_TARGET "standard"
#define DEBUG_IP_FIREWALL_USER

struct xt_table_info {
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int size;
};

struct xt_target {
    union {
        struct {
            char name[32];
        } user;
    } u;
};

struct xt_standard_target {
    struct xt_target target;
    int verdict;
};

struct ipt_ip {
    int dummy;
};

struct ipt_entry {
    struct {
        unsigned int pcnt;
    } counters;
    unsigned int comefrom;
    unsigned int target_offset;
    unsigned int next_offset;
    struct ipt_ip ip;
};

static inline void *ipt_get_target_c(const struct ipt_entry *e) {
    return (void *)e + e->target_offset;
}

static inline int unconditional(const struct ipt_ip *ip) {
    return 1;
}

static inline void duprintf(const char *fmt, ...) {}
static inline void pr_err(const char *fmt, ...) {}