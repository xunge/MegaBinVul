#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#define duprintf(fmt, args...) do {} while (0)
#define COMPAT_CALC_SIZE 0
#define NF_IP_NUMHOOKS 8
#define AF_INET 2
#define EINVAL 22
#define ENOENT 2
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))

typedef uint16_t u_int16_t;

struct ipt_ip {
    /* minimal definition to make it complete */
    uint32_t dummy;
};

struct compat_ipt_entry {
    uint32_t dummy;
};

struct compat_xt_entry_target {
    uint32_t dummy;
};

struct ipt_counters {
    uint64_t pcnt;
    uint64_t bcnt;
};

struct ipt_entry {
    struct ipt_ip ip;
    unsigned int comefrom;
    uint16_t target_offset;
    uint16_t next_offset;
    struct ipt_counters counters;
    char elems[0];
};

struct ipt_entry_target {
    union {
        struct {
            char name[32];
            uint8_t revision;
        } user;
        struct {
            struct ipt_target *target;
        } kernel;
    } u;
};

struct xt_table_info {
    unsigned int hook_entry[NF_IP_NUMHOOKS];
    unsigned int underflow[NF_IP_NUMHOOKS];
};

struct ipt_target {
    int (*compat)(struct ipt_entry_target *, void *, int *, int);
    struct module *me;
};

struct module;

static inline int ip_checkentry(const struct ipt_ip *ip) { return 1; }
static inline struct ipt_entry_target *ipt_get_target(struct ipt_entry *e) { return NULL; }
static inline struct ipt_target *xt_find_target(int af, const char *name, uint8_t revision) { return NULL; }
static inline struct ipt_target *try_then_request_module(struct ipt_target *t, const char *fmt, ...) { return t; }
static inline void xt_compat_target(struct ipt_entry_target *t, void *null, int *off, int calc) {}
static inline int compat_add_offset(unsigned int offset, int off) { return 0; }
static inline int IPT_MATCH_ITERATE(struct ipt_entry *e, int (*fn)(va_list), ...) { return 0; }
static inline int compat_check_calc_match(va_list args) { return 0; }
static inline int cleanup_match(va_list args) { return 0; }
static inline void module_put(struct module *mod) {}