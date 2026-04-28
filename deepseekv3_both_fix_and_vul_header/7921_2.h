#include <stdint.h>
#include <stdbool.h>
#include <math.h>

typedef uint64_t __u64;

struct f2fs_sb_info {
    unsigned long blocksize;
    unsigned int discard_blks;
    unsigned int segs_per_sec;
    void *sb;
    struct {
        int gc_mutex;
    };
};

struct fstrim_range {
    __u64 start;
    __u64 len;
    __u64 minlen;
};

struct cp_control {
    __u64 trimmed;
    unsigned int reason;
    __u64 trim_minlen;
    unsigned int trim_start;
    unsigned int trim_end;
};

#define F2FS_BYTES_TO_BLK(x) ((x) >> 12)
#define F2FS_BLK_TO_BYTES(x) ((x) << 12)
#define MAX_BLKADDR(sbi) (0)
#define MAIN_BLKADDR(sbi) (0)
#define MAIN_SEGS(sbi) (0)
#define GET_SEGNO(sbi, x) (0)
#define BATCHED_TRIM_BLOCKS(sbi) (0)
#define BATCHED_TRIM_SEGMENTS(sbi) (0)
#define SBI_NEED_FSCK (0)
#define CP_DISCARD (0)
#define KERN_WARNING (0)
#define EINVAL 22

#define max_t(type, x, y) ({ type __x = (x); type __y = (y); __x > __y ? __x : __y; })
#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })

static inline unsigned int rounddown(unsigned int x, unsigned int y) {
    return x - x % y;
}

static inline int is_sbi_flag_set(struct f2fs_sb_info *sbi, int flag) { return 0; }
static inline void f2fs_msg(void *sb, int level, const char *msg) {}
static inline int write_checkpoint(struct f2fs_sb_info *sbi, struct cp_control *cpc) { return 0; }
static inline void mark_discard_range_all(struct f2fs_sb_info *sbi) {}
static inline void f2fs_wait_discard_bios(struct f2fs_sb_info *sbi, ...) {}
static inline void mutex_lock(int *mutex) {}
static inline void mutex_unlock(int *mutex) {}
static inline void schedule(void) {}