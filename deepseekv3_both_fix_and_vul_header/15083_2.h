#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define KERN_DEBUG 7

typedef unsigned long mm_segment_t;

struct dentry {
    struct inode *d_inode;
    struct {
        char *name;
    } d_name;
};

struct inode {
    struct inode_operations *i_op;
};

struct inode_operations {
    int (*readlink)(struct dentry *, char *, int);
};

struct nameidata {
    char **saved_names;
    int depth;
};

#define get_ds() ((mm_segment_t)0)
#define set_fs(x) ((void)(x))
#define get_fs() ((mm_segment_t)0)

#define nd_set_link(nd, link) ((nd)->saved_names[(nd)->depth] = (link))

#define ERR_PTR(err) ((void *)(long)(err))

static inline void ecryptfs_printk(int level, const char *fmt, ...) { }

void *kmalloc(size_t size, int flags) { return malloc(size); }
void kfree(void *ptr) { free(ptr); }

#define __user