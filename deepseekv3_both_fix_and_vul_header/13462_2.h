#include <stddef.h>
#include <errno.h>

#define __user

struct net;
struct ip6t_get_entries {
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

#define AF_INET6 10
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define EINVAL 22
#define EFAULT 14
#define EAGAIN 11

static void module_put(void *module) {}
static void xt_table_unlock(struct xt_table *t) {}
static struct xt_table *xt_find_table_lock(struct net *net, int family, const char *name) { return NULL; }
static int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static int copy_entries_to_user(size_t size, struct xt_table *t, void *entrytable) { return 0; }