#include <stdint.h>
#include <stdlib.h>

struct super_block {
    void *s_fs_info;
};

struct hfsplus_sb_info {
    void *sync_work;
    void *s_vhdr;
    void *attr_tree;
    void *cat_tree;
    void *ext_tree;
    void *alloc_file;
    void *hidden_dir;
    void *s_vhdr_buf;
    void *s_backup_vhdr_buf;
    void *nls;
};

struct hfsplus_vh {
    uint32_t modify_date;
    uint32_t attributes;
};

#define HFSPLUS_SB(sb) ((struct hfsplus_sb_info *)(sb)->s_fs_info)
#define HFSPLUS_VOL_UNMNT 0x00000001
#define HFSPLUS_VOL_INCNSTNT 0x00000002
#define SUPER 0

typedef uint32_t __be32;
typedef uint32_t u32;

static inline void hfs_dbg(int category, const char *fmt, ...) {}
static inline void hfsplus_sync_fs(struct super_block *sb, int wait) {}
static inline void hfs_btree_close(void *tree) {}
static inline __be32 cpu_to_be32(u32 x) { return x; }
static inline u32 hfsp_now2mt(void) { return 0; }
static inline void cancel_delayed_work_sync(void *work) {}
static inline int sb_rdonly(struct super_block *sb) { return 0; }
static inline void iput(void *inode) {}
static inline void kfree(void *ptr) { free(ptr); }
static inline void unload_nls(void *nls) {}