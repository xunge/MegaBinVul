#include <stddef.h>

#define MAX_NR_CONSOLES 63
#define MIN_NR_CONSOLES 1

struct tty_port {
    // 最小化tty_port结构定义
    int dummy;
};

struct vc_data {
    struct tty_port port;
};

static inline int vt_busy(int i) { return 0; }
static inline struct vc_data *vc_deallocate(int i) { return NULL; }
static inline void console_lock(void) {}
static inline void console_unlock(void) {}
static inline void tty_port_destroy(struct tty_port *port) {}
static inline void kfree(void *p) {}