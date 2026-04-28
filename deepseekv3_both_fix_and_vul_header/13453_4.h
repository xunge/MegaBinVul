#include <stddef.h>
#include <errno.h>

#define AF_INET 2

struct net;
struct module;

struct xt_table_info {
    unsigned int size;
    void *private;
};

struct xt_table {
    struct xt_table_info *private;
    struct module *me;
};

struct ipt_get_entries {
    char name[32];
    unsigned int size;
    void *entrytable;
};

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    return 0;
}

static inline int copy_entries_to_user(unsigned int size, struct xt_table *t, void *entrytable) {
    return 0;
}

static inline struct xt_table *xt_find_table_lock(struct net *net, int af, const char *name) {
    return NULL;
}

static inline void xt_table_unlock(struct xt_table *t) {}