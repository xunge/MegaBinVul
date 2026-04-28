#include <string.h>
#include <errno.h>
#include <stddef.h>

#define XT_TABLE_MAXNAMELEN 32
#define AF_INET 2

struct net;
struct xt_table {
    void *private;
    unsigned int valid_hooks;
    struct module *me;
};
struct xt_table_info {
    unsigned int hook_entry[5];
    unsigned int underflow[5];
    unsigned int number;
    unsigned int size;
};
struct ipt_getinfo {
    unsigned int valid_hooks;
    unsigned int hook_entry[5];
    unsigned int underflow[5];
    unsigned int num_entries;
    unsigned int size;
    char name[XT_TABLE_MAXNAMELEN];
};
struct module;

#ifdef CONFIG_COMPAT
static inline bool in_compat_syscall(void) { return false; }
static void xt_compat_lock(int af) {}
static void xt_compat_unlock(int af) {}
static void xt_compat_flush_offsets(int af) {}
static int compat_table_info(const struct xt_table_info *info, struct xt_table_info *tmp) { return 0; }
#endif

static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }

static struct xt_table *xt_request_find_table_lock(struct net *net, int af, const char *name) { return NULL; }
static void xt_table_unlock(struct xt_table *t) {}
static void module_put(struct module *mod) {}

#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000L)
#define PTR_ERR(ptr) ((long)(ptr))

/* 修改函数签名 */
static int get_info(struct net *net, void *user, const int *len);

/* 定义EINVAL和EFAULT错误码 */
#ifndef EINVAL
#define EINVAL 22
#endif
#ifndef EFAULT
#define EFAULT 14
#endif

/* 定义__user宏为空 */
#define __user