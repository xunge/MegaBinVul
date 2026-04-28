#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

typedef unsigned int umode_t;
typedef unsigned long long u64;

struct p9_stat_dotl {
    unsigned int st_result_mask;
    time_t st_atime_sec;
    long st_atime_nsec;
    time_t st_mtime_sec;
    long st_mtime_nsec;
    time_t st_ctime_sec;
    long st_ctime_nsec;
    uid_t st_uid;
    gid_t st_gid;
    unsigned int st_nlink;
    umode_t st_mode;
    off_t st_size;
    u64 st_blocks;
    dev_t st_rdev;
    u64 st_gen;
};

struct inode {
    umode_t i_mode;
    uid_t i_uid;
    gid_t i_gid;
    struct timespec i_atime;
    struct timespec i_mtime;
    struct timespec i_ctime;
    unsigned long i_ino;
    dev_t i_rdev;
    off_t i_size;
    u64 i_blocks;
    unsigned int i_generation;
};

struct v9fs_inode {
    unsigned int cache_validity;
};

#define V9FS_I(inode) ((struct v9fs_inode *)(inode))
#define V9FS_INO_INVALID_ATTR 0x01
#define P9_STATS_BASIC 0x000007ff
#define P9_STATS_ATIME 0x00000001
#define P9_STATS_MTIME 0x00000002
#define P9_STATS_CTIME 0x00000004
#define P9_STATS_UID 0x00000008
#define P9_STATS_GID 0x00000010
#define P9_STATS_NLINK 0x00000020
#define P9_STATS_MODE 0x00000040
#define P9_STATS_RDEV 0x00000080
#define P9_STATS_SIZE 0x00000100
#define P9_STATS_BLOCKS 0x00000200
#define P9_STATS_GEN 0x00000400
#define V9FS_STAT2INODE_KEEP_ISIZE 0x01
#define S_IALLUGO 0007777

static inline void set_nlink(struct inode *inode, unsigned int nlink) {}
static inline void v9fs_i_size_write(struct inode *inode, off_t i_size) {}
static inline void init_special_inode(struct inode *inode, umode_t mode, dev_t rdev) {}
static inline dev_t new_decode_dev(dev_t dev) { return dev; }