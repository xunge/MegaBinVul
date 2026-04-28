#include <stddef.h>
#include <sys/types.h>

typedef unsigned long vm_flags_t;

struct address_space {
    void *private_list;
};

struct inode {
    struct address_space *i_mapping;
};

struct vm_area_struct {
    vm_flags_t vm_flags;
};

struct hstate;
struct resv_map;

#define VM_NORESERVE 0x00000000
#define VM_MAYSHARE 0x00000000
#define HPAGE_RESV_OWNER 0x00000000
#define ENOMEM 12
#define ENOSPC 28

struct hstate *hstate_inode(struct inode *inode);
long region_chg(void *private_list, long from, long to);
struct resv_map *resv_map_alloc(void);
void set_vma_resv_map(struct vm_area_struct *vma, struct resv_map *resv_map);
void set_vma_resv_flags(struct vm_area_struct *vma, unsigned long flags);
int hugetlb_get_quota(struct address_space *mapping, long chg);
int hugetlb_acct_memory(struct hstate *h, long chg);
void hugetlb_put_quota(struct address_space *mapping, long chg);
void region_add(void *private_list, long from, long to);