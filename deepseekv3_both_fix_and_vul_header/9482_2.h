#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct qstr {
    unsigned int len;
    const char *name;
};

struct dentry {
    struct qstr d_name;
    struct dentry *d_parent;
    void *d_inode;
    unsigned int d_count;
    unsigned int d_flags;
    void *d_fsdata;
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
};

#define LASSERT(cond) ((void)0)
#define CERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define d_count(d) ((d)->d_count)

static inline void ll_dump_inode(void *inode) {}

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))