#include <stddef.h>
#include <stdint.h>

#define NF_INET_NUMHOOKS 4
#define EINVAL 22

struct xt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct xt_entry_target {
    unsigned int size;
};

struct ipt_entry {
    unsigned int next_offset;
    struct xt_counters counters;
    unsigned int comefrom;
};

struct xt_table_info {
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
};

#define duprintf(fmt, ...) 
#define pr_err(fmt, ...) 

static int check_entry(struct ipt_entry *e);
static int check_underflow(struct ipt_entry *e);