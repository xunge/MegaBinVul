#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define duprintf(fmt, args...) do {} while (0)
#define NFPROTO_ARP 3
#define PTR_ERR(x) ((long)(x))
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000L))
#define EINVAL 22
#define NF_ARP_NUMHOOKS 3

typedef uint8_t u8;

struct compat_arpt_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    void *arp;
    void *elems;
    void *counters;
    unsigned int comefrom;
};

struct compat_xt_entry_target {
    unsigned int size;
};

struct arpt_entry {
    unsigned int dummy[24];
};

struct xt_table_info {
    unsigned int hook_entry[NF_ARP_NUMHOOKS];
    unsigned int underflow[NF_ARP_NUMHOOKS];
};

struct xt_target {
    struct module *me;
};

struct xt_entry_target {
    union {
        struct {
            char name[32];
            u8 revision;
        } user;
        struct {
            struct xt_target *target;
        } kernel;
    } u;
};

struct module;

static inline int arp_checkentry(void *arp) { return 1; }
static inline int xt_compat_check_entry_offsets_4args(void *e, void *elems, unsigned int target_offset, unsigned int next_offset) { return 0; }
static inline int xt_compat_check_entry_offsets_3args(void *e, unsigned int target_offset, unsigned int next_offset) { return 0; }
static inline struct xt_entry_target *compat_arpt_get_target(struct compat_arpt_entry *e) { return NULL; }
static inline struct xt_target *xt_request_find_target(int family, const char *name, u8 revision) { return NULL; }
static inline int xt_compat_target_offset(struct xt_target *target) { return 0; }
static inline int xt_compat_add_offset(int family, unsigned int offset, int delta) { return 0; }
static inline void module_put(struct module *mod) {}