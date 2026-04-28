#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

struct super_block {
    void *s_fs_info;
};

struct inode;
struct crypto_shash;

struct f2fs_sb_info {
    pthread_mutex_t umount_mutex;
    struct inode *node_inode;
    struct inode *meta_inode;
    void *ckpt;
    void *raw_super;
    struct crypto_shash *s_chksum_driver;
    char *s_qf_names[3];
    bool discard_en;
    unsigned int discard_blks;
    void *write_io[5];
    void *write_io_dummy;
};

struct cp_control {
    int reason;
};

#define F2FS_SB(sb) ((struct f2fs_sb_info *)(sb)->s_fs_info)
#define MAXQUOTAS 3
#define NR_PAGE_TYPE 5
#define SBI_IS_DIRTY 0
#define CP_UMOUNT_FLAG 0
#define CP_UMOUNT 0
#define CP_TRIMMED 0