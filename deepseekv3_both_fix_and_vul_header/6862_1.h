#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long paddr_t;
typedef unsigned long mfn_t;
typedef unsigned long p2m_type_t;

#define INVALID_MFN ((mfn_t)-1)
#define INVALID_PADDR ((paddr_t)-1)
#define PAGE_MASK (~0UL << 12)
#define _PAGE_DIRTY (1UL << 1)
#define _PAGE_ACCESSED (1UL << 2)
#define PGT_count_mask 0x7f
#define SECONDS(n) (n)
#define NOW() (0)
#define XENLOG_INFO 0
#define EINVAL 1
#define ENOMEM 2
#define ENODATA 3
#define EFAULT 4

#define XEN_GUEST_HANDLE(type) void*

struct domain {
    struct {
        struct {
            struct sh_dirty_vram *dirty_vram;
        } hvm;
    } arch;
    void *dirty_cpumask;
};

struct p2m_domain {
    unsigned long max_mapped_pfn;
};

struct sh_dirty_vram {
    unsigned long begin_pfn;
    unsigned long end_pfn;
    paddr_t *sl1ma;
    uint8_t *dirty_bitmap;
    long last_dirty;
};

struct page_info {
    struct {
        struct {
            uint32_t type_info;
        } inuse;
    } u;
};

typedef uint64_t l1_pgentry_t;

static inline int mfn_eq(mfn_t a, mfn_t b) { return a == b; }
static inline unsigned long _gfn(unsigned long pfn) { return pfn; }
static inline int l1e_get_flags(l1_pgentry_t l1e) { return 0; }
static inline void l1e_remove_flags(l1_pgentry_t l1e, int flags) {}

#define gdprintk(level, fmt, ...)
#define xmalloc(type) malloc(sizeof(type))
#define xmalloc_array(type, count) malloc(sizeof(type) * (count))
#define xzalloc_array(type, count) calloc((count), sizeof(type))
#define xfree(ptr) free(ptr)
#define vzalloc(size) calloc(1, size)
#define vfree(ptr) free(ptr)

static inline mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long pfn, p2m_type_t *t) { return INVALID_MFN; }
static inline int sh_remove_all_mappings(struct domain *d, mfn_t mfn, unsigned long gfn) { return 0; }
static inline int sh_remove_write_access(struct domain *d, mfn_t mfn, int write, int lock) { return 0; }
static inline void guest_flush_tlb_mask(struct domain *d, void *mask) {}
static inline void shadow_blow_tables(struct domain *d) {}
static inline void paging_lock(struct domain *d) {}
static inline void paging_unlock(struct domain *d) {}
static inline struct p2m_domain *p2m_get_hostp2m(struct domain *d) { return NULL; }
static inline void p2m_lock(struct p2m_domain *p2m) {}
static inline void p2m_unlock(struct p2m_domain *p2m) {}
static inline void *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(void *ptr) {}
static inline mfn_t maddr_to_mfn(paddr_t pa) { return INVALID_MFN; }
static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline int copy_to_guest(XEN_GUEST_HANDLE(void) guest, void *src, unsigned long size) { return 0; }