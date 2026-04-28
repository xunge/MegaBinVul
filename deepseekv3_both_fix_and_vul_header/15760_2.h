#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t __u32;
typedef uint64_t __u64;

struct super_block {
    unsigned long s_flags;
    void *s_fs_info;
    char *s_id;
    struct block_device *s_bdev;
};

struct block_device {
    // minimal definition
};

struct work_struct {
    // minimal definition
};

struct journal_s {
    // minimal definition
};
typedef struct journal_s journal_t;

#define EXT4_SB(sb) ((struct ext4_sb_info *)(sb->s_fs_info))
#define EXT4_ERROR_FS 0x0001
#define EXT4_MF_FS_ABORTED 0x0002
#define KERN_CRIT "<2>"
#define SB_RDONLY 0x0001
#define ERRORS_CONT 0
#define WARN_ON_ERROR 0
#define ERRORS_PANIC 0
#define EIO 5

struct ext4_sb_info {
    journal_t *s_journal;
    unsigned long s_mount_state;
    struct work_struct s_error_work;
    unsigned long s_mount_flags;
};

static inline bool test_opt(struct super_block *sb, int opt) { return false; }
static inline bool sb_rdonly(struct super_block *sb) { return false; }
static inline bool bdev_read_only(struct block_device *bdev) { return false; }
static inline void WARN_ON_ONCE(int condition) {}
static inline void ext4_set_mount_flag(struct super_block *sb, int flag) {}
static inline void jbd2_journal_abort(journal_t *journal, int err) {}
static inline void schedule_work(struct work_struct *work) {}
static inline void ext4_commit_super(struct super_block *sb) {}
static inline void save_error_info(struct super_block *sb, int error, __u32 ino, __u64 block, const char *func, unsigned int line) {}
static inline bool system_going_down(void) { return false; }
static inline void ext4_msg(struct super_block *sb, const char *level, const char *fmt, ...) {}
static inline void smp_wmb(void) {}
static inline void panic(const char *fmt, ...) { exit(1); }