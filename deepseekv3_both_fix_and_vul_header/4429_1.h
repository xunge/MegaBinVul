#include <stdbool.h>
#include <string.h>

struct ip6t_entry {
    int ipv6;
};

struct xt_entry_target {
    union {
        struct {
            char name[32];
        } user;
    } u;
};

struct xt_standard_target {
    unsigned int verdict;
};

#define XT_STANDARD_TARGET ""
#define NF_DROP 0
#define NF_ACCEPT 1

static bool unconditional(const void *);
static struct xt_entry_target *ip6t_get_target_c(const struct ip6t_entry *);