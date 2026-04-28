#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

struct super_block {
    struct file_system_type *s_type;
    const struct super_operations *s_op;
    const struct dentry_operations *s_d_op;
    struct dentry *s_root;
    unsigned long s_flags;
    loff_t s_maxbytes;
    unsigned long s_blocksize;
    unsigned long s_magic;
    int s_stack_depth;
    void *s_bdi;
};

struct inode {
    uid_t i_uid;
};

struct dentry {
    struct super_block *d_sb;
    struct inode *d_inode;
};

struct path {
    struct dentry *dentry;
};

struct file_system_type {
    const char *name;
};

struct backing_dev_info {
    int dummy;
};

struct ecryptfs_mount_crypt_stat {
    int dummy;
};

struct ecryptfs_sb_info {
    struct backing_dev_info bdi;
    struct ecryptfs_mount_crypt_stat mount_crypt_stat;
};

struct ecryptfs_dentry_info {
    struct path lower_path;
};

struct super_operations {
    int dummy;
};

struct dentry_operations {
    int dummy;
};

struct user_namespace {
    int dummy;
};

struct user_namespace init_user_ns;

struct file_system_type ecryptfs_fs_type;
struct kmem_cache *ecryptfs_sb_info_cache;
struct kmem_cache *ecryptfs_dentry_info_cache;
const struct super_operations ecryptfs_sops;
const struct dentry_operations ecryptfs_dops;

#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define EPERM 1
#define KERN_ERR "<3>"
#define KERN_WARNING "<4>"
#define MS_POSIXACL (1<<16)
#define MS_RDONLY 1
#define MS_ACTIVE (1<<30)
#define LOOKUP_FOLLOW 0x0001
#define LOOKUP_DIRECTORY 0x0002
#define FILESYSTEM_MAX_STACK_DEPTH 2
#define ECRYPTFS_SUPER_MAGIC 0xf15f
#define BDI_CAP_MAP_COPY 0

static inline int IS_ERR(const void *ptr) { return 0; }
static inline long PTR_ERR(const void *ptr) { return 0; }
static inline void *ERR_PTR(long error) { return NULL; }
static inline int set_anon_super(struct super_block *s, void *data) { return 0; }

uid_t current_uid(void) { return 0; }
uid_t from_kuid(struct user_namespace *ns, uid_t uid) { return uid; }
uid_t i_uid_read(struct inode *inode) { return inode->i_uid; }
int uid_eq(uid_t left, uid_t right) { return left == right; }

void *kmem_cache_zalloc(struct kmem_cache *cache, int flags) { return NULL; }
void kmem_cache_free(struct kmem_cache *cache, void *objp) {}
struct super_block *sget(struct file_system_type *type, 
                        int (*test)(struct super_block *,void *),
                        int (*set)(struct super_block *,void *),
                        int flags, void *data) { return NULL; }
int bdi_setup_and_register(struct backing_dev_info *bdi, const char *name, 
                          unsigned int cap) { return 0; }
int kern_path(const char *name, unsigned int flags, struct path *path) { return 0; }
void path_put(struct path *path) {}
void deactivate_locked_super(struct super_block *s) {}
struct inode *ecryptfs_get_inode(struct inode *lower_inode, 
                                struct super_block *sb) { return NULL; }
struct dentry *d_make_root(struct inode *root_inode) { return NULL; }
struct dentry *dget(struct dentry *dentry) { return NULL; }
void printk(const char *fmt, ...) {}
void ecryptfs_printk(const char *level, const char *fmt, ...) {}
void ecryptfs_set_superblock_private(struct super_block *s, 
                                    struct ecryptfs_sb_info *sbi) {}
void ecryptfs_destroy_mount_crypt_stat(
    struct ecryptfs_mount_crypt_stat *mount_crypt_stat) {}
void ecryptfs_set_superblock_lower(struct super_block *s, 
                                  struct super_block *lower_sb) {}
void ecryptfs_set_dentry_private(struct dentry *dentry, 
                                struct ecryptfs_dentry_info *dentry_info) {}
int ecryptfs_parse_options(struct ecryptfs_sb_info *sbi, 
                          void *raw_data, uid_t *check_ruid) { return 0; }