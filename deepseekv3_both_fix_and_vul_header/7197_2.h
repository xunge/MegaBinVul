#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned long ulong;
typedef u32 CLST;

struct buffer_head {
    void *b_data;
};

struct rw_semaphore {
    int dummy;
};

struct wnd_bitmap {
    ulong *free_bits;
    size_t nbits;
    size_t nwnd;
    u32 bits_last;
    struct rw_semaphore rw_lock;
};

struct super_block {
    u32 s_blocksize;
    unsigned int s_blocksize_bits;
};

struct ntfs_sb_info {
    struct super_block *sb;
    struct {
        struct wnd_bitmap bitmap;
    } used;
    unsigned int cluster_bits;
};

struct fstrim_range {
    u64 start;
    u64 len;
    u64 minlen;
};

#define BITMAP_MUTEX_CLUSTERS 0
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))

static inline int test_bit(int nr, const ulong *addr) {
    return (addr[nr / (8 * sizeof(ulong))] >> (nr % (8 * sizeof(ulong)))) & 1;
}

static inline void down_read_nested(struct rw_semaphore *sem, int subclass) {}
static inline void up_read(struct rw_semaphore *sem) {}
static inline void put_bh(struct buffer_head *bh) {}

static inline CLST bytes_to_cluster(struct ntfs_sb_info *sbi, u64 bytes) {
    return bytes >> sbi->cluster_bits;
}

struct buffer_head *wnd_map(struct wnd_bitmap *wnd, size_t iw);
int ntfs_discard(struct ntfs_sb_info *sbi, CLST lcn, CLST len);