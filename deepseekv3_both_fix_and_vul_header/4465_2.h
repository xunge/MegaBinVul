#include <stdbool.h>
#include <stdio.h>

struct dentry {
    struct inode *d_inode;
    struct {
        const char *name;
    } d_name;
};

struct inode {
    int i_mutex;
};

struct list_head {
    struct list_head *next, *prev;
};

struct ovl_cache_entry {
    bool is_whiteout;
    const char *name;
    unsigned int len;
    struct list_head l_node;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))(head)->next; pos != (typeof(pos))(head); pos = (typeof(pos))pos->member.next)

#define I_MUTEX_CHILD 0
#define IS_ERR(x) (x == NULL)
#define PTR_ERR(x) (-1)

void mutex_lock_nested(int *mutex, int subclass);
void mutex_unlock(int *mutex);
struct dentry *lookup_one_len(const char *name, struct dentry *parent, unsigned len);
void ovl_cleanup(struct inode *dir, struct dentry *dentry);
void dput(struct dentry *dentry);
int pr_err(const char *fmt, ...);