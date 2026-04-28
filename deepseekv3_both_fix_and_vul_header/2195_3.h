#include <sys/types.h>
#include <time.h>

struct net;
struct socket;
typedef unsigned long mm_segment_t;
#define __user
#define KERNEL_DS ((mm_segment_t)0)
#define get_fs() ((mm_segment_t)0)
#define set_fs(x) do {} while(0)
#define sock_do_ioctl(net, sock, cmd, arg) 0
#define compat_put_timespec(up, kts) 0