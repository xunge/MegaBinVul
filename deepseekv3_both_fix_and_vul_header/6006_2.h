#include <string.h>
#include <linux/netfilter_ipv4/ip_tables.h>
#include <linux/netfilter/x_tables.h>
#include <linux/module.h>
#include <linux/ip.h>

#define COMPAT_FROM_USER 0
#define EINVAL 22

struct xt_target {
    const char name[XT_EXTENSION_MAXNAMELEN];
    u_int8_t revision;
    unsigned int (*checkentry)(const char *, struct ipt_entry *, void *,
                              void *, unsigned int);
    void (*destroy)(void *, unsigned int);
    int (*compat)(struct xt_entry_target *t, void **dstptr,
                  unsigned int *size, int from_user);
    struct module *me;
};

struct xt_table_info {
    unsigned int size;
    unsigned int number;
    unsigned int initial_entries;
    unsigned int hook_entry[NF_IP_NUMHOOKS];
    unsigned int underflow[NF_IP_NUMHOOKS];
    void *entries[1];
};

struct compat_ipt_entry {
    struct ipt_ip ip;
    unsigned int nfcache;
    u_int16_t target_offset;
    u_int16_t next_offset;
    unsigned int comefrom;
};

static int compat_copy_match_from_user(struct xt_entry_match *m, void **dstptr,
                     unsigned int *size, const char *name,
                     struct ipt_ip *ip, unsigned int comefrom, int *j)
{
    return 0;
}

static int cleanup_match(struct xt_entry_match *m, int *j)
{
    return 0;
}

static int standard_check(struct xt_entry_target *t, unsigned int size)
{
    return 1;
}

static void duprintf(const char *fmt, ...) {}

extern struct xt_target ipt_standard_target;
extern int xt_compat_target(struct xt_entry_target *t, void **dstptr,
                           unsigned int *size, int from_user);
extern int xt_check_target(struct xt_target *target, unsigned int family,
                          unsigned int size, const char *name,
                          unsigned int hook_mask, u_int8_t proto, int inv_proto);