#include <stddef.h>
#include <string.h>

#define duprintf(fmt, args...) do {} while (0)
#define NF_ARP_NUMHOOKS 3
#define NFPROTO_ARP 1
#define EINVAL 22
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))

struct compat_arpt_entry {
    unsigned int next_offset;
    void *counters;
    unsigned int comefrom;
};

struct compat_xt_entry_target {
    unsigned int size;
};

struct arpt_entry {
    unsigned int next_offset;
};

struct xt_table_info {
    unsigned int hook_entry[NF_ARP_NUMHOOKS];
    unsigned int underflow[NF_ARP_NUMHOOKS];
};

struct xt_entry_target {
    union {
        struct {
            char name[32];
            unsigned char revision;
        } user;
        struct {
            struct xt_target *target;
        } kernel;
    } u;
};

struct xt_target {
    struct module *me;
};

struct module;

static inline struct xt_entry_target *compat_arpt_get_target(struct compat_arpt_entry *e) { return NULL; }
static inline int check_entry(struct arpt_entry *e) { return 0; }
static inline int xt_compat_add_offset(unsigned char pf, unsigned int offset, int delta) { return 0; }
static inline unsigned int xt_compat_target_offset(struct xt_target *target) { return 0; }
static inline void module_put(struct module *mod) {}
struct xt_target *xt_request_find_target(unsigned char family, const char *name, unsigned char revision) { return NULL; }