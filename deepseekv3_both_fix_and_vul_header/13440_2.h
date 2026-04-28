#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

#define GFP_KERNEL 0
#define NPROTO 32
#define ENOMEM 12
#define EEXIST 17

struct mutex {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct xt_table_info {
    unsigned int number;
    unsigned int initial_entries;
};

struct xt_table {
    int af;
    char *name;
    struct xt_table_info *private;
    struct list_head list;
};

struct xt_af {
    struct mutex mutex;
};

struct xt_pernet {
    struct list_head tables[NPROTO];
};

struct net {
    struct xt_pernet xt;
};

extern struct xt_af xt[NPROTO];

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (typeof(*pos)*)(head); pos = NULL)

#define mutex_lock(m) ((void)0)
#define mutex_unlock(m) ((void)0)
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

void *kmemdup(const void *src, size_t len, int gfp);
void kfree(const void *obj);
int xt_replace_table(struct xt_table *table, int zero, struct xt_table_info *newinfo, int *ret);
void *ERR_PTR(int error);