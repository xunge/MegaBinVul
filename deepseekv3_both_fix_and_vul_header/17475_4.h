#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

#define MAX_NR_CONSOLES 63
#define VT_IS_IN_USE(i) (1)
#define fg_console 0
#define GPFIRST 0
#define GPLAST 0
#define GPNUM 0
#define PIT_TICK_RATE 1193182
#define KB_101 0
#define KD_TEXT 0
#define KD_GRAPHICS 1
#define KD_TEXT0 2
#define KD_TEXT1 3
#define VT_AUTO 0
#define VT_PROCESS 1
#define VT_ACKACQ 2
#define CAP_SYS_TTY_CONFIG 1
#define CAP_KILL 1
#define ENOIOCTLCMD ENOTTY

struct tty_struct {
    void *driver_data;
};

struct vt_mode {
    int mode;
    int frsig;
};

struct vc_data {
    unsigned int vc_num;
    unsigned char vc_mode;
    unsigned short vc_hi_font_mask;
    unsigned int vc_scan_lines;
    struct {
        int height;
    } vc_font;
    int vc_resize_user;
    struct vt_mode vt_mode;
    void *vt_pid;
    int vt_newvt;
};

struct console_font_op {
    int op;
    int flags;
    int width;
    int height;
    int charcount;
    void *data;
};

struct kbd_repeat {
    int delay;
    int period;
};

struct vt_stat {
    unsigned short v_active;
    unsigned short v_state;
};

struct vt_setactivate {
    unsigned int console;
    struct vt_mode mode;
};

struct vt_sizes {
    unsigned short v_rows;
    unsigned short v_cols;
};

struct vt_consize {
    unsigned short v_vlin;
    unsigned short v_clin;
    unsigned short v_vcol;
    unsigned short v_ccol;
    unsigned short v_rows;
    unsigned short v_cols;
};

struct vt_event {
    unsigned int event;
    unsigned int oldev;
    unsigned int newev;
    unsigned int pad[4];
};

struct vt_spawn_console {
    int lock;
    void *pid;
    int sig;
};

struct signal_struct {
    struct tty_struct *tty;
};

struct task_struct {
    struct signal_struct *signal;
};

static int vt_dont_switch;
static struct vt_spawn_console vt_spawn_con;
static struct vc_cons {
    struct vc_data *d;
} vc_cons[MAX_NR_CONSOLES];
static struct task_struct *current;

static inline int capable(int cap) { return 1; }
static inline int put_user(unsigned int val, void *addr) { return 0; }
static inline int get_user(unsigned short *val, void *addr) { return 0; }
static inline int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline int copy_to_user(void *to, const void *from, size_t n) { return 0; }
static inline void spin_lock_irq(int *lock) {}
static inline void spin_unlock_irq(int *lock) {}
static inline void *get_pid(void *pid) { return pid; }
static inline void put_pid(void *pid) {}
static inline void *task_pid(void *task) { return NULL; }
static inline int valid_signal(int sig) { return 1; }

static inline void console_lock() {}
static inline void console_unlock() {}

static inline int vc_cons_allocated(unsigned int console) { return 1; }
static inline int tioclinux(struct tty_struct *tty, unsigned long arg) { return 0; }
static inline void kd_mksound(unsigned int count, unsigned int ticks) {}
static inline int ksys_ioperm(unsigned long from, unsigned long num, int turn_on) { return 0; }
static inline int kbd_rate(struct kbd_repeat *kbrep) { return 0; }
static inline int vt_do_kdskbmode(unsigned int console, unsigned int arg) { return 0; }
static inline int vt_do_kdgkbmode(unsigned int console) { return 0; }
static inline int vt_do_kdskbmeta(unsigned int console, unsigned int arg) { return 0; }
static inline int vt_do_kdgkbmeta(unsigned int console) { return 0; }
static inline int vt_do_kbkeycode_ioctl(unsigned int cmd, void *up, int perm) { return 0; }
static inline int vt_do_kdsk_ioctl(unsigned int cmd, void *up, int perm, unsigned int console) { return 0; }
static inline int vt_do_kdgkb_ioctl(unsigned int cmd, void *up, int perm) { return 0; }
static inline int vt_do_diacrit(unsigned int cmd, void *up, int perm) { return 0; }
static inline int vt_do_kdskled(unsigned int console, unsigned int cmd, unsigned long arg, int perm) { return 0; }
static inline int vc_allocate(unsigned int console) { return 0; }
static inline void set_console(unsigned int console) {}
static inline int vt_waitactive(unsigned int arg) { return 0; }
static inline void vt_disallocate_all() {}
static inline int vt_disallocate(unsigned int arg) { return 0; }
static inline void vc_resize(struct vc_data *vc, unsigned int cols, unsigned int rows) {}
static inline int con_font_op(struct vc_data *vc, struct console_font_op *op) { return 0; }
static inline int con_set_cmap(void *up) { return 0; }
static inline int con_get_cmap(void *up) { return 0; }
static inline int do_fontx_ioctl(unsigned int cmd, void *up, int perm, struct console_font_op *op) { return 0; }
static inline void con_set_default_unimap(struct vc_data *vc) {}
static inline int con_set_trans_old(void *up) { return 0; }
static inline int con_get_trans_old(void *up) { return 0; }
static inline int con_set_trans_new(void *up) { return 0; }
static inline int con_get_trans_new(void *up) { return 0; }
static inline void con_clear_unimap(struct vc_data *vc) {}
static inline int do_unimap_ioctl(unsigned int cmd, void *up, int perm, struct vc_data *vc) { return 0; }
static inline int vt_event_wait_ioctl(void *event) { return 0; }
static inline void do_unblank_screen(int unblank) {}
static inline void do_blank_screen(int blank) {}
static inline void complete_change_console(struct vc_data *vc) {}
static inline void tty_ldisc_flush(struct tty_struct *tty) {}
static inline unsigned int msecs_to_jiffies(unsigned int msec) { return msec; }
static inline unsigned int array_index_nospec(unsigned int index, unsigned long size) { return index; }

#define KIOCSOUND 0x4B2F
#define KDMKTONE 0x4B30
#define KDGKBTYPE 0x4B33
#define KDKBDREP 0x4B4B
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
#define KDGKBENT 0x4B46
#define KDSKBENT 0x4B47
#define KDGKBSENT 0x4B48
#define KDSKBSENT 0x4B49
#define KDGKBDIACR 0x4B64
#define KDGKBDIACRUC 0x4B65
#define KDSKBDIACR 0x4B66
#define KDSKBDIACRUC 0x4B67
#define KDGKBLED 0x4B68
#define KDSKBLED 0x4B69
#define KDGETLED 0x4B31
#define KDSETLED 0x4B32
#define KDSIGACCEPT 0x4B4E
#define VT_SETMODE 0x5601
#define VT_GETMODE 0x5602
#define VT_GETSTATE 0x5603
#define VT_OPENQRY 0x5606
#define VT_ACTIVATE 0x5607
#define VT_SETACTIVATE 0x5608
#define VT_WAITACTIVE 0x5609
#define VT_RELDISP 0x5605
#define VT_DISALLOCATE 0x5604
#define VT_RESIZE 0x560A
#define VT_RESIZEX 0x560B
#define PIO_FONT 0x4B6A
#define GIO_FONT 0x4B6B
#define PIO_CMAP 0x4B70
#define GIO_CMAP 0x4B71
#define PIO_FONTX 0x4B6C
#define GIO_FONTX 0x4B6D
#define PIO_FONTRESET 0x4B6E
#define KDFONTOP 0x4B72
#define PIO_SCRNMAP 0x4B40
#define GIO_SCRNMAP 0x4B41
#define PIO_UNISCRNMAP 0x4B42
#define GIO_UNISCRNMAP 0x4B43
#define PIO_UNIMAPCLR 0x4B6F
#define PIO_UNIMAP 0x4B74
#define GIO_UNIMAP 0x4B75
#define VT_LOCKSWITCH 0x560C
#define VT_UNLOCKSWITCH 0x560D
#define VT_GETHIFONTMASK 0x560E
#define VT_WAITEVENT 0x560F

#define KD_FONT_OP_SET 0
#define KD_FONT_OP_GET 1
#define KD_FONT_OP_SET_DEFAULT 2
#define KD_FONT_FLAG_OLD 0x8000
#define KD_FONT_FLAG_DONT_RECALC 0x2000

#define __user