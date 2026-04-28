#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

#define EDGE_CLOSING_WAIT 100
#define HZ 100

typedef uint32_t spinlock_t;
typedef struct { int dummy; } wait_queue_head_t;
typedef struct { int dummy; } wait_queue_t;
typedef struct { int dummy; } task_struct;
typedef struct { int dummy; } tty_struct;
typedef struct { int dummy; } tty_port;
typedef struct { int dummy; } kfifo;

struct edgeport_port {
    struct usb_serial_port *port;
    spinlock_t ep_lock;
    kfifo write_fifo;
    int baud_rate;
};

struct usb_serial_port {
    tty_port port;
    struct usb_serial *serial;
};

struct usb_serial {
    int disconnected;
};

extern task_struct *current;
extern unsigned long jiffies;

#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define init_waitqueue_entry(wait, task) ((void)0)
#define add_wait_queue(queue, wait) ((void)0)
#define remove_wait_queue(queue, wait) ((void)0)
#define set_current_state(state) ((void)0)
#define TASK_INTERRUPTIBLE 0
#define TASK_RUNNING 0
#define signal_pending(task) 0
#define schedule_timeout(timeout) (0)
#define msleep(msecs) usleep(msecs * 1000)
#define max(a,b) ((a)>(b)?(a):(b))
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))

static inline int tx_active(struct edgeport_port *port) { return 0; }
static inline int kfifo_len(kfifo *fifo) { return 0; }
static inline void kfifo_reset_out(kfifo *fifo) {}
static inline tty_struct *tty_port_tty_get(tty_port *port) { return NULL; }
static inline void tty_kref_put(tty_struct *tty) {}