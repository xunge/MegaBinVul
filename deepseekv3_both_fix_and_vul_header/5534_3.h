#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

struct inode;
struct file;
struct cred;

struct file_operations {
    int (*open)(struct inode *, struct file *);
};

struct inode {
    unsigned int i_mode;
    struct address_space *i_mapping;
    void *i_sb;
    struct file_operations *i_fop;
};

struct dentry {
    struct inode *d_inode;
};

struct path {
    void *mnt;
    struct dentry *dentry;
};

struct address_space {
    struct inode *host;
};

struct file {
    unsigned int f_flags;
    unsigned int f_mode;
    struct path f_path;
    struct inode *f_inode;
    struct file_operations *f_op;
    struct address_space *f_mapping;
    void *f_ra;
};

#define FMODE_LSEEK 0x1
#define FMODE_PREAD 0x2
#define FMODE_PWRITE 0x4
#define FMODE_PATH 0x8
#define FMODE_WRITE 0x10
#define FMODE_READ 0x20
#define ENODEV 19

#define O_PATH 010000000
#define O_ACCMODE 0003
#define O_CREAT 0100
#define O_EXCL 0200
#define O_NOCTTY 0400
#define O_TRUNC 01000

#define OPEN_FMODE(flags) ((flags) & O_ACCMODE)
#define unlikely(x) (x)
#define WARN_ON(cond) (cond)

static void path_get(struct path *path) {}
static void path_put(struct path *path) {}
static int __get_file_write_access(struct inode *inode, void *mnt) { return 0; }
static int special_file(unsigned int mode) { return 0; }
static void file_take_write(struct file *file) {}
static void file_sb_list_add(struct file *file, void *sb) {}
static void fops_put(struct file_operations *fops) {}
static void file_sb_list_del(struct file *file) {}
static void put_write_access(struct inode *inode) {}
static void file_reset_write(struct file *file) {}
static void __mnt_drop_write(void *mnt) {}
static struct file_operations *fops_get(struct file_operations *fops) { return fops; }
static int security_file_open(struct file *file, const struct cred *cred) { return 0; }
static int break_lease(struct inode *inode, int flags) { return 0; }
static void i_readcount_inc(struct inode *inode) {}
static void file_ra_state_init(void *ra, struct address_space *mapping) {}