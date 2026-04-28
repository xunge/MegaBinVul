#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <linux/netfilter/x_tables.h>
#include <linux/netfilter_ipv4/ip_tables.h>
#include <linux/netfilter.h>
#include <linux/module.h>

#define duprintf(fmt, args...) do {} while (0)
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define NFPROTO_IPV4 AF_INET
#define NF_INET_NUMHOOKS 5

struct xt_table_info {
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
};

struct compat_ipt_entry {
    struct ipt_ip ip;
    unsigned int target_offset;
    unsigned int next_offset;
    unsigned int comefrom;
    struct xt_counters counters;
    unsigned char elems[0];
};

struct compat_xt_entry_target {
    uint32_t target_size;
    char name[32];
    uint8_t revision;
    union {
        struct {
            char name[32];
            uint8_t revision;
        } user;
        struct xt_target *target;
    } u;
};

struct xt_target {
    struct module *me;
};

struct xt_match {
    struct module *me;
};

extern int check_entry(struct ipt_entry *e);
extern int compat_find_calc_match(struct xt_entry_match *ematch, const char *name, struct ipt_ip *ip, int *off);
extern struct xt_target *xt_request_find_target(unsigned int family, const char *name, uint8_t revision);
extern int xt_compat_target_offset(struct xt_target *target);
extern int xt_compat_add_offset(unsigned int family, unsigned int offset, int delta);

static inline struct xt_entry_target *compat_ipt_get_target(struct compat_ipt_entry *e)
{
    return (void *)e + e->target_offset;
}