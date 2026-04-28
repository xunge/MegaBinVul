#include <stdlib.h>
#include <errno.h>

#define MIN_NR_CONSOLES 1
#define EBUSY 16

struct tty_port {
    // Minimal stub definition
    int dummy;
};

struct vc_data {
    struct tty_port port;
};

void console_lock(void);
void console_unlock(void);
int vt_busy(unsigned int);
struct vc_data *vc_deallocate(unsigned int);
void tty_port_destroy(struct tty_port *port);
void kfree(void *ptr);