#include <stddef.h>

struct hstate;
struct list_head {
    struct list_head *next, *prev;
};
struct address_space {
    struct list_head private_list;
};
struct inode {
    struct address_space *i_mapping;
    long i_blocks;
    void *i_lock;
};

void spin_lock(void *lock);
void spin_unlock(void *lock);
long region_truncate(struct list_head *list, long offset);
struct hstate *hstate_inode(struct inode *inode);
long blocks_per_huge_page(struct hstate *h);
void hugetlb_put_quota(struct address_space *mapping, long delta);
void hugetlb_acct_memory(struct hstate *h, long delta);