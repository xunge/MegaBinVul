#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <linux/netfilter_ipv6/ip6_tables.h>
#include <linux/netfilter/x_tables.h>

#define NF_IP6_TRACE_COMMENT_POLICY 0
#define NF_IP6_TRACE_COMMENT_RETURN 1

struct xt_target {
    const char *name;
};

union xt_target_union {
    struct {
        struct xt_target *target;
    } kernel;
};

struct xt_target_entry {
    union xt_target_union u;
    const char *data;
};

static const char *comments[] = {
    [NF_IP6_TRACE_COMMENT_POLICY] = "policy",
    [NF_IP6_TRACE_COMMENT_RETURN] = "return"
};

static inline bool unconditional(const struct ip6t_ip6 *ipv6)
{
    return false;
}

static inline const void *ip6t_get_target_c(const struct ip6t_entry *e)
{
    return (void *)e + e->target_offset;
}

#define XT_ERROR_TARGET "ERROR"
#define XT_STANDARD_TARGET "standard"