#include <stddef.h>

#define ERR_PTR(err) ((void *)((long)(err)))
#define NUMA_NO_NODE (-1)

struct vm_area_struct {
    struct file *vm_file;
};
struct file {
    struct address_space *f_mapping;
};
struct address_space {
    struct inode *host;
};
struct inode {
    struct address_space *i_mapping;
};
struct hstate;
struct page;

extern struct hstate *hstate_vma(struct vm_area_struct *vma);
extern long vma_needs_reservation(struct hstate *h, struct vm_area_struct *vma, unsigned long addr);
extern int hugetlb_get_quota(struct address_space *mapping, long chg);
extern struct page *dequeue_huge_page_vma(struct hstate *h, struct vm_area_struct *vma, unsigned long addr, int avoid_reserve);
extern struct page *alloc_buddy_huge_page(struct hstate *h, int nid);
extern void hugetlb_put_quota(struct address_space *mapping, long chg);
extern void set_page_private(struct page *page, unsigned long private);
extern void vma_commit_reservation(struct hstate *h, struct vm_area_struct *vma, unsigned long addr);

extern int hugetlb_lock;
#define spin_lock(lock) (void)(lock)
#define spin_unlock(lock) (void)(lock)

enum {
    VM_FAULT_OOM = 1,
    VM_FAULT_SIGBUS = 2
};