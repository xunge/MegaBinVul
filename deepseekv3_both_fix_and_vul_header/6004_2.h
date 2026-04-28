#include <linux/ip.h>
#include <linux/module.h>
#include <linux/netfilter/x_tables.h>
#include <linux/netfilter_ipv4/ip_tables.h>

#define COMPAT_FROM_USER 0
#define EINVAL 22

typedef unsigned int compat_uint_t;

struct xt_match {
    int (*compat)(struct xt_entry_match *m, void **dstptr,
                 compat_uint_t *size, int from_user);
    int (*checkentry)(const char *name, const struct ipt_ip *ip,
                     struct xt_match *match, void *data,
                     unsigned int hookmask);
    char name[XT_EXTENSION_MAXNAMELEN];
    struct module *me;
};

static inline int xt_check_match(struct xt_match *match, int family, int size,
                               const char *name, unsigned int hookmask,
                               u_int8_t proto, u_int8_t invflags);

static inline void xt_compat_match(struct xt_entry_match *m, void **dstptr,
                                 compat_uint_t *size, int from_user);

static inline void module_put(struct module *module);

#define duprintf(fmt, ...)