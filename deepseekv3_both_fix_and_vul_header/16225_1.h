#include <stdbool.h>
#include <stddef.h>

typedef struct { int lock; } spinlock_t;
typedef unsigned long l3_pgentry_t;
typedef unsigned long l2_pgentry_t;
typedef unsigned long l1_pgentry_t;

#define PAGE_SIZE 4096
#define _PAGE_NX (1UL << 63)
#define _PAGE_DIRTY (1UL << 6)
#define _PAGE_ACCESSED (1UL << 5)
#define _PAGE_RW (1UL << 1)
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_PSE (1UL << 7)
#define __PAGE_HYPERVISOR (1UL << 8)

#define L3_PAGETABLE_SHIFT 30
#define L2_PAGETABLE_SHIFT 21
#define L1_PAGETABLE_ENTRIES 512
#define L2_PAGETABLE_ENTRIES 512
#define PAGETABLE_ORDER 9
#define FLUSH_TLB_GLOBAL 1

#define IS_ALIGNED(x, a) (((x) & ((a) - 1)) == 0)
#define ASSERT(x) ((void)0)

#define l3e_get_flags(x) ((x) & ~((1UL << 12) - 1))
#define l3e_get_pfn(x) ((x) >> 12)
#define l3e_empty() (0UL)
#define l3e_from_pfn(pfn, flags) (((pfn) << 12) | (flags))
#define l3e_from_mfn(mfn, flags) (((mfn) << 12) | (flags))
#define l3e_write_atomic(ptr, val) (*(ptr) = (val))
#define l3e_to_l2e(x) ((l2_pgentry_t *)((x) & ~((1UL << 12) - 1)))

#define l2e_get_flags(x) ((x) & ~((1UL << 12) - 1))
#define l2e_get_pfn(x) ((x) >> 12)
#define l2e_empty() (0UL)
#define l2e_from_pfn(pfn, flags) (((pfn) << 12) | (flags))
#define l2e_from_mfn(mfn, flags) (((mfn) << 12) | (flags))
#define l2e_write(ptr, val) (*(ptr) = (val))
#define l2e_write_atomic(ptr, val) (*(ptr) = (val))
#define l2e_to_l1e(x) ((l1_pgentry_t *)((x) & ~((1UL << 12) - 1)))
#define l2e_get_intpte(x) (x)

#define l1e_get_flags(x) ((x) & ~((1UL << 12) - 1))
#define l1e_get_pfn(x) ((x) >> 12)
#define l1e_empty() (0UL)
#define l1e_from_pfn(pfn, flags) (((pfn) << 12) | (flags))
#define l1e_write(ptr, val) (*(ptr) = (val))
#define l1e_write_atomic(ptr, val) (*(ptr) = (val))
#define l1e_get_intpte(x) (x)

#define l2_table_offset(v) (((v) >> L2_PAGETABLE_SHIFT) & (L2_PAGETABLE_ENTRIES - 1))
#define l1_table_offset(v) (((v) >> 12) & (L1_PAGETABLE_ENTRIES - 1))

enum system_state {
    SYS_STATE_boot,
    SYS_STATE_smp,
    SYS_STATE_active
};
extern enum system_state system_state;

extern spinlock_t map_pgdir_lock;

#define ENOMEM 12

static inline void spin_lock(spinlock_t *lock) { (void)lock; }
static inline void spin_unlock(spinlock_t *lock) { (void)lock; }

static inline l2_pgentry_t *alloc_xen_pagetable(void) { return NULL; }
static inline void free_xen_pagetable(void *p) {}
static inline l3_pgentry_t *virt_to_xen_l3e(unsigned long v) { return NULL; }
static inline unsigned long virt_to_mfn(void *v) { return 0; }
static inline void flush_area(void *v, unsigned int flags) {}