#include <termios.h>

struct tty_struct;
struct ktermios {
    unsigned int c_cflag;
};

struct tty_operations {
    void (*set_termios)(struct tty_struct *tty, struct ktermios *old);
};

struct tty_struct {
    struct ktermios *termios;
    struct tty_driver *driver;
};

struct tty_driver {
    struct tty_operations *ops;
    void (*set_termios)(struct tty_struct *tty, struct ktermios *old);
};