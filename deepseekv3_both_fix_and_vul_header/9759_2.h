#include <string.h>
#include <errno.h>

struct uart_icount {
    unsigned int cts;
    unsigned int dsr;
    unsigned int rng;
    unsigned int dcd;
    unsigned int rx;
    unsigned int tx;
    unsigned int frame;
    unsigned int overrun;
    unsigned int parity;
    unsigned int brk;
    unsigned int buf_overrun;
};

struct hso_tiocmget {
    struct uart_icount icount;
};

struct hso_serial {
    struct hso_tiocmget *tiocmget;
    int serial_lock;
};

struct serial_icounter_struct {
    unsigned int cts;
    unsigned int dsr;
    unsigned int rng;
    unsigned int dcd;
    unsigned int rx;
    unsigned int tx;
    unsigned int frame;
    unsigned int overrun;
    unsigned int parity;
    unsigned int brk;
    unsigned int buf_overrun;
};

#define __user
#define ENOENT 2
#define EFAULT 14

static inline void spin_lock_irq(int *lock) { (void)lock; }
static inline void spin_unlock_irq(int *lock) { (void)lock; }
static inline int copy_to_user(void *dst, const void *src, unsigned long size) {
    memcpy(dst, src, size);
    return 0;
}