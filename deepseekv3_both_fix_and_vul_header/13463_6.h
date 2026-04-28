#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#define XT_TABLE_MAXNAMELEN 32
#define AF_INET6 10
#define EINVAL 22
#define EFAULT 14

struct net;
struct module;

struct xt_table_info {
    unsigned int size;
    unsigned int number;
    unsigned int valid_hooks;
    unsigned int hook_entry[5];
    unsigned int underflow[5];
};

struct xt_table {
    struct xt_table_info *private;
    unsigned int valid_hooks;
    struct module *me;
};

struct ip6t_getinfo {
    char name[XT_TABLE_MAXNAMELEN];
    unsigned int valid_hooks;
    unsigned int hook_entry[5];
    unsigned int underflow[5];
    unsigned int num_entries;
    unsigned int size;
};

typedef void* user_ptr_t;
#define __user

static inline int copy_from_user(void *to, const user_ptr_t from, unsigned long n) { return 0; }
static inline int copy_to_user(user_ptr_t to, const void *from, unsigned long n) { return 0; }

#ifdef CONFIG_COMPAT
static inline bool in_compat_syscall(void) { return false; }
static void xt_compat_lock(int family) {}
static void xt_compat_unlock(int family) {}
static void xt_compat_flush_offsets(int family) {}
static int compat_table_info(const struct xt_table_info *info, struct xt_table_info *tmp) { return 0; }
#endif

static struct xt_table *xt_request_find_table_lock(struct net *net, int family, const char *name) { return NULL; }
static void xt_table_unlock(struct xt_table *table) {}
static bool IS_ERR(const void *ptr) { return false; }
static long PTR_ERR(const void *ptr) { return 0; }
static void module_put(struct module *mod) {}