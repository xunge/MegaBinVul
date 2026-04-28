#include <stdbool.h>
#include <string.h>

struct arp {
    int dummy;
};

struct arpt_entry {
    struct arp arp;
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

static bool unconditional(const struct arp *arp) {
    return false;
}

static struct xt_entry_target* arpt_get_target_c(const struct arpt_entry* e) {
    return NULL;
}

#define XT_STANDARD_TARGET "standard"
#define NF_DROP 0
#define NF_ACCEPT 1