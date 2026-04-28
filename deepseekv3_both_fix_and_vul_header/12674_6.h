#include <sys/types.h>
#include <unistd.h>

struct vc_data {
    int dummy;
};

struct console_font_op {
    int dummy;
};

struct tty_struct {
    struct vc_data *driver_data;
    int dummy;
};

struct signal_struct {
    struct tty_struct *tty;
};

struct task_struct {
    struct signal_struct *signal;
    int dummy;
};

extern struct task_struct *current;

#define PIO_FONTX 1
#define GIO_FONTX 2
#define KDFONTOP 3
#define PIO_UNIMAP 4
#define GIO_UNIMAP 5
#define KIOCSOUND 6
#define KDMKTONE 7
#define KDSETMODE 8
#define KDMAPDISP 9
#define KDUNMAPDISP 10
#define KDSKBMODE 11
#define KDSKBMETA 12
#define KDSKBLED 13
#define KDSETLED 14
#define KDSIGACCEPT 15
#define VT_ACTIVATE 16
#define VT_WAITACTIVE 17
#define VT_RELDISP 18
#define VT_DISALLOCATE 19
#define VT_RESIZE 20
#define VT_RESIZEX 21
#define CAP_SYS_TTY_CONFIG 22

#define __user
#define compat_ptr(x) ((void *)(x))

extern long compat_fontx_ioctl_vc(struct vc_data *vc, unsigned int cmd, void *up, int perm, struct console_font_op *op);
extern long compat_fontx_ioctl_cmd(unsigned int cmd, void *up, int perm, struct console_font_op *op);
extern long compat_kdfontop_ioctl(void *up, int perm, struct console_font_op *op, struct vc_data *vc);
extern long compat_unimap_ioctl(unsigned int cmd, void *up, int perm, struct vc_data *vc);
extern long vt_ioctl(struct tty_struct *tty, unsigned int cmd, unsigned long arg);
extern int capable(int cap);