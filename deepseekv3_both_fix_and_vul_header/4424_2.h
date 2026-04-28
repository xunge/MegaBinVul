#include <stdbool.h>
#include <string.h>

struct ipt_ip {
    // minimal definition needed for compilation
    unsigned char dummy;
};

struct ipt_entry {
    struct ipt_ip ip;
};

struct xt_entry_target {
    union {
        struct {
            char name[32];
        } user;
    } u;
};

struct xt_standard_target {
    unsigned int verdict;
};

#define XT_STANDARD_TARGET "standard"
#define NF_DROP 0
#define NF_ACCEPT 1

static inline bool unconditional(const struct ipt_ip *ip) { return true; }
static inline struct xt_entry_target *ipt_get_target_c(const struct ipt_entry *e) { return (struct xt_entry_target *)0; }