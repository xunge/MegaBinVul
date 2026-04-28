#include <stddef.h>
#include <errno.h>
#include <sys/types.h>

#define ATTR_SIZE 1
#define ATTR_FILE 2
#define EINVAL 22

typedef off_t loff_t;

struct dentry {
    struct inode *d_inode;
};

struct inode {
    void *i_mutex;
};

struct file;

struct iattr {
    loff_t ia_size;
    unsigned int ia_valid;
    struct file *ia_file;
};

void mutex_lock(void *);
void mutex_unlock(void *);
int notify_change(struct dentry *, struct iattr *);