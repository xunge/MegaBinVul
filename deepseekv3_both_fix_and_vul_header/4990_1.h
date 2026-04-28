#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define XEN_GUEST_HANDLE_64(type) uint64_t
#define EINVAL 22
#define ENOMEM 12
#define ENODATA 61
#define EFAULT 14
#define XENLOG_INFO 0
#define INVALID_MFN (~0UL)
#define INVALID_PADDR (~0UL)
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define SECONDS(n) (n)
#define NOW() (0)
#define PGT_count_mask 0xFF
#define _PAGE_DIRTY (1<<1)
#define _PAGE_ACCESSED (1<<0)

typedef unsigned long mfn_t;
typedef uint64_t paddr_t;
typedef uint8_t p2m_type_t;
typedef uint64_t l1_pgentry_t;

struct domain {
    struct {
        struct {
            struct sh_dirty_vram *dirty_vram;
        } hvm_domain;
    } arch;
    unsigned long domain_dirty_cpumask;
    void **vcpu;
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

static inline mfn_t _mfn(unsigned long mfn) { return (mfn_t){ mfn }; }
static inline unsigned long mfn_x(mfn_t mfn) { return mfn; }
static inline unsigned long paddr_to_pfn(paddr_t pa) { return pa >> 12; }

#define gdprintk(level, fmt, ...) 
#define xmalloc(type) malloc(sizeof(type))
#define xmalloc_array(type, num) malloc(sizeof(type) * (num))
#define xzalloc_array(type, num) calloc((num), sizeof(type))
#define xfree(ptr) free(ptr)
#define copy_to_guest(dest, src, size) 0

void p2m_lock(struct p2m_domain *p2m);
void p2m_unlock(struct p2m_domain *p2m);
struct p2m_domain *p2m_get_hostp2m(struct domain *d);
void paging_lock(struct domain *d);
void paging_unlock(struct domain *d);
void shadow_blow_tables(struct domain *d);
int sh_remove_all_mappings(void *vcpu, mfn_t mfn);
int sh_remove_write_access(void *vcpu, mfn_t mfn, int write, int lock);
void flush_tlb_mask(unsigned long mask);
void *sh_map_domain_page(mfn_t mfn);
void sh_unmap_domain_page(void *ptr);
mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long pfn, p2m_type_t *t);
struct page_info *mfn_to_page(mfn_t mfn);

static inline void l1e_remove_flags(l1_pgentry_t *l1e, unsigned long flags) {
    *l1e &= ~flags;
}
static inline unsigned long l1e_get_flags(l1_pgentry_t l1e) {
    return l1e;
}