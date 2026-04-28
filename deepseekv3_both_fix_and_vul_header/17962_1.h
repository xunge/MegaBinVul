typedef unsigned long pmd_t;
typedef unsigned long pud_t;
typedef struct { unsigned long vm_mm; } vm_area_struct;
typedef struct { unsigned long bits[1]; } nodemask_t;

#define pmd_offset(pud, addr) ((pmd_t *)0)
#define pmd_addr_end(addr, end) (end)
#define split_huge_page_pmd(mm, pmd) do {} while (0)
#define pmd_none_or_clear_bad(pmd) (0)
#define check_pte_range(vma, pmd, addr, end, nodes, flags, private) (0)
#define EIO 5