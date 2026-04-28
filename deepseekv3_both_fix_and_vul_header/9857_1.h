#include <stddef.h>
#include <stdlib.h>

struct tty_struct {
    void *disc_data;
    struct tty_operations *ops;
    struct tty_ldisc *ldisc;
    int receive_room;
};

struct tty_operations {
    int (*write)(struct tty_struct *);
};

struct tty_ldisc {
    struct tty_ldisc_ops *ops;
};

struct tty_ldisc_ops {
    void (*flush_buffer)(struct tty_struct *);
};

struct hci_uart {
    struct tty_struct *tty;
    int rx_lock;
};

#define BT_DBG(fmt, ...)
#define BT_ERR(fmt, ...)
#define EEXIST 17
#define EOPNOTSUPP 95
#define ENFILE 23
#define GFP_KERNEL 0

static void spin_lock_init(int *lock) {}
static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void tty_driver_flush_buffer(struct tty_struct *tty) {}