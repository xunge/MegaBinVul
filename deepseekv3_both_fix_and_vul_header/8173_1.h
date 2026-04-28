#include <unistd.h>
#include <string.h>

struct file;
struct inode;
typedef long ssize_t;
typedef long loff_t;
typedef unsigned long size_t;
#define __user
#define EFAULT 14

ssize_t sched_feat_set(char *cmp);
void inode_lock(struct inode *inode);
void inode_unlock(struct inode *inode);
struct inode *file_inode(struct file *filp);
int copy_from_user(void *to, const void __user *from, unsigned long n);
char *strstrip(char *s);