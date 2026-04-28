#include <stdint.h>
#include <string.h>
#include <assert.h>

#define GUEST_PAGING_LEVELS 4
#define PAGE_SHIFT 12
#define INVALID_MFN (~0ULL)
#define _PAGE_PRESENT (1ULL<<0)
#define _PAGE_USER (1ULL<<2)
#define _PAGE_RW (1ULL<<1)
#define _PAGE_ACCESSED (1ULL<<5)
#define _PAGE_DIRTY (1ULL<<6)
#define _PAGE_PAT (1ULL<<7)
#define _PAGE_PWT (1ULL<<3)
#define _PAGE_PCD (1ULL<<4)
#define _PAGE_NX_BIT (1ULL<<63)
#define _PAGE_INVALID_BITS (1ULL<<9)
#define _PAGE_PSE (1ULL<<7)
#define _PAGE_PKEY_BITS (1ULL<<59)
#define PFEC_user_mode (1U<<2)
#define PFEC_insn_fetch (1U<<4)
#define PFEC_write_access (1U<<1)
#define SMAP_CHECK_HONOR_CPL_AC 1
#define SMAP_CHECK_ENABLED 2
#define SMAP_CHECK_DISABLED 0
#define X86_EFLAGS_AC (1U<<18)
#define x86_seg_ss 0

typedef uint32_t bool_t;
typedef uint64_t mfn_t;
typedef uint64_t gfn_t;
typedef uint32_t p2m_type_t;
typedef uint32_t p2m_query_t;

typedef uint64_t guest_l1e_t;
typedef uint64_t guest_l2e_t;
typedef uint64_t guest_l3e_t;
typedef uint64_t guest_l4e_t;

typedef struct walk_t {
    unsigned long va;
    mfn_t l4mfn;
    mfn_t l3mfn;
    mfn_t l2mfn;
    mfn_t l1mfn;
    guest_l4e_t l4e;
    guest_l3e_t l3e;
    guest_l2e_t l2e;
    guest_l1e_t l1e;
} walk_t;

struct vcpu {
    struct domain *domain;
    struct {
        int smap_check_policy;
    } arch;
};

struct domain {
    struct {
        struct {
            unsigned int gfn_bits;
        } paging;
    } arch;
};

struct p2m_domain;

struct segment_register {
    struct {
        struct {
            unsigned int dpl;
        } fields;
    } attr;
};

struct cpu_user_regs {
    uint32_t eflags;
};

#define P2M_ALLOC (1U<<0)
#define P2M_UNSHARE (1U<<1)

static uint32_t guest_walk = 0;

static inline uint32_t gfn_x(gfn_t gfn) { return gfn; }
static inline gfn_t _gfn(uint32_t gfn) { return gfn; }
static inline uint32_t mfn_x(mfn_t mfn) { return mfn; }
static inline mfn_t _mfn(uint32_t mfn) { return mfn; }

#define guest_l1_table_offset(va) (((va)>>12)&0x1ff)
#define guest_l2_table_offset(va) (((va)>>21)&0x1ff)
#define guest_l3_table_offset(va) (((va)>>30)&0x1ff)
#define guest_l4_table_offset(va) (((va)>>39)&0x1ff)

#define GUEST_L2_GFN_MASK 0x1ff
#define GUEST_L3_GFN_MASK 0x1ff

static inline uint64_t guest_l1e_get_flags(guest_l1e_t l1e) { return l1e; }
static inline uint64_t guest_l2e_get_flags(guest_l2e_t l2e) { return l2e; }
static inline uint64_t guest_l3e_get_flags(guest_l3e_t l3e) { return l3e; }
static inline uint64_t guest_l4e_get_flags(guest_l4e_t l4e) { return l4e; }

static inline gfn_t guest_l1e_get_gfn(guest_l1e_t l1e) { return l1e >> 12; }
static inline gfn_t guest_l2e_get_gfn(guest_l2e_t l2e) { return l2e >> 12; }
static inline gfn_t guest_l3e_get_gfn(guest_l3e_t l3e) { return l3e >> 12; }
static inline gfn_t guest_l4e_get_gfn(guest_l4e_t l4e) { return l4e >> 12; }

static inline unsigned int guest_l1e_get_pkey(guest_l1e_t l1e) { return 0; }
static inline unsigned int guest_l2e_get_pkey(guest_l2e_t l2e) { return 0; }
static inline unsigned int guest_l3e_get_pkey(guest_l3e_t l3e) { return 0; }

static inline guest_l1e_t guest_l1e_from_gfn(gfn_t gfn, int flags) { return (gfn << 12) | flags; }

static inline bool_t is_hvm_domain(struct domain *d) { return 0; }
static inline bool_t hvm_smep_enabled(struct vcpu *v) { return 0; }
static inline bool_t hvm_smap_enabled(struct vcpu *v) { return 0; }
static inline bool_t guest_supports_1G_superpages(struct vcpu *v) { return 0; }
static inline bool_t guest_supports_superpages(struct vcpu *v) { return 0; }
static inline bool_t pkey_fault(struct vcpu *v, uint32_t pfec, uint32_t gflags, unsigned int pkey) { return 0; }
static inline bool_t set_ad_bits(void *entry, void *gw_entry, bool_t write) { return 0; }

static inline uint32_t mandatory_flags(struct vcpu *v, uint32_t pfec) { return 0; }
static inline void perfc_incr(uint32_t counter) {}
static inline void paging_mark_dirty(struct domain *d, uint32_t mfn) {}
static inline void hvm_get_segment_register(struct vcpu *v, int seg, struct segment_register *reg) {}
static inline const struct cpu_user_regs *guest_cpu_user_regs(void) { return NULL; }

static inline void *map_domain_gfn(struct p2m_domain *p2m, gfn_t gfn, mfn_t *mfn, p2m_type_t *p2mt, p2m_query_t qt, uint32_t *rc) { return NULL; }
static inline void unmap_domain_page(void *ptr) {}
static inline void put_page(void *page) {}
static inline void *mfn_to_page(uint32_t mfn) { return NULL; }
#define ASSERT(x) assert(x)