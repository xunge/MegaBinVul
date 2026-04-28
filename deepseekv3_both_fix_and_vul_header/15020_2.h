#include <stddef.h>

#define IRTTY_MAGIC 0x1234

struct sir_dev {
    void *priv;
};

struct tty_driver {
    int (*chars_in_buffer)(void *tty);
};

struct tty_struct {
    struct tty_driver *driver;
};

struct sirtty_cb {
    unsigned int magic;
    struct tty_struct *tty;
};

#define IRDA_ASSERT(cond, action) do { if (!(cond)) action; } while (0)