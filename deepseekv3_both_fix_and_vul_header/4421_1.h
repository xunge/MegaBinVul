#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define NF_ARP_NUMHOOKS 3
#define EINVAL 22

struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct xt_table_info {
    unsigned int hook_entry[NF_ARP_NUMHOOKS];
    unsigned int underflow[NF_ARP_NUMHOOKS];
};

struct arpt_entry {
    unsigned int next_offset;
    struct xt_counters counters;
    unsigned int comefrom;
};

struct xt_entry_target {
    unsigned int size;
};

extern void duprintf(const char *fmt, ...);
extern int check_entry(struct arpt_entry *e);
extern int check_underflow(struct arpt_entry *e);
extern int pr_err(const char *fmt, ...);