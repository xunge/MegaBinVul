#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define S_IALLUGO 0007777
#define strlcpy strncpy
typedef mode_t umode_t;

struct p9_wstat {
    unsigned int atime;
    unsigned int mtime;
    unsigned int n_uid;
    unsigned int n_gid;
    char extension[32];
    unsigned long length;
};

struct inode {
    mode_t i_mode;
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
    unsigned int i_uid;
    unsigned int i_gid;
    unsigned long i_blocks;
};

struct super_block {
    struct v9fs_session_info *s_fs_info;
};

struct v9fs_session_info {
    unsigned int dfltuid;
    unsigned int dfltgid;
};

struct v9fs_inode {
    unsigned int cache_validity;
};

#define V9FS_I(inode) ((struct v9fs_inode *)(inode))
#define V9FS_INO_INVALID_ATTR 0x01
#define V9FS_STAT2INODE_KEEP_ISIZE 0x01

static inline void set_nlink(struct inode *inode, unsigned int nlink) {}
static inline void v9fs_i_size_write(struct inode *inode, unsigned long length) {}
static inline int v9fs_proto_dotu(struct v9fs_session_info *v9ses) { return 0; }
static inline mode_t p9mode2perm(struct v9fs_session_info *v9ses, struct p9_wstat *stat) { return 0; }