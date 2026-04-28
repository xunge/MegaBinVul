#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <errno.h>

struct device;
struct device_attribute;

struct socket {
    int type;
};

struct task_struct {
    // Minimal definition
};

struct usbip_device {
    pthread_spinlock_t lock;
    int status;
    struct socket *tcp_socket;
    int sockfd;
    struct task_struct *tcp_rx;
    struct task_struct *tcp_tx;
};

struct stub_device {
    struct usbip_device ud;
};

#define SDEV_ST_AVAILABLE 0
#define SDEV_ST_USED 1
#define SDEV_EVENT_DOWN 0
#define ENODEV 19
#define EINVAL 22

void *stub_rx_loop(void *arg);
void *stub_tx_loop(void *arg);

static inline void spin_lock_irq(pthread_spinlock_t *lock) { pthread_spin_lock(lock); }
static inline void spin_unlock_irq(pthread_spinlock_t *lock) { pthread_spin_unlock(lock); }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline struct stub_device *dev_get_drvdata(struct device *dev) { return NULL; }
static inline struct socket *sockfd_lookup(int fd, int *err) { return NULL; }
static inline void sockfd_put(struct socket *sock) {}
static inline void usbip_event_add(struct usbip_device *ud, int event) {}
static inline struct task_struct *kthread_get_run(void *(*func)(void *), void *data, const char *name) { return NULL; }