#include <stdbool.h>
#include <stddef.h>

typedef unsigned int sector_t;

struct inode {
    unsigned long i_blkbits;
    unsigned long i_size;
};

struct page {
    unsigned long index;
    unsigned long flags;
};

struct f2fs_map_blocks {
    unsigned int m_lblk;
    unsigned int m_len;
    unsigned int m_flags;
    sector_t m_pblk;
};

struct bio;
struct f2fs_sb_info;

#define F2FS_MAP_MAPPED    0x01
#define F2FS_GET_BLOCK_DEFAULT 0
#define DATA_GENERIC_ENHANCE_READ 0
#define REQ_RAHEAD 0
#define F2FS_RD_DATA 0
#define PAGE_SIZE 4096
#define EFSCORRUPTED 5
#define DATA 0

#define i_size_read(inode) ((inode)->i_size)
#define SetPageMappedToDisk(page) ((page)->flags |= (1 << 0))
#define PageUptodate(page) ((page)->flags & (1 << 1))
#define SetPageUptodate(page) ((page)->flags |= (1 << 1))
#define ClearPageError(page) ((page)->flags &= ~(1 << 2))
#define unlock_page(page) do {} while (0)
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)-1000)
#define PTR_ERR(ptr) ((long)(ptr))

static inline bool __same_bdev(struct f2fs_sb_info *sbi, sector_t block, struct bio *bio) { return false; }
static inline void __submit_bio(struct f2fs_sb_info *sbi, struct bio *bio, int type) {}
static inline void inc_page_count(struct f2fs_sb_info *sbi, int type) {}
static inline void f2fs_wait_on_block_writeback(struct inode *inode, sector_t block_nr) {}
static inline bool f2fs_is_valid_blkaddr(struct f2fs_sb_info *sbi, sector_t block_nr, int type) { return true; }
static inline struct bio *f2fs_grab_read_bio(struct inode *inode, sector_t block_nr, unsigned nr_pages, int op_flags) { return NULL; }
static inline int f2fs_map_blocks(struct inode *inode, struct f2fs_map_blocks *map, int create, int flag) { return 0; }
static inline void zero_user_segment(struct page *page, unsigned start, unsigned end) {}
static inline bool cleancache_get_page(struct page *page) { return false; }
static inline int bio_add_page(struct bio *bio, struct page *page, unsigned len, unsigned offset) { return 0; }

#define F2FS_I_SB(inode) NULL