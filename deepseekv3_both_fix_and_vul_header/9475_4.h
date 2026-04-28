#include <stddef.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

struct qstr {
    const char *name;
    unsigned int len;
};

struct inode {
    unsigned long i_ino;
};

struct dentry {
    struct list_head d_subdirs;
    struct list_head d_child;
    union {
        struct list_head d_child;  // 统一使用d_child作为成员名
    } d_u;
    struct qstr d_name;
    struct inode *d_inode;
    int d_lock;
};

struct path {
    struct dentry *dentry;
};

struct file {
    struct path f_path;
    void *private_data;
};

struct dir_context {
    long pos;
};

#define DENTRY_D_LOCK_NESTED 1

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void spin_lock_nested(int *lock, int nested) {}
static inline void list_move(struct list_head *list, struct list_head *head) {}
#define list_entry(ptr, type, member) ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

int dir_emit_dots(struct file *, struct dir_context *);
int dir_emit(struct dir_context *, const char *, int, unsigned long, unsigned int);
bool simple_positive(struct dentry *);
unsigned int dt_type(struct inode *);