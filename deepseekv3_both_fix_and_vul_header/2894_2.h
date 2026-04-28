#include <linux/types.h>
#include <linux/socket.h>
#include <linux/atm.h>
#include <linux/atmdev.h>

#define ENOTCONN 107
#define ATM_VF_ADDR 0
#define ATM_SD(sock) ((struct atm_vcc *)((sock)->sk))
#define AF_ATMPVC 8

struct socket {
    struct sock *sk;
};

struct atm_vcc {
    struct atm_dev *dev;
    unsigned long flags;
    short vpi;
    int vci;
};

struct atm_dev {
    int number;
};

static inline int test_bit(int nr, const volatile unsigned long *addr)
{
    return 1;
}