#include <stddef.h>
#include <errno.h>

struct path {
    // dummy members
    int dummy;
};

struct file {
    int f_flags;
};

struct filename {
    // dummy members
    int dummy;
};

struct nameidata {
    unsigned int flags;
    struct path path;
};

struct open_flags {
    int open_flag;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000L))
#define ERR_PTR(x) ((void *)((long)(x)))
#define PTR_ERR(x) ((long)(x))
#define unlikely(x) (x)
#define BUG_ON(x) do { if (x) {} } while (0)

#define __O_TMPFILE 020000000
#define LOOKUP_FOLLOW 0x0001
#define LOOKUP_PARENT 0x0002
#define LOOKUP_OPEN 0x0004
#define LOOKUP_CREATE 0x0008
#define LOOKUP_EXCL 0x0010
#define LOOKUP_RCU 0x0020
#define FILE_OPENED 0x01

#define ELOOP 40
#define EOPENSTALE 100
#define ECHILD 10
#define ESTALE 116

static struct file *get_empty_filp(void) { return 0; }
static int do_tmpfile(int dfd, struct filename *pathname, struct nameidata *nd, int flags, const struct open_flags *op, struct file *file, int *opened) { return 0; }
static int path_init(int dfd, struct filename *pathname, int flags, struct nameidata *nd) { return 0; }
static int do_last(struct nameidata *nd, struct path *path, struct file *file, const struct open_flags *op, int *opened, struct filename *pathname) { return 0; }
static void path_put_conditional(struct path *path, struct nameidata *nd) {}
static void path_put(struct path *path) {}
static int may_follow_link(struct path *link, struct nameidata *nd) { return 0; }
static int follow_link(struct path *link, struct nameidata *nd, void **cookie) { return 0; }
static void put_link(struct nameidata *nd, struct path *link, void *cookie) {}
static void path_cleanup(struct nameidata *nd) {}
static void put_filp(struct file *file) {}