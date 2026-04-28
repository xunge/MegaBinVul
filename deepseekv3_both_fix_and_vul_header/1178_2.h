#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define KB_101 0x02
#define PIT_TICK_RATE 1193182ul
#define GPFIRST 0x3b0
#define GPLAST 0x3df
#define GPNUM (GPLAST - GPFIRST + 1)
#define CAP_SYS_TTY_CONFIG 0
#define CAP_KILL 0
#define SIGKILL 9

/* IOCTL commands */
#define KIOCSOUND 0x4B2F
#define KDMKTONE 0x4B30
#define KDGKBTYPE 0x4B33
#define KDKBDREP 0x4B46
#define KDSETMODE 0x4B3A
#define KDGETMODE 0x4B3B
#define KDMAPDISP 0x4B3C
#define KDUNMAPDISP 0x4B3D
#define KDSKBMODE 0x4B45
#define KDGKBMODE 0x4B44
#define KDSKBMETA 0x4B62
#define KDGKBMETA 0x4B63
#define KDGETKEYCODE 0x4B4C
#define KDSETKEYCODE 0x4B4D
#define KDGKBENT 0x4B48
#define KDSKBENT 0x4B47
#define KDGKBSENT 0x4B49
#define KDSKBSENT 0x4B4A
#define KDGKBDIACR 0x4B64
#define KDGKBDIACRUC 0x4B65
#define KDSKBDIACR 0x4B66
#define KDSKBDIACRUC 0x4B67
#define KDGKBLED 0x4B68
#define KDSKBLED 0x4B69
#define KDGETLED 0x4B31
#define KDSETLED 0x4B32
#define KDSIGACCEPT 0x4B4E
#define KDFONTOP 0x4B72
#define KDADDIO 0x4B34
#define KDDELIO 0x4B35
#define KDENABIO 0x4B36
#define KDDISABIO 0x4B37

/* Error codes */
#define EPERM 1
#define EINVAL 22
#define ENXIO 6
#define EFAULT 14
#define ENOIOCTLCMD 515

struct vc_data {
    int vc_num;
    int vc_mode;
};

struct tty_struct {
    struct vc_data *driver_data;
};

struct kbd_repeat {
    int delay;
    int period;
};

struct console_font_op {
    unsigned int op;
    unsigned int flags;
    unsigned int width, height;
    unsigned int charcount;
    void *data;
};

enum {
    KD_FONT_OP_GET,
    KD_FONT_OP_SET,
    KD_FONT_OP_SET_DEFAULT,
    KD_FONT_OP_COPY,
};

static struct {
    int lock;
    pid_t *pid;
    int sig;
} vt_spawn_con;

/* Dummy function declarations */
#define __user
#define capable(x) 0
#define put_user(x, y) 0
#define copy_from_user(x, y, z) 0
#define copy_to_user(x, y, z) 0
#define spin_lock_irq(x)
#define spin_unlock_irq(x)
#define get_pid(x) NULL
#define put_pid(x)
#define task_pid(x) NULL
#define current NULL
#define valid_signal(x) 1
#define msecs_to_jiffies(x) (x)
#define kd_mksound(x, y)
#define kbd_rate(x) 0
#define vt_kdsetmode(x, y) 0
#define vt_do_kdskbmode(x, y) 0
#define tty_ldisc_flush(x)
#define vt_do_kdgkbmode(x) 0
#define vt_do_kdskbmeta(x, y) 0
#define vt_do_kdgkbmeta(x) 0
#define vt_do_kbkeycode_ioctl(x, y, z) 0
#define vt_do_kdsk_ioctl(x, y, z, w) 0
#define vt_do_kdgkb_ioctl(x, y, z) 0
#define vt_do_diacrit(x, y, z) 0
#define vt_do_kdskled(x, y, z, w) 0
#define con_font_op(x, y) 0
#define ksys_ioperm(x, y, z) 0