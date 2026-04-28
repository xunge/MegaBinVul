#include <stdint.h>
#include <string.h>

#define duprintf(fmt, args...) do {} while (0)
#define NF_INET_NUMHOOKS 4
#define NFPROTO_IPV6 10
#define AF_INET6 10
#define EINVAL 22

struct xt_entry_match {
    union {
        struct {
            uint16_t match_size;
            char name[32];
            uint8_t revision;
            struct {
                struct module *me;
            } *match;
        } kernel;
        struct {
            uint16_t match_size;
            char name[32];
            uint8_t revision;
        } user;
    } u;
};

struct xt_entry_target {
    union {
        struct {
            uint16_t target_size;
            char name[32];
            uint8_t revision;
            struct xt_target *target;
        } kernel;
        struct {
            uint16_t target_size;
            char name[32];
            uint8_t revision;
        } user;
    } u;
};

struct xt_target {
    struct module *me;
};

struct module {
    // Dummy definition
};

struct compat_ip6t_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    unsigned int comefrom;
    struct {
        uint64_t pcnt;
        uint64_t bcnt;
    } counters;
    struct {
        uint8_t src[16];
        uint8_t dst[16];
    } ipv6;
};

struct ip6t_entry {
    unsigned int next_offset;
    unsigned int target_offset;
    unsigned int comefrom;
    struct {
        uint64_t pcnt;
        uint64_t bcnt;
    } counters;
    struct {
        uint8_t src[16];
        uint8_t dst[16];
    } ipv6;
};

struct xt_table_info {
    unsigned int hook_entry[NF_INET_NUMHOOKS];
    unsigned int underflow[NF_INET_NUMHOOKS];
};

struct compat_xt_entry_target {
    uint16_t target_size;
    char name[32];
    uint8_t revision;
};

static inline int check_entry(struct ip6t_entry *e) { return 0; }
static inline int compat_find_calc_match(struct xt_entry_match *ematch, const char *name, void *ipv6, int *off) { return 0; }
static inline struct xt_entry_target *compat_ip6t_get_target(struct compat_ip6t_entry *e) { return NULL; }
static inline struct xt_target *xt_request_find_target(uint8_t family, const char *name, uint8_t revision) { return NULL; }
static inline int xt_compat_target_offset(struct xt_target *target) { return 0; }
static inline int xt_compat_add_offset(uint8_t family, unsigned int offset, int off) { return 0; }
static inline void module_put(struct module *module) {}

#define xt_ematch_foreach(ematch, e) \
    for ((ematch) = (struct xt_entry_match *)((char *)(e) + (e)->target_offset); \
         (char *)(ematch) + (ematch)->u.kernel.match_size <= (char *)(e) + (e)->next_offset && \
         (ematch)->u.kernel.match_size >= sizeof(struct xt_entry_match); \
         (ematch) = (struct xt_entry_match *)((char *)(ematch) + (ematch)->u.kernel.match_size))

#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)(-1000))
#define PTR_ERR(ptr) ((intptr_t)(ptr))