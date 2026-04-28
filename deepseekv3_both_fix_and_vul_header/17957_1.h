typedef unsigned long pmd_t;
typedef unsigned long pud_t;
typedef struct vm_area_struct vm_area_struct;
typedef struct page page;
typedef unsigned long swp_entry_t;

#define pmd_offset(pud, addr) ((pmd_t *)0)
#define pmd_addr_end(addr, end) (end)
#define pmd_trans_huge(pmd) (0)
#define pmd_none_or_clear_bad(pmd) (0)
#define unlikely(x) (x)

extern int unuse_pte_range(struct vm_area_struct *vma, pmd_t *pmd,
                          unsigned long addr, unsigned long end,
                          swp_entry_t entry, struct page *page);