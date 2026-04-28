#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef unsigned int block_t;
typedef uint32_t nid_t;

struct super_block;
struct page;

struct inode {
    unsigned int i_mode;
};

struct rw_semaphore {
    // placeholder for rw_semaphore
};

struct f2fs_sb_info {
    struct super_block *sb;
    unsigned int skipped_gc_rwsem;
};

struct f2fs_summary {
    uint32_t nid;
    uint16_t ofs_in_node;
};

struct gc_inode_list {
    // placeholder for gc inode list
};

struct node_info {
    nid_t ino;
};

struct f2fs_inode_info {
    struct inode vfs_inode;
    struct rw_semaphore i_gc_rwsem[2];
};

#define WRITE 0
#define READ 1
#define BG_GC 0
#define FG_GC 1
#define META_NAT 0
#define REQ_RAHEAD 0

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define le32_to_cpu(x) (x)
#define le16_to_cpu(x) (x)
#define F2FS_I(inode) ((struct f2fs_inode_info *)inode)
#define S_ISREG(mode) (((mode) & 0170000) == 0100000)
#define NAT_BLOCK_OFFSET(nid) (nid)

static unsigned int f2fs_usable_blks_in_seg(struct f2fs_sb_info *sbi, unsigned int segno) { return 0; }
static block_t START_BLOCK(struct f2fs_sb_info *sbi, unsigned int segno) { return 0; }
static bool has_not_enough_free_secs(struct f2fs_sb_info *sbi, int a, int b) { return false; }
static unsigned int get_valid_blocks(struct f2fs_sb_info *sbi, unsigned int segno, bool b) { return 0; }
static unsigned int BLKS_PER_SEC(struct f2fs_sb_info *sbi) { return 0; }
static int check_valid_map(struct f2fs_sb_info *sbi, unsigned int segno, int off) { return 0; }
static void f2fs_ra_meta_pages(struct f2fs_sb_info *sbi, nid_t nid, int count, int type, bool lock) {}
static void f2fs_ra_node_page(struct f2fs_sb_info *sbi, nid_t nid) {}
static bool is_alive(struct f2fs_sb_info *sbi, struct f2fs_summary *sum, struct node_info *dni, block_t blkaddr, unsigned int *nofs) { return false; }
static struct inode *f2fs_iget(struct super_block *sb, nid_t ino) { return NULL; }
static bool is_bad_inode(struct inode *inode) { return false; }
static void iput(struct inode *inode) {}
static bool down_write_trylock(struct rw_semaphore *sem) { return true; }
static void up_write(struct rw_semaphore *sem) {}
static block_t f2fs_start_bidx_of_node(unsigned int nofs, struct inode *inode) { return 0; }
static bool f2fs_post_read_required(struct inode *inode) { return false; }
static int ra_data_block(struct inode *inode, block_t bidx) { return 0; }
static void add_gc_inode(struct gc_inode_list *gc_list, struct inode *inode) {}
static struct page *f2fs_get_read_data_page(struct inode *inode, block_t bidx, int type, bool lock) { return NULL; }
static void f2fs_put_page(struct page *page, int unlock) {}
static struct inode *find_gc_inode(struct gc_inode_list *gc_list, nid_t ino) { return NULL; }
static void inode_dio_wait(struct inode *inode) {}
static int move_data_block(struct inode *inode, block_t bidx, int gc_type, unsigned int segno, int off) { return 0; }
static int move_data_page(struct inode *inode, block_t bidx, int gc_type, unsigned int segno, int off) { return 0; }
static void stat_inc_data_blk_count(struct f2fs_sb_info *sbi, int count, int gc_type) {}