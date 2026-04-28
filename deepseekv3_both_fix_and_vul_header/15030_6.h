#include <string.h>
#include <time.h>

#define PAGE_CACHE_SIZE 4096
#define ENAMETOOLONG 36
#define ENOSPC 28
#define EOPNOTSUPP 95
#define BOGO_DIRENT_SIZE 64
#define CURRENT_TIME time(NULL)
#define S_IFLNK 0120000
#define S_IRWXUGO 0777
#define S_ISGID 02000
#define KM_USER0 0
#define SGP_WRITE 0

struct address_space_operations {
    /* dummy structure */
    int dummy;
};

struct inode {
    struct super_block *i_sb;
    unsigned long i_size;
    unsigned short i_mode;
    unsigned int i_gid;
    time_t i_ctime;
    time_t i_mtime;
    const void *i_op;
    struct address_space *i_mapping;
};

struct address_space {
    struct address_space_operations *a_ops;
};

struct dentry;
struct page;
struct super_block;
struct shmem_inode_info;

struct shmem_symlink_inline_operations;
struct shmem_symlink_inode_operations;
struct shmem_aops;

extern struct shmem_symlink_inline_operations shmem_symlink_inline_operations;
extern struct shmem_symlink_inode_operations shmem_symlink_inode_operations;
extern struct shmem_aops shmem_aops;

#define SHMEM_I(inode) ((struct shmem_inode_info *)inode)

static inline int security_inode_init_security(struct inode *inode, 
                                             struct inode *dir,
                                             const char *name,
                                             void *value,
                                             size_t len)
{
    return 0;
}

struct inode *shmem_get_inode(struct super_block *sb, int mode, int dev);
int shmem_getpage(struct inode *inode, int index, struct page **pagep, int sgp, void *fsdata);
void iput(struct inode *);
void d_instantiate(struct dentry *, struct inode *);
void dget(struct dentry *);
void *kmap_atomic(struct page *page, int type);
void kunmap_atomic(void *addr, int type);
void set_page_dirty(struct page *page);
void page_cache_release(struct page *page);
void unlock_page(struct page *page);