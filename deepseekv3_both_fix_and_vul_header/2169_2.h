#include <stddef.h>
#include <errno.h>
#include <sys/types.h>

struct dentry {
    struct super_block *d_sb;
    struct inode *d_inode;
};

struct file_system_type;
struct super_block {
    unsigned long s_flags;
    void *s_bdi;
    const void *s_op;
    const void *s_d_op;
    unsigned long s_maxbytes;
    unsigned long s_blocksize;
    unsigned long s_magic;
    struct dentry *s_root;
    struct file_system_type *s_type;
};

struct inode {
    uid_t i_uid;
};

struct path {
    struct dentry *dentry;
    void *mnt;
};

struct ecryptfs_sb_info {
    void *bdi;
    void *mount_crypt_stat;
};

struct ecryptfs_dentry_info;

#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define EPERM 1
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))
#define KERN_WARNING "4"
#define KERN_ERR "3"
#define LOOKUP_FOLLOW 1
#define LOOKUP_DIRECTORY 2
#define MS_ACTIVE 0x40000000
#define BDI_CAP_MAP_COPY 0
#define ECRYPTFS_SUPER_MAGIC 0xf15f

extern struct kmem_cache *ecryptfs_sb_info_cache;
extern struct kmem_cache *ecryptfs_dentry_info_cache;
extern struct file_system_type ecryptfs_fs_type;
extern const struct super_operations ecryptfs_sops;
extern const struct dentry_operations ecryptfs_dops;

void *kmem_cache_zalloc(struct kmem_cache *, int);
void kmem_cache_free(struct kmem_cache *, void *);
int ecryptfs_parse_options(struct ecryptfs_sb_info *, void *, ...);
struct super_block *sget(struct file_system_type *, int (*)(struct super_block *, void *), int (*)(struct super_block *, void *), void *);
int set_anon_super(struct super_block *, void *);
int bdi_setup_and_register(void *, const char *, int);
void ecryptfs_set_superblock_private(struct super_block *, struct ecryptfs_sb_info *);
int kern_path(const char *, unsigned int, struct path *);
void ecryptfs_printk(const char *, const char *, ...);
void ecryptfs_set_superblock_lower(struct super_block *, struct super_block *);
struct inode *ecryptfs_get_inode(struct inode *, struct super_block *);
struct dentry *d_alloc_root(struct inode *);
void iput(struct inode *);
void ecryptfs_set_dentry_private(struct dentry *, struct ecryptfs_dentry_info *);
void ecryptfs_set_dentry_lower(struct dentry *, struct dentry *);
void ecryptfs_set_dentry_lower_mnt(struct dentry *, void *);
void path_put(struct path *);
void deactivate_locked_super(struct super_block *);
void ecryptfs_destroy_mount_crypt_stat(void *);
struct dentry *dget(struct dentry *);
int printk(const char *, ...);
uid_t current_uid(void);