#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct file;

struct usb_serial_port {
    int number;
    void *driver_data;
};

struct tty_struct {
    struct usb_serial_port *driver_data;
};

struct async_icount {
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

struct moschip_port {
    struct async_icount icount;
    int delta_msr_cond;
    int delta_msr_wait;
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
#define smp_rmb() __asm__ __volatile__("":::"memory")

#define ERESTARTSYS 512
#define EIO 5
#define EFAULT 14
#define ENOIOCTLCMD 515

#define signal_pending(x) 0
#define current NULL
#define wait_event_interruptible(wq, condition) 0
#define dbg(fmt, ...)

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

extern int mos7840_port_paranoia_check(struct usb_serial_port *port, const char *func);
extern int mos7840_get_lsr_info(struct tty_struct *tty, void *argp);
extern int mos7840_get_serial_info(struct moschip_port *port, void *argp);
extern struct moschip_port *mos7840_get_port_private(struct usb_serial_port *port);