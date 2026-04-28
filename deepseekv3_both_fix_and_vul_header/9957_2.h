#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

struct clusterip_config;
struct file {
    struct {
        struct dentry *dentry;
    } f_path;
};
struct dentry {
    struct inode *d_inode;
};
struct inode;
struct proc_dir_entry {
    void *data;
};

#define PDE(inode) ((struct proc_dir_entry *)(inode))
#define simple_strtoul(str, endp, base) strtoul(str, endp, base)
#define __user
#define EFAULT 14
#define ENOMEM 12  
#define ENOENT 2
#define EIO 5

typedef long ssize_t;
typedef long loff_t;

extern int clusterip_add_node(struct clusterip_config *c, unsigned long nodenum);
extern int clusterip_del_node(struct clusterip_config *c, unsigned long nodenum);
extern unsigned long copy_from_user(void *to, const void *from, unsigned long n);