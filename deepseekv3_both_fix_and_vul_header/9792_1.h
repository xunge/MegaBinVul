#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

typedef int compat_mode_t;

struct mq_attr {
    long mq_flags;
    long mq_maxmsg;
    long mq_msgsize;
    long mq_curmsgs;
    long __reserved[4];
};

struct compat_mq_attr {
    int mq_flags;
    int mq_maxmsg;
    int mq_msgsize;
    int mq_curmsgs;
    int __reserved[4];
};

#define __user
#define asmlinkage
#define EFAULT 14

void *compat_alloc_user_space(unsigned long size);
int get_compat_mq_attr(struct mq_attr *attr, struct compat_mq_attr __user *u_attr);
long sys_mq_open(const char __user *u_name, int oflag, compat_mode_t mode, void __user *p);
int copy_to_user(void __user *to, const void *from, unsigned long n);