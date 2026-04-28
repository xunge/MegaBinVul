#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define GFS2_DIF_INHERIT_JDATA (1 << 0)
#define GFS2_DIF_JDATA (1 << 1)
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define S_IFMT 0170000
#define S_IFDIR 0040000
#define __user
#define EFAULT 14

typedef unsigned int u32;

struct file {
    struct {
        struct {
            struct inode *d_inode;
        } *dentry;
    } f_path;
};

struct inode {
    unsigned short i_mode;
};

extern u32 fsflags_cvt(const u32 *table, u32 fsflags);
extern int do_gfs2_set_flags(struct file *filp, u32 gfsflags, u32 mask);
extern int get_user(u32, u32 *);

static const u32 fsflags_to_gfs2[32] = {0};