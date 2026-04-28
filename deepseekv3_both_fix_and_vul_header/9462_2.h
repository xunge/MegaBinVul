#include <stddef.h>
#include <sys/stat.h>

struct list_head {
    struct list_head *next, *prev;
};

struct inode {
    unsigned int i_mode;
};

struct dentry {
    struct list_head d_subdirs;
    struct list_head d_child;
    struct {
        struct list_head d_child;
    } d_u;
    struct inode *d_inode;
};

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

extern struct dentry *class_dir;
void sel_remove_entries(struct dentry *d);