#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

typedef unsigned long l3_pgentry_t;
typedef unsigned long l2_pgentry_t;
typedef unsigned long l1_pgentry_t;

#define SYS_STATE_boot 0
#define _PAGE_NX (1UL << 63)
#define _PAGE_DIRTY (1UL << 6)
#define _PAGE_ACCESSED (1UL << 5)
#define _PAGE_RW (1UL << 1)
#define _PAGE_PRESENT (1UL << 0)
#define _PAGE_PSE (1UL << 7)
#define __PAGE_HYPERVISOR (1UL << 2)

#define PAGE_SIZE 4096
#define L3_PAGETABLE_SHIFT 30
#define L2_PAGETABLE_SHIFT 21
#define L1_PAGETABLE_SHIFT 12
#define L2_PAGETABLE_ENTRIES 512
#define L1_PAGETABLE_ENTRIES 512
#define PAGETABLE_ORDER 9

#define IS_ALIGNED(x, a) (((x) & ((a) - 1)) == 0)
#define ASSERT(x) do { if (!(x)) { *(volatile int *)0 = 0; } } while (0)

extern int system_state;

typedef struct { int lock; } spinlock_t;
extern spinlock_t map_pgdir_lock;

static inline unsigned long l2_table_offset(unsigned long v) { return (v >> L2_PAGETABLE_SHIFT) & (L2_PAGETABLE_ENTRIES - 1); }
static inline unsigned long l1_table_offset(unsigned long v) { return (v >> L1_PAGETABLE_SHIFT) & (L1_PAGETABLE_ENTRIES - 1); }

static inline l3_pgentry_t *virt_to_xen_l3e(unsigned long v) { return NULL; }
static inline unsigned long l3e_get_flags(l3_pgentry_t l3e) { return l3e & ~((1UL << 12) - 1); }
static inline unsigned long l3e_get_pfn(l3_pgentry_t l3e) { return l3e >> 12; }
static inline l3_pgentry_t l3e_empty(void) { return 0; }
static inline l3_pgentry_t l3e_from_pfn(unsigned long pfn, unsigned long flags) { return (pfn << 12) | (flags & ((1UL << 12) - 1)); }
static inline l3_pgentry_t l3e_from_mfn(unsigned long mfn, unsigned long flags) { return (mfn << 12) | (flags & ((1UL << 12) - 1)); }
static inline void l3e_write_atomic(l3_pgentry_t *p, l3_pgentry_t l3e) { *p = l3e; }

static inline l2_pgentry_t *l3e_to_l2e(l3_pgentry_t l3e) { return (l2_pgentry_t *)(l3e & ~((1UL << 12) - 1)); }
static inline unsigned long l2e_get_flags(l2_pgentry_t l2e) { return l2e & ~((1UL << 12) - 1); }
static inline unsigned long l2e_get_pfn(l2_pgentry_t l2e) { return l2e >> 12; }
static inline l2_pgentry_t l2e_empty(void) { return 0; }
static inline l2_pgentry_t l2e_from_pfn(unsigned long pfn, unsigned long flags) { return (pfn << 12) | (flags & ((1UL << 12) - 1)); }
static inline l2_pgentry_t l2e_from_mfn(unsigned long mfn, unsigned long flags) { return (mfn << 12) | (flags & ((1UL << 12) - 1)); }
static inline void l2e_write(l2_pgentry_t *p, l2_pgentry_t l2e) { *p = l2e; }
static inline void l2e_write_atomic(l2_pgentry_t *p, l2_pgentry_t l2e) { *p = l2e; }

static inline l1_pgentry_t *l2e_to_l1e(l2_pgentry_t l2e) { return (l1_pgentry_t *)(l2e & ~((1UL << 12) - 1)); }
static inline unsigned long l1e_get_flags(l1_pgentry_t l1e) { return l1e & ~((1UL << 12) - 1); }
static inline unsigned long l1e_get_pfn(l1_pgentry_t l1e) { return l1e >> 12; }
static inline l1_pgentry_t l1e_empty(void) { return 0; }
static inline l1_pgentry_t l1e_from_pfn(unsigned long pfn, unsigned long flags) { return (pfn << 12) | (flags & ((1UL << 12) - 1)); }
static inline void l1e_write(l1_pgentry_t *p, l1_pgentry_t l1e) { *p = l1e; }
static inline void l1e_write_atomic(l1_pgentry_t *p, l1_pgentry_t l1e) { *p = l1e; }

static inline unsigned long l1e_get_intpte(l1_pgentry_t l1e) { return l1e; }
static inline unsigned long l2e_get_intpte(l2_pgentry_t l2e) { return l2e; }

static inline l2_pgentry_t *alloc_xen_l2_table(void) { return NULL; }
static inline l1_pgentry_t *alloc_xen_l1_table(void) { return NULL; }
static inline void free_xen_pagetable(void *p) {}
static inline unsigned long virt_to_mfn(void *v) { return 0; }
static inline void flush_area(void *v, unsigned int flags) {}

static inline void spin_lock(spinlock_t *lock) { lock->lock = 1; }
static inline void spin_unlock(spinlock_t *lock) { lock->lock = 0; }

#define FLUSH_TLB_GLOBAL 0