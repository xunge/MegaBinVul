#include <string.h>
#include <errno.h>

#define XT_TABLE_MAXNAMELEN 32
#define NFPROTO_ARP 0
#define CONFIG_COMPAT
#define EINVAL 22
#define EFAULT 14

struct net;
struct module;

struct xt_table {
    struct xt_table_info *private;
    unsigned int valid_hooks;
    struct module *me;
};

struct xt_table_info {
    unsigned int hook_entry[5];
    unsigned int underflow[5];
    unsigned int number;
    unsigned int size;
};

struct arpt_getinfo {
    unsigned int valid_hooks;
    unsigned int hook_entry[5];
    unsigned int underflow[5];
    unsigned int num_entries;
    unsigned int size;
    char name[XT_TABLE_MAXNAMELEN];
};

#define __user

static inline void *ERR_PTR(long error) { return (void *)error; }
static inline long PTR_ERR(const void *ptr) { return (long)ptr; }
static inline long IS_ERR(const void *ptr) { return (unsigned long)ptr > (unsigned long)-1000L; }

static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int in_compat_syscall(void) { return 0; }
static inline void xt_compat_lock(int proto) {}
static inline void xt_compat_unlock(int proto) {}
static inline void xt_compat_flush_offsets(int proto) {}
static inline int compat_table_info(const struct xt_table_info *info, struct xt_table_info *tmp) { return 0; }
static inline struct xt_table *xt_request_find_table_lock(struct net *net, int proto, const char *name) { return NULL; }
static inline void xt_table_unlock(struct xt_table *table) {}
static inline void module_put(struct module *mod) {}