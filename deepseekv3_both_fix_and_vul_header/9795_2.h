#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <signal.h>

#define __user
#define TTY_EXCLUSIVE 0
#define ENOIOCTLCMD (-1)
#define EINTR (-2)
#define ENOTTY (-3)
#define EINVAL (-4)

struct file {
    struct {
        struct {
            struct inode *d_inode;
        } *f_dentry;
    };
};

struct tty_struct {
    unsigned long flags;
    struct {
        int (*break_ctl)(struct tty_struct *, int);
        int (*ioctl)(struct tty_struct *, struct file *, unsigned int, unsigned long);
    } *ops;
    struct {
        struct {
            int num;
        } *ops;
    } *ldisc;
};

struct tty_ldisc {
    struct {
        int (*ioctl)(struct tty_struct *, struct file *, unsigned int, unsigned long);
    } *ops;
};

struct inode;

struct task_struct {
    struct {
        struct tty_struct *tty;
    } *signal;
};

extern struct task_struct *current;