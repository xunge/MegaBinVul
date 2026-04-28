#include <linux/types.h>
#include <linux/errno.h>
#include <stddef.h>

typedef unsigned int u32;
#define __user

struct sock;
struct ccid {
    struct ccid_ops *ccid_ops;
};

struct ccid_ops {
    int (*ccid_hc_rx_getsockopt)(struct sock *sk, int optname, int len,
                                u32 __user *optval, int __user *optlen);
};