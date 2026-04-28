#include <linux/fs.h>
#include <linux/fuse.h>
#include <linux/errno.h>
#include <linux/fcntl.h>
#include <linux/sched.h>
#include <linux/wait.h>

struct fuse_dev {
    struct fuse_conn *fc;
};

struct fuse_conn {
    struct {
        struct fasync_struct *fasync;
    } iq;
};

struct fasync_struct;