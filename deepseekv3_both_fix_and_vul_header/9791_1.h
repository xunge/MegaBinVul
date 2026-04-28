#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

typedef int mqd_t;

struct mq_attr {
    long mq_flags;
    long mq_maxmsg;
    long mq_msgsize;
    long mq_curmsgs;
};

struct compat_mq_attr {
    long mq_flags;
    long mq_maxmsg;
    long mq_msgsize;
    long mq_curmsgs;
};

#define __user
#define asmlinkage
#define EFAULT (-1)

void *compat_alloc_user_space(unsigned long size);
int get_compat_mq_attr(struct mq_attr *attr, const struct compat_mq_attr __user *uattr);
int put_compat_mq_attr(const struct mq_attr *attr, struct compat_mq_attr __user *uattr);
long sys_mq_getsetattr(mqd_t mqdes, struct mq_attr __user *newattr, struct mq_attr __user *oldattr);