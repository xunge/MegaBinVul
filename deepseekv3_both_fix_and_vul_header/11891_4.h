#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

typedef uint64_t paddr_t;
typedef struct { uint64_t val; } mfn_t;
typedef struct { uint64_t val; } gfn_t;

#define INVALID_MFN ((mfn_t){0})
#define PRIpaddr "lx"
#define PAGE_SHIFT 12
#define PAGE_MASK (~((1UL << PAGE_SHIFT)-1))
#define XENLOG_DEBUG ""
#define SHF_pagetable_dying (1U << 0)

struct vcpu {
    struct domain *domain;
    struct {
        struct {
            paddr_t guest_cr[8];
        } hvm;
        struct {
            struct {
                int pagetable_dying;
            } shadow;
        } paging;
        mfn_t shadow_table[4];
    } arch;
};

struct domain {
    struct {
        struct {
            struct {
                int pagetable_dying_op;
            } shadow;
        } paging;
    } arch;
    unsigned long dirty_cpumask;
    bool is_hvm;
};

struct page_info {
    union {
        struct {
            uint64_t back;
        } sh;
    } v;
    bool pagetable_dying;
    unsigned int shadow_flags;
};

typedef enum {
    SH_type_l2_pae_shadow,
    p2m_ram,
} p2m_type_t;
typedef uint64_t guest_l3e_t;

extern struct vcpu *current;

#define _gfn(x) ((gfn_t){x})
#define _mfn(x) ((mfn_t){x})
#define gfn_x(x) ((x).val)
#define mfn_x(x) ((x).val)
#define mfn_eq(x, y) ((x).val == (y).val)
#define unlikely(x) (x)
#define mfn_valid(x) ((x).val != 0)

static inline bool is_hvm_domain(struct domain *d) { return d->is_hvm; }
static inline gfn_t guest_l3e_get_gfn(guest_l3e_t l3e) { return _gfn(l3e >> PAGE_SHIFT); }
static inline bool p2m_is_ram(p2m_type_t t) { return t == p2m_ram; }
static inline bool pagetable_is_null(mfn_t mfn) { return mfn_eq(mfn, INVALID_MFN); }
static inline mfn_t pagetable_get_mfn(mfn_t mfn) { return mfn; }
static inline mfn_t shadow_hash_lookup(struct domain *d, unsigned long mfn, p2m_type_t type) { return INVALID_MFN; }
static inline void shadow_unhook_mappings(struct domain *d, mfn_t smfn, int count) {}
static inline void flush_tlb_mask(unsigned long mask) {}
static inline void paging_lock(struct domain *d) {}
static inline void paging_unlock(struct domain *d) {}
static inline char *map_domain_page(mfn_t mfn) { return NULL; }
static inline void unmap_domain_page(char *ptr) {}
static inline mfn_t get_gfn_query(struct domain *d, gfn_t gfn, p2m_type_t *t) { return INVALID_MFN; }
static inline mfn_t get_gfn_query_unlocked(struct domain *d, unsigned long gfn, p2m_type_t *t) { return INVALID_MFN; }
static inline void put_gfn(struct domain *d, unsigned long gfn) {}
static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }

static inline int printk(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}