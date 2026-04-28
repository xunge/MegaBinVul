#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

struct inode {
    dev_t i_rdev;
};

struct file {
    unsigned f_flags;
    const struct file_operations *f_op;
};

struct tty_struct {
    struct tty_driver *driver;
    int index;
    const char *name;
    struct tty_operations *ops;
    unsigned long flags;
    void *session;
};

struct tty_driver {
    int type;
    int subtype;
};

struct tty_operations {
    int (*open)(struct tty_struct *tty, struct file *filp);
};

struct file_operations {
};

struct mutex {
};

struct task_struct {
    struct signal_struct *signal;
    struct sighand_struct *sighand;
};

struct signal_struct {
    int leader;
    void *tty;
};

struct sighand_struct {
    void *siglock;
};

#define TTYAUX_MAJOR 5
#define TTY_MAJOR 4
#define O_NOCTTY 0400
#define O_NONBLOCK 04000
#define ENXIO 6
#define ENODEV 19
#define ERESTARTSYS 512
#define EBUSY 16
#define CAP_SYS_ADMIN 21
#define CONFIG_VT 1
#define TTY_DEBUG_HANGUP 0
#define KERN_DEBUG "<7>"
#define TTY_EXCLUSIVE 0
#define TTY_DRIVER_TYPE_PTY 2
#define PTY_TYPE_MASTER 0

extern struct mutex tty_mutex;
extern struct tty_driver *console_driver;
extern int fg_console;
extern struct task_struct *current;
extern struct file_operations hung_up_tty_fops;
extern struct file_operations tty_fops;

static inline int capable(int cap) { return 1; }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return 0; }
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline void tty_lock() {}
static inline void tty_unlock() {}
static inline struct tty_struct *get_current_tty() { return NULL; }
static inline struct tty_driver *tty_driver_kref_get(struct tty_driver *d) { return d; }
static inline void tty_kref_put(struct tty_struct *tty) {}
static inline struct tty_driver *console_device(int *index) { return NULL; }
static inline struct tty_driver *get_tty_driver(dev_t device, int *index) { return NULL; }
static inline struct tty_struct *tty_driver_lookup_tty(struct tty_driver *driver, struct inode *inode, int idx) { return NULL; }
static inline int tty_reopen(struct tty_struct *tty) { return 0; }
static inline struct tty_struct *tty_init_dev(struct tty_driver *driver, int idx, int first_ok) { return NULL; }
static inline void tty_driver_kref_put(struct tty_driver *driver) {}
static inline int tty_add_file(struct tty_struct *tty, struct file *file) { return 0; }
static inline void check_tty_count(struct tty_struct *tty, const char *msg) {}
static inline void tty_release(struct inode *inode, struct file *filp) {}
static inline int signal_pending(struct task_struct *p) { return 0; }
static inline void schedule(void) {}
static inline void spin_lock_irq(void *lock) {}
static inline void spin_unlock_irq(void *lock) {}
static inline void __proc_set_tty(struct task_struct *current, struct tty_struct *tty) {}
static inline void nonseekable_open(struct inode *inode, struct file *filp) {}
static inline void *ERR_PTR(long error) { return (void *)error; }
static inline long PTR_ERR(const void *ptr) { return (long)ptr; }
static inline int IS_ERR(const void *ptr) { return 0; }
static inline int printk(const char *fmt, ...) { return 0; }

#define MKDEV(ma,mi) ((ma)<<8 | (mi))