#include <stdbool.h>
#include <stddef.h>

typedef unsigned long mfn_t;
typedef unsigned long pfn_t;

#define mfn_x(mfn) ((unsigned long)(mfn))
#define mfn_eq(a, b) ((a) == (b))
#define mfn_add(mfn, n) ((mfn_t)(mfn_x(mfn) + (n)))

#define INVALID_MFN ((mfn_t)-1)

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGETABLE_ORDER 9
#define L1_PAGETABLE_SHIFT (PAGE_SHIFT)
#define L2_PAGETABLE_SHIFT (L1_PAGETABLE_SHIFT + PAGETABLE_ORDER)
#define L3_PAGETABLE_SHIFT (L2_PAGETABLE_SHIFT + PAGETABLE_ORDER)

#define L1_PAGETABLE_ENTRIES (1UL << PAGETABLE_ORDER)
#define L2_PAGETABLE_ENTRIES (1UL << PAGETABLE_ORDER)
#define L3_PAGETABLE_ENTRIES (1UL << PAGETABLE_ORDER)

#define _PAGE_PRESENT    (1U<<0)
#define _PAGE_RW         (1U<<1)
#define _PAGE_USER       (1U<<2)
#define _PAGE_PWT        (1U<<3)
#define _PAGE_PCD        (1U<<4)
#define _PAGE_ACCESSED   (1U<<5)
#define _PAGE_DIRTY      (1U<<6)
#define _PAGE_PSE        (1U<<7)
#define _PAGE_GLOBAL     (1U<<8)
#define _PAGE_PAT        (1U<<12)

#define PAGE_CACHE_ATTRS (_PAGE_PWT | _PAGE_PCD | _PAGE_PAT)
#define __PAGE_HYPERVISOR (_PAGE_PRESENT | _PAGE_RW)
#define PAGE_HYPERVISOR __PAGE_HYPERVISOR

#define MAP_SMALL_PAGES  (1U<<16)

#define FLUSH_TLB         (1U<<0)
#define FLUSH_TLB_GLOBAL  (1U<<1)
#define FLUSH_CACHE       (1U<<2)
#define FLUSH_VA_VALID    (1U<<3)
#define FLUSH_ORDER(n)    ((n)<<8)

#define SYS_STATE_boot 0
#define DIRECTMAP_VIRT_START 0
#define HYPERVISOR_VIRT_END 0

#define ENOMEM 12

typedef struct { unsigned long val; } l1_pgentry_t;
typedef struct { unsigned long val; } l2_pgentry_t;
typedef struct { unsigned long val; } l3_pgentry_t;

struct spinlock {
    int lock;
};
typedef struct spinlock spinlock_t;

#define spin_lock(lock) do { (void)(lock); } while (0)
#define spin_unlock(lock) do { (void)(lock); } while (0)

#define l1e_get_pfn(l1e) ((l1e).val >> PAGE_SHIFT)
#define l1e_get_flags(l1e) ((l1e).val & ((1UL << PAGE_SHIFT) - 1))
#define l1e_from_pfn(pfn, flags) ((l1_pgentry_t) { ((pfn) << PAGE_SHIFT) | (flags) })
#define l1e_from_mfn(mfn, flags) l1e_from_pfn(mfn_x(mfn), flags)
#define l1e_write(ptr, val) (*(ptr) = (val))
#define l1e_write_atomic(ptr, val) l1e_write(ptr, val)

#define l2e_get_pfn(l2e) ((l2e).val >> PAGE_SHIFT)
#define l2e_get_flags(l2e) ((l2e).val & ((1UL << PAGE_SHIFT) - 1))
#define l2e_from_pfn(pfn, flags) ((l2_pgentry_t) { ((pfn) << PAGE_SHIFT) | (flags) })
#define l2e_from_mfn(mfn, flags) l2e_from_pfn(mfn_x(mfn), flags)
#define l2e_write(ptr, val) (*(ptr) = (val))
#define l2e_write_atomic(ptr, val) l2e_write(ptr, val)

#define l3e_get_pfn(l3e) ((l3e).val >> PAGE_SHIFT)
#define l3e_get_flags(l3e) ((l3e).val & ((1UL << PAGE_SHIFT) - 1))
#define l3e_from_pfn(pfn, flags) ((l3_pgentry_t) { ((pfn) << PAGE_SHIFT) | (flags) })
#define l3e_from_mfn(mfn, flags) l3e_from_pfn(mfn_x(mfn), flags)
#define l3e_write_atomic(ptr, val) (*(ptr) = (val))

#define l1f_to_lNf(flags) (flags)
#define lNf_to_l1f(flags) (flags)

#define virt_to_xen_l3e(virt) NULL
#define virt_to_xen_l2e(virt) NULL
#define virt_to_xen_l1e(virt) NULL
#define virt_to_mfn(virt) INVALID_MFN

#define l2_table_offset(virt) (((virt) >> L2_PAGETABLE_SHIFT) & (L2_PAGETABLE_ENTRIES - 1))
#define l1_table_offset(virt) (((virt) >> L1_PAGETABLE_SHIFT) & (L1_PAGETABLE_ENTRIES - 1))

#define l2e_to_l1e(l2e) ((l1_pgentry_t *)(l2e).val)
#define l3e_to_l2e(l3e) ((l2_pgentry_t *)(l3e).val)

extern int system_state;
extern bool cpu_has_page1gb;
extern spinlock_t map_pgdir_lock;

static inline void *alloc_xen_pagetable(void) { return NULL; }
static inline void free_xen_pagetable(void *p) {}
static inline void flush_area(unsigned long virt, unsigned int flags) {}