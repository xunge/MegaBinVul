#include <termios.h>
#include <sys/ioctl.h>

struct tty_driver;
struct tty_struct {
    unsigned int index;
    void *driver_data;
    struct {
        unsigned short ws_row;
        unsigned short ws_col;
    } winsize;
    struct termios termios;
};

struct vc_data {
    struct {
        struct tty_struct *tty;
    } port;
    unsigned int vc_utf;
    unsigned short vc_rows;
    unsigned short vc_cols;
};

extern struct {
    struct vc_data *d;
} vc_cons[];

#define ERESTARTSYS 512
#define IUTF8 0040000

void console_lock(void);
void console_unlock(void);
int vc_allocate(unsigned int currcons);
int tty_port_install(void *port, struct tty_driver *driver, struct tty_struct *tty);