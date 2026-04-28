#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

struct console {
    int index;
    int cflag;
};

struct usbcons_info {
    void *port;
};

struct tty_port {
    int count;
    int console;
};

struct device {
};

struct mutex {
};

struct kref {
};

struct list_head {
    struct list_head *next, *prev;
};

struct spinlock {
    int lock;
};

struct ld_semaphore {
    int count;
};

struct ktermios {
    int c_cflag;
};

struct usb_serial_port {
    void *serial;
    struct tty_port port;
    struct device dev;
};

struct usb_serial {
    void *interface;
    struct usb_serial_driver *type;
    struct mutex disc_mutex;
};

struct usb_serial_driver {
    int (*open)(void *, void *);
    void (*set_termios)(void *, void *, void *);
};

struct tty_struct {
    struct kref kref;
    struct tty_driver *driver;
    int index;
    struct termios termios;
    void *ops;
    struct list_head tty_files;
    struct spinlock files_lock;
    struct ld_semaphore ldisc_sem;
};

struct tty_driver {
    struct module *owner;
    struct kref kref;
};

struct module {
};

struct tty_operations {
};

static struct usbcons_info usbcons_info;
extern struct tty_driver *usb_serial_tty_driver;
extern struct tty_operations usb_console_fake_tty_ops;

#define CREAD 0000200
#define HUPCL 0002000
#define CLOCAL 0004000
#define CS7 0000040
#define CS8 0000060
#define PARODD 0001000
#define PARENB 0000400
#define GFP_KERNEL 0
#define ENODEV 19
#define ENOMEM 12

static inline unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base)
{
    return strtoul(cp, endp, base);
}

static inline void *kzalloc(size_t size, int flags)
{
    return calloc(1, size);
}

static inline void kref_init(struct kref *kref) {}
static inline void init_ldsem(struct ld_semaphore *sem) {}
static inline void spin_lock_init(struct spinlock *lock) {}
static inline void INIT_LIST_HEAD(struct list_head *list) {}
static inline void kref_get(struct kref *kref) {}
static inline void __module_get(struct module *mod) {}
static inline void tty_init_termios(struct tty_struct *tty) {}
static inline void tty_kref_put(struct tty_struct *tty) {}
static inline void mutex_unlock(struct mutex *lock) {}

static inline int usb_serial_port_get_by_minor(int minor) { return 0; }
static inline int usb_autopm_get_interface(void *interface) { return 0; }
static inline int tty_port_tty_set(struct tty_port *port, void *tty) { return 0; }
static inline int tty_port_initialized(struct tty_port *port) { return 0; }
static inline int dev_err(struct device *dev, const char *fmt, ...) { return 0; }
static inline int tty_termios_encode_baud_rate(struct termios *termios, int ibaud, int obaud) { return 0; }
static inline int tty_port_set_initialized(struct tty_port *port, int val) { return 0; }
static inline int usb_autopm_put_interface(void *interface) { return 0; }
static inline int usb_serial_put(void *serial) { return 0; }
static inline int pr_err(const char *fmt, ...) { return 0; }