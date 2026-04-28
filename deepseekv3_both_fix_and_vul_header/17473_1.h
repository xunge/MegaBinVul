#include <stddef.h>
#include <stdatomic.h>

#define MAX_NR_CONSOLES 63
#define ENXIO 6
#define ENOMEM 12
#define GFP_KERNEL 0
#define VT_ALLOCATE 0

struct tty_port {
    const struct tty_port_operations *ops;
};

struct vt_notifier_param {
    void *vc;
};

struct vc_data {
    struct tty_port port;
    unsigned short **vc_uni_pagedir_loc;
    void *vc_screenbuf;
    size_t vc_screenbuf_size;
    int vc_rows;
    int vc_cols;
};

struct vc {
    struct vc_data *d;
    void *SAK_work;
};

extern struct vc vc_cons[MAX_NR_CONSOLES];
extern int global_cursor_default;
extern atomic_int vt_notifier_list;
extern const struct tty_port_operations vc_port_ops;

#define WARN_CONSOLE_UNLOCKED()

void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
void tty_port_init(struct tty_port *port);
void INIT_WORK(void *work, void (*func)(void *));
void visual_init(struct vc_data *vc, unsigned int currcons, int init);
void con_set_default_unimap(struct vc_data *vc);
void vc_init(struct vc_data *vc, int rows, int cols, int do_clear);
void vcs_make_sysfs(unsigned int currcons);
void visual_deinit(struct vc_data *vc);
void vc_SAK(void *work);
void atomic_notifier_call_chain(atomic_int *list, unsigned long val, void *v);

struct tty_port_operations {
    int dummy;
};