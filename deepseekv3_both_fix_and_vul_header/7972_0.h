#include <string.h>
#include <linux/netfilter/x_tables.h>

#define XT_STANDARD_TARGET ""
#define EINVAL 22

struct compat_xt_entry_target {
    union {
        struct {
            unsigned short target_size;
            char name[32];
            unsigned char revision;
        } user;
        struct {
            unsigned short target_size;
        } kernel;
        unsigned short target_size;
    } u;
};

struct compat_xt_standard_target {
    struct compat_xt_entry_target target;
    int verdict;
};