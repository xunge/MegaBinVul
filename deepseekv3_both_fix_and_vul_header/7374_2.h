#include <stdbool.h>
#include <stddef.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct dentry;

struct mount {
    struct list_head mnt_mounts;
    struct dentry *mnt_mountpoint;
    struct {
        unsigned int mnt_flags;
    } mnt;
    struct list_head mnt_child;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))(head)->next; pos != (typeof(pos))(head); pos = (typeof(pos))pos->member.next)

#define MNT_LOCKED 0x00000001

static inline bool is_subdir(struct dentry *dentry, struct dentry *parent)
{
    return false;
}