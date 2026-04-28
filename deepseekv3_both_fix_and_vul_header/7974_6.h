#include <stddef.h>
#include <stdint.h>

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

struct xt_entry_target {
    unsigned int size;
};

struct arpt_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    unsigned int elems;
    struct {
        int dummy;
    } arp;
    struct xt_counters counters;
    unsigned int comefrom;
};

#define duprintf(fmt, args...) 
#define pr_debug(fmt, args...) 

static inline int arp_checkentry(void *arp) { return 1; }
static inline int check_underflow(struct arpt_entry *e) { return 1; }
static inline int xt_check_entry_offsets(struct arpt_entry *e, ...) { return 0; }