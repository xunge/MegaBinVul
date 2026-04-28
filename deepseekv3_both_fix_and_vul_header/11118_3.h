#include <stddef.h>
#include <sys/stat.h>

struct super_block {
    void *s_fs_info;
};

struct address_space {
    struct address_space_operations *a_ops;
};

struct inode {
    unsigned long i_state;
    unsigned short i_mode;
    unsigned int i_rdev;
    struct address_space *i_mapping;
    struct inode_operations *i_op;
    struct file_operations *i_fop;
};

struct f2fs_sb_info {
    unsigned long node_ino;
    unsigned long meta_ino;
};

struct address_space_operations {
    // placeholder structure
};

struct inode_operations {
    // placeholder structure
};

struct file_operations {
    // placeholder structure
};

#define F2FS_SB(sb) ((struct f2fs_sb_info *)(sb)->s_fs_info)
#define F2FS_NODE_INO(sbi) ((sbi)->node_ino)
#define F2FS_META_INO(sbi) ((sbi)->meta_ino)

#define GFP_NOFS 0
#define ENOMEM 12
#define EINVAL 22
#define EIO 5

#define I_NEW 0x00000080

#define ERR_PTR(error) ((void *)(long)(error))

struct address_space_operations f2fs_node_aops;
struct address_space_operations f2fs_meta_aops;
struct address_space_operations f2fs_dblock_aops;
struct inode_operations f2fs_file_inode_operations;
struct file_operations f2fs_file_operations;
struct inode_operations f2fs_dir_inode_operations;
struct file_operations f2fs_dir_operations;
struct inode_operations f2fs_encrypted_symlink_inode_operations;
struct inode_operations f2fs_symlink_inode_operations;
struct inode_operations f2fs_special_inode_operations;

static inline void trace_f2fs_iget(struct inode *inode) {}
static inline void trace_f2fs_iget_exit(struct inode *inode, int ret) {}
static inline int do_read_inode(struct inode *inode) { return 0; }
static inline int sanity_check_inode(struct inode *inode) { return 1; }
static inline void mapping_set_gfp_mask(struct address_space *mapping, int mask) {}
static inline void inode_nohighmem(struct inode *inode) {}
static inline int f2fs_encrypted_inode(struct inode *inode) { return 0; }
static inline void f2fs_set_inode_flags(struct inode *inode) {}
static inline void unlock_new_inode(struct inode *inode) {}
static inline void iget_failed(struct inode *inode) {}
static inline struct inode *iget_locked(struct super_block *sb, unsigned long ino) { return NULL; }
static inline void init_special_inode(struct inode *inode, unsigned short mode, unsigned int rdev) {}