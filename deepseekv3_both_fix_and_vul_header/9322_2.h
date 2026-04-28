#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

#define EINTR 4
#define EINVAL 22
#define ENOTTY 25
#define EPERM 1
#define ENOIOCTLCMD 515

#define TCIFLUSH 0
#define TCIOFLUSH 2
#define TTY_EXCLUSIVE 0
#define CAP_SYS_ADMIN 21

struct file;
struct inode;
struct tty_struct {
    struct tty_ldisc *ldisc;
    struct tty_operations *ops;
    unsigned long flags;
};
struct tty_ldisc {
    struct tty_ldisc_ops *ops;
};
struct tty_ldisc_ops {
    int num;
    int (*ioctl)(struct tty_struct *tty, struct file *file, unsigned int cmd, unsigned long arg);
};
struct tty_operations {
    int (*ioctl)(struct tty_struct *tty, unsigned int cmd, unsigned long arg);
    int (*break_ctl)(struct tty_struct *tty, int state);
};
struct task_struct {
    struct signal_struct *signal;
};
struct signal_struct {
    struct tty_struct *tty;
};

#define current ((struct task_struct *)0)

typedef void *user_ptr_t;
#define __user

static inline int put_user(int val, int *addr) { return 0; }
static inline int capable(int cap) { return 1; }