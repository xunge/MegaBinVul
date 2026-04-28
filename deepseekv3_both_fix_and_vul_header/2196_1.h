#include <sys/time.h>

typedef struct {
    unsigned long seg;
} mm_segment_t;

#define KERNEL_DS ((mm_segment_t){0})
#define get_fs() ((mm_segment_t){0})
#define set_fs(x) do {} while(0)

struct net;
struct socket;
#define __user

int sock_do_ioctl(struct net *net, struct socket *sock, unsigned int cmd, unsigned long arg);
int compat_put_timeval(void __user *up, struct timeval *ktv);