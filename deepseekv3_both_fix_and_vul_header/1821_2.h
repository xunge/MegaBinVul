#include <stdint.h>
#include <sys/types.h>
#include <time.h>

typedef uint16_t umode_t;
typedef uint16_t __le16;
typedef uint32_t __le32;
typedef uint64_t __le64;
typedef uint32_t __u32;

#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)
#define le64_to_cpu(x) (x)

#define S_ISREG(mode) (((mode) & 0170000) == 0100000)
#define S_ISDIR(mode) (((mode) & 0170000) == 0040000)
#define S_ISLNK(mode) (((mode) & 0170000) == 0120000)

#define NILFS_I_BMAP 0
#define NILFS_I(inode) ((struct nilfs_inode_info *)(inode))

#define EIO 5
#define ESTALE 116

struct inode {
    umode_t i_mode;
    unsigned long i_ino;
    uid_t i_uid;
    gid_t i_gid;
    unsigned int i_nlink;
    loff_t i_size;
    struct timespec i_atime;
    struct timespec i_ctime;
    struct timespec i_mtime;
    unsigned long i_blocks;
    unsigned int i_generation;
};

struct nilfs_inode {
    __le16 i_mode;
    __le16 i_links_count;
    __le32 i_uid;
    __le32 i_gid;
    __le64 i_size;
    __le64 i_mtime;
    __le64 i_ctime;
    __le32 i_mtime_nsec;
    __le32 i_ctime_nsec;
    __le64 i_blocks;
    __le32 i_flags;
    __le32 i_generation;
};

struct nilfs_inode_info {
    unsigned long i_state;
    struct nilfs_bmap *i_bmap;
    __u32 i_flags;
    __u32 i_dir_start_lookup;
};

static inline void i_uid_write(struct inode *inode, uid_t uid) {
    inode->i_uid = uid;
}

static inline void i_gid_write(struct inode *inode, gid_t gid) {
    inode->i_gid = gid;
}

static inline void set_nlink(struct inode *inode, unsigned int nlink) {
    inode->i_nlink = nlink;
}

static inline void set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}

int nilfs_is_metadata_file_inode(struct inode *inode);
int nilfs_bmap_read(struct nilfs_bmap *bmap, struct nilfs_inode *raw_inode);