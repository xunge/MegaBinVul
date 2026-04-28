#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include <stddef.h>

struct compat_mmsghdr;
struct compat_timespec;
struct timespec;
struct mmsghdr;

#define MSG_CMSG_COMPAT 0
#define COMPAT_USE_64BIT_TIME 0
#define EINVAL 22
#define EFAULT 14

#define __user
#define asmlinkage

int __sys_recvmmsg(int fd, struct mmsghdr *mmsg, unsigned int vlen, unsigned int flags, struct timespec *timeout);
int get_compat_timespec(struct timespec *ktspec, struct compat_timespec *timeout);
int put_compat_timespec(struct timespec *ktspec, struct compat_timespec *timeout);