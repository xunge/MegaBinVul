#include <stddef.h>
#include <string.h>

#define NF_INET_NUMHOOKS 8
#define NF_MAX_VERDICT 0xFFFF
#define XT_STANDARD_TARGET ""

struct xt_table_info {
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int size;
};

struct xt_target {
    struct {
        char name[sizeof(XT_STANDARD_TARGET)];
    } user;
};

struct xt_standard_target {
    struct {
        struct xt_target u;
    } target;
    int verdict;
};

struct ip6t_ipv6 {
    int dummy;
};

struct ip6t_entry {
    struct {
        unsigned int pcnt;
    } counters;
    unsigned int comefrom;
    unsigned int target_offset;
    unsigned int next_offset;
    struct ip6t_ipv6 ipv6;
};

static inline void *ip6t_get_target_c(const struct ip6t_entry *e) {
    return (void *)e + e->target_offset;
}

static inline int unconditional(const struct ip6t_entry *e) {
    return 0;
}

static void duprintf(const char *fmt, ...) {}
static void pr_err(const char *fmt, ...) {}