#include <stdbool.h>
#include <stddef.h>

typedef unsigned int sector_t;

struct list_head {
    struct list_head *next, *prev;
};

struct page {
    unsigned long flags;
    struct list_head lru;
    unsigned long index;
};

struct address_space {
    struct inode *host;
};

struct inode {
    void *i_sb;
};

struct bio;

struct f2fs_map_blocks {
    sector_t m_pblk;
    sector_t m_lblk;
    unsigned int m_len;
    unsigned int m_flags;
    void *m_next_pgofs;
    void *m_next_extent;
    int m_seg_type;
    bool m_may_create;
};

#define NO_CHECK_TYPE 0
#define PAGE_SIZE 4096
#define F2FS_I_SB(inode) ((inode)->i_sb)
#define DATA 0

#define list_last_entry(ptr, type, member) \
    ((type *)((char *)(ptr)->prev - offsetof(type, member)))

void prefetchw(const void *x);
void list_del(struct list_head *entry);
void SetPageError(struct page *page);
void zero_user_segment(struct page *page, unsigned start, unsigned end);
void unlock_page(struct page *page);
void put_page(struct page *page);
void BUG_ON(int condition);
int add_to_page_cache_lru(struct page *page, struct address_space *mapping,
                         unsigned long index, unsigned gfp_mask);
unsigned readahead_gfp_mask(struct address_space *mapping);
void __submit_bio(void *sb, struct bio *bio, int type);
int f2fs_read_single_page(struct inode *inode, struct page *page, unsigned nr_pages,
                         struct f2fs_map_blocks *map, struct bio **bio,
                         sector_t *last_block_in_bio, bool is_readahead);

static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}