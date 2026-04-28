#include <stddef.h>
#include <stdbool.h>

#define VM_SHARED 0x00000008
#define VM_WRITE 0x00000002
#define ENOMEM 12
#define EFAULT 14
#define EEXIST 17

struct mm_struct;
struct file {
    struct address_space *f_mapping;
};
struct vm_area_struct {
    unsigned long vm_flags;
    struct file *vm_file;
};
struct hstate;
struct address_space;
struct page;
typedef unsigned long pte_t;
typedef struct { } spinlock_t;
typedef unsigned long pgoff_t;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define unlikely(x) (x)
#define __SetPageUptodate(x) do { } while (0)
#define __user
#define pte_mkyoung(x) (x)

static inline struct hstate *hstate_vma(struct vm_area_struct *vma) { return NULL; }
static inline struct page *alloc_huge_page(struct vm_area_struct *vma, unsigned long addr, int zero) { return NULL; }
static inline int copy_huge_page_from_user(struct page *page, const void *src, unsigned long len, bool zero) { return 0; }
static inline unsigned long pages_per_huge_page(struct hstate *h) { return 0; }
static inline void set_page_huge_active(struct page *page) { }
static inline unsigned long vma_hugecache_offset(struct hstate *h, struct vm_area_struct *vma, unsigned long addr) { return 0; }
static inline int huge_add_to_page_cache(struct page *page, struct address_space *mapping, pgoff_t idx) { return 0; }
static inline spinlock_t *huge_pte_lockptr(struct hstate *h, struct mm_struct *mm, pte_t *ptep) { return NULL; }
static inline void spin_lock(spinlock_t *lock) { }
static inline int huge_pte_none(pte_t pte) { return 0; }
static inline pte_t huge_ptep_get(pte_t *ptep) { return *ptep; }
static inline void page_dup_rmap(struct page *page, bool compound) { }
static inline void ClearPagePrivate(struct page *page) { }
static inline void hugepage_add_new_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long address) { }
static inline pte_t make_huge_pte(struct vm_area_struct *vma, struct page *page, int writable) { return (pte_t){0}; }
static inline pte_t huge_pte_mkdirty(pte_t pte) { return pte; }
static inline void set_huge_pte_at(struct mm_struct *mm, unsigned long addr, pte_t *ptep, pte_t pte) { }
static inline int huge_ptep_set_access_flags(struct vm_area_struct *vma, unsigned long addr, pte_t *ptep, pte_t pte, int dirty) { return 0; }
static inline void hugetlb_count_add(unsigned long pages, struct mm_struct *mm) { }
static inline void update_mmu_cache(struct vm_area_struct *vma, unsigned long addr, pte_t *ptep) { }
static inline void spin_unlock(spinlock_t *lock) { }
static inline void unlock_page(struct page *page) { }
static inline void put_page(struct page *page) { }