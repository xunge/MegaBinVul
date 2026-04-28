#include <stddef.h>
#include <stdint.h>
#include <linux/netfilter_ipv4/ip_tables.h>
#include <linux/netfilter/x_tables.h>

#define COMPAT_CALC_SIZE 0

struct xt_table_info {
    unsigned int size;
    unsigned int hook_entry[NF_IP_NUMHOOKS]; 
    unsigned int underflow[NF_IP_NUMHOOKS];
};

struct xt_target {
    int (*compat)(void *, void *, int *, int);
};

static int compat_calc_match(const struct ipt_entry_match *m, void *data);
static int compat_add_offset(uint16_t offset, int delta);
static int xt_compat_target(struct ipt_entry_target *t, void *null, int *off, int size);