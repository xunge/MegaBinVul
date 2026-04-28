#include <stddef.h>
#include <sys/types.h>

typedef unsigned long vm_flags_t;

struct vm_area_struct {
    vm_flags_t vm_flags;
};

struct address_space {
    void *private_list;
};

struct inode {
    struct address_space *i_mapping;
};

struct hstate;
struct hugepage_subpool;
struct resv_map;

#define VM_NORESERVE 0x00000000
#define VM_MAYSHARE 0x00000000
#define HPAGE_RESV_OWNER 0x00000000
#define ENOMEM 12
#define ENOSPC 28

long region_chg(void *private_list, long from, long to);
void region_add(void *private_list, long from, long to);
struct hstate *hstate_inode(struct inode *inode);
struct hugepage_subpool *subpool_inode(struct inode *inode);
struct resv_map *resv_map_alloc(void);
void set_vma_resv_map(struct vm_area_struct *vma, struct resv_map *resv_map);
void set_vma_resv_flags(struct vm_area_struct *vma, unsigned long flags);
int hugepage_subpool_get_pages(struct hugepage_subpool *spool, long chg);
void hugepage_subpool_put_pages(struct hugepage_subpool *spool, long chg);
int hugetlb_acct_memory(struct hstate *h, long chg);