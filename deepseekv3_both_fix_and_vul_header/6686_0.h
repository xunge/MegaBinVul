#include <stddef.h>
#include <stdbool.h>

#define ENOMEM 12
#define EFAULT 14
#define EEXIST 17

#define VM_SHARED 0x00000001
#define VM_WRITE 0x00000002

typedef unsigned long pgoff_t;
typedef struct { unsigned long pte; } pte_t;
typedef struct { int lock; } spinlock_t;

struct mm_struct;
struct vm_area_struct {
    unsigned long vm_flags;
    struct file *vm_file;
};
struct hstate;
struct page;
struct file {
    struct address_space *f_mapping;
};
struct address_space {
    struct inode *host;
};
struct inode {
    unsigned long i_size;
};

#define __user
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-4096)
#define unlikely(x) (x)

static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline void __SetPageUptodate(struct page *page) {}
static inline void set_page_huge_active(struct page *page) {}
static inline void ClearPagePrivate(struct page *page) {}
static inline void unlock_page(struct page *page) {}
static inline void put_page(struct page *page) {}
static inline void page_dup_rmap(struct page *page, bool flag) {}

static inline unsigned long i_size_read(struct inode *inode) { return inode->i_size; }
static inline unsigned long huge_page_shift(struct hstate *h) { return 0; }

struct hstate *hstate_vma(struct vm_area_struct *vma) { return NULL; }
struct page *alloc_huge_page(struct vm_area_struct *vma, unsigned long addr, int flags) { return NULL; }
int copy_huge_page_from_user(struct page *page, const void *src, unsigned long size, bool flags) { return 0; }
unsigned long pages_per_huge_page(struct hstate *h) { return 0; }
unsigned long vma_hugecache_offset(struct hstate *h, struct vm_area_struct *vma, unsigned long addr) { return 0; }
int huge_add_to_page_cache(struct page *page, struct address_space *mapping, pgoff_t idx) { return 0; }
spinlock_t *huge_pte_lockptr(struct hstate *h, struct mm_struct *mm, pte_t *pte) { return NULL; }
pte_t huge_ptep_get(pte_t *ptep) { return (pte_t){0}; }
int huge_pte_none(pte_t pte) { return 1; }
pte_t make_huge_pte(struct vm_area_struct *vma, struct page *page, int writable) { return (pte_t){0}; }
pte_t huge_pte_mkdirty(pte_t pte) { return pte; }
pte_t pte_mkyoung(pte_t pte) { return pte; }
void set_huge_pte_at(struct mm_struct *mm, unsigned long addr, pte_t *ptep, pte_t pte) {}
int huge_ptep_set_access_flags(struct vm_area_struct *vma, unsigned long addr, pte_t *ptep, pte_t pte, int dirty) { return 0; }
void hugetlb_count_add(unsigned long pages, struct mm_struct *mm) {}
void update_mmu_cache(struct vm_area_struct *vma, unsigned long addr, pte_t *pte) {}
void hugepage_add_new_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long addr) {}