#include <string.h>
#include <stddef.h>

struct sb_uart_icount {
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

struct sb_uart_port {
    void *lock;
    struct sb_uart_icount icount;
};

struct sb_uart_state {
    struct sb_uart_port *port;
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

#define EFAULT 14

static inline void spin_lock_irq(void *lock) {}
static inline void spin_unlock_irq(void *lock) {}
static inline int copy_to_user(void *dst, const void *src, size_t size) { return 0; }