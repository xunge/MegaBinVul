#include <stddef.h>

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct;

struct page;

typedef struct { } pgd_t;
typedef struct { } pud_t;
typedef struct { } pmd_t;
typedef struct { } pte_t;
typedef struct { } spinlock_t;

#define FOLL_WRITE 0x01
#define FOLL_GET 0x02
#define FOLL_TOUCH 0x04
#define FOLL_ANON 0x08

#define IS_ERR(x) (0)
#define BUG_ON(x) 
#define unlikely(x) (x)
#define pgd_offset(mm, addr) (NULL)
#define pgd_none(x) (0)
#define pgd_bad(x) (0)
#define pud_offset(pgd, addr) (NULL)
#define pud_none(x) (0)
#define pud_bad(x) (0)
#define pmd_offset(pud, addr) (NULL)
#define pmd_none(x) (0)
#define pmd_huge(x) (0)
#define pmd_bad(x) (0)
#define pte_offset_map_lock(mm, pmd, addr, ptl) (NULL)
#define pte_present(x) (0)
#define pte_write(x) (0)
#define pte_dirty(x) (0)
#define pte_none(x) (0)
#define pte_unmap_unlock(pte, ptl) 
#define PageDirty(x) (0)
#define set_page_dirty(x) 
#define mark_page_accessed(x) 
#define get_page(x) 
#define ZERO_PAGE(x) (NULL)
#define ERR_PTR(x) (NULL)

struct page *follow_huge_addr(struct mm_struct *mm, unsigned long address, int write);
struct page *follow_huge_pmd(struct mm_struct *mm, unsigned long address, pmd_t *pmd, int write);
struct page *vm_normal_page(struct vm_area_struct *vma, unsigned long address, pte_t pte);