#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef int64_t s64;

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    void *s_fs_info;
};

struct metapage {
    void *data;
};

struct dmap {
};

struct bmap {
    s64 db_mapsize;
    int db_l2nbperpage;
};

struct jfs_sb_info {
    struct inode *ipbmap;
    struct bmap *bmap;
    unsigned int flag;
    s64 minblks_trim;
};

#define JFS_SBI(sb) ((struct jfs_sb_info *)(sb)->s_fs_info)
#define IREAD_LOCK(ip, type)
#define IREAD_UNLOCK(ip)
#define RDWRLOCK_DMAP 0
#define unlikely(x) (x)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define EIO 5
#define PSIZE 4096
#define JFS_DISCARD 0x00000001
#define KERN_ERR ""

#define BLKTODMAP(b, l) ((b) >> (l))
#define BPERDMAP (1 << 15)

int dbFreeDmap(struct bmap *bmp, struct dmap *dp, s64 blkno, int nb);
void jfs_error(struct super_block *sb, const char *fmt, ...);
void jfs_issue_discard(struct inode *ip, s64 blkno, s64 nblocks);
struct metapage *read_metapage(struct inode *ip, s64 blkno, int size, int flag);
void write_metapage(struct metapage *mp);
void release_metapage(struct metapage *mp);
int printk(const char *fmt, ...);