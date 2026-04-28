#include <string.h>
#include <stdbool.h>
#include <linux/netfilter/x_tables.h>
#include <linux/netfilter_ipv4/ip_tables.h>

#define NF_IP_TRACE_COMMENT_POLICY 0
#define NF_IP_TRACE_COMMENT_RETURN 1

struct xt_target {
    char name[32];
};

extern const char *comments[];
extern const char *hookname;

static inline const void *ipt_get_target_c(const struct ipt_entry *e)
{
    return (void *)e + e->target_offset;
}

static inline bool unconditional(const struct ipt_ip *ip)
{
    return true;
}