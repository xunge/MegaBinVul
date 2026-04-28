#include <stddef.h>
#include <errno.h>

struct net;
struct arpt_get_entries {
    char name[32];
    size_t size;
    void *entrytable;
};
struct xt_table {
    void *private;
    void *me;
};
struct xt_table_info {
    size_t size;
};

#define NFPROTO_ARP 0
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define EINVAL 22
#define EFAULT 14
#define EAGAIN 11

static int copy_from_user(void *dst, const void *src, size_t size) { return 0; }
static int copy_entries_to_user(size_t size, struct xt_table *t, void *entrytable) { return 0; }
static struct xt_table *xt_find_table_lock(struct net *net, int proto, const char *name) { return NULL; }
static void module_put(void *module) {}
static void xt_table_unlock(struct xt_table *t) {}

#define __user