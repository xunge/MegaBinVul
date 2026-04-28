#include <stddef.h>
#include <errno.h>

struct sock;
typedef unsigned int u32;

#define __user

struct ccid_operations {
    int (*ccid_hc_tx_getsockopt)(struct sock *, int, int, u32 __user *, int __user *);
};

struct ccid {
    struct ccid_operations *ccid_ops;
};