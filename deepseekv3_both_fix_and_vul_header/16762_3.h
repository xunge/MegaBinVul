#include <stdbool.h>
#include <stdint.h>

#define EIO 5
#define EACCES 13
#define MAY_EXEC 1
#define MAY_ACCESS 2
#define MAY_CHDIR 4
#define STATX_MODE 0x0002
#define STATX_UID 0x0004
#define STATX_GID 0x0008
#define S_ISREG(mode) (((mode) & 0170000) == 0100000)
#define S_IXUGO 0000711
#define READ_ONCE(x) (x)

typedef uint32_t u32;

struct inode {
    unsigned int i_mode;
};
struct fuse_conn {
    bool default_permissions;
};
struct fuse_inode {
    u32 inval_mask;
    uint64_t i_time;
};

extern struct fuse_conn *get_fuse_conn(struct inode *);
extern bool fuse_is_bad(struct inode *);
extern bool fuse_allow_current_process(struct fuse_conn *);
extern struct fuse_inode *get_fuse_inode(struct inode *);
extern int fuse_perm_getattr(struct inode *, int);
extern int generic_permission(struct inode *, int);
extern int fuse_access(struct inode *, int);
extern uint64_t get_jiffies_64(void);
extern bool time_before64(uint64_t a, uint64_t b);