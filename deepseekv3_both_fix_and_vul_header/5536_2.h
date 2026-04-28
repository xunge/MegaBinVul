#include <errno.h>
#include <stdio.h>

#define SB_UNFROZEN 0
#define MS_RDONLY 1
#define MS_RMT_MASK 0
#define CONFIG_BLOCK 1
#define EBUSY 16
#define EACCES 13

struct sb_writers {
    int frozen;
};

struct file_system_type {
    const char *name;
};

struct super_operations {
    int (*remount_fs)(struct super_block *, int *, void *);
};

struct super_block {
    struct file_system_type *s_type;
    void *s_bdev;
    struct super_operations *s_op;
    struct sb_writers s_writers;
    unsigned long s_flags;
    int s_readonly_remount;
};

static inline void smp_wmb(void) { }
static inline void WARN(int val, const char *fmt, ...) { }

int bdev_read_only(void *bdev);
void acct_auto_close(struct super_block *sb);
void shrink_dcache_sb(struct super_block *sb);
void sync_filesystem(struct super_block *sb);
void mark_files_ro(struct super_block *sb);
int sb_prepare_remount_readonly(struct super_block *sb);
void invalidate_bdev(void *bdev);