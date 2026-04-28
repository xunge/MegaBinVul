#include <errno.h>
#include <sys/ioctl.h>
#include <stddef.h>

struct tty_struct {
    void *driver_data;
    unsigned long flags;
};

struct tty_port {
    int mutex; // Simplified mutex representation
};

struct uart_state {
    struct tty_port port;
    struct uart_port *uart_port;
};

struct uart_port {
    struct {
        int (*ioctl)(struct uart_port *, unsigned int, unsigned long);
    } *ops;
};

struct file;

#define TTY_IO_ERROR 0
#define ENOIOCTLCMD 515
#define EIO 5

#define TIOCGSERIAL 0x541E
#define TIOCSSERIAL 0x541F
#define TIOCSERCONFIG 0x5453
#define TIOCSERGWILD 0x5454
#define TIOCSERSWILD 0x5455
#define TIOCMIWAIT 0x545C
#define TIOCGICOUNT 0x545D
#define TIOCSERGETLSR 0x5459

static inline void mutex_lock(int *lock) { (void)lock; }
static inline void mutex_unlock(int *lock) { (void)lock; }
static inline int tty_hung_up_p(struct file *filp) { (void)filp; return 0; }

static inline int uart_get_info(struct uart_state *state, void *arg) { (void)state; (void)arg; return 0; }
static inline int uart_set_info(struct tty_struct *tty, struct uart_state *state, void *arg) { (void)tty; (void)state; (void)arg; return 0; }
static inline int uart_do_autoconfig(struct tty_struct *tty, struct uart_state *state) { (void)tty; (void)state; return 0; }
static inline int uart_wait_modem_status(struct uart_state *state, unsigned long arg) { (void)state; (void)arg; return 0; }
static inline int uart_get_count(struct uart_state *state, void *arg) { (void)state; (void)arg; return 0; }
static inline int uart_get_lsr_info(struct tty_struct *tty, struct uart_state *state, void *arg) { (void)tty; (void)state; (void)arg; return 0; }

#define __user
typedef void* user_ptr_t;