#include <stdint.h>
#include <stdio.h>

typedef uint64_t mfn_t;
typedef unsigned int SH_type;

struct domain {
    int domain_id;
    void *dirty_cpumask;
};

struct page_info {
    uint32_t count_info;
    uint32_t shadow_flags;
};

typedef void (*hash_domain_callback_t)(struct domain *, mfn_t);

#define SH_type_unused 16
#define SH_type_l2_32_shadow 3
#define SH_type_l1_32_shadow 1
#define SH_type_l2h_pae_shadow 7
#define SH_type_l2_pae_shadow 6
#define SH_type_l1_pae_shadow 4
#define SH_type_l4_64_shadow 13
#define SH_type_l3_64_shadow 12
#define SH_type_l2h_64_shadow 10
#define SH_type_l2_64_shadow 9
#define SH_type_l1_64_shadow 8

#define SHF_L2_32    (1U << SH_type_l2_32_shadow)
#define SHF_L2H_PAE  (1U << SH_type_l2h_pae_shadow)
#define SHF_L2_PAE   (1U << SH_type_l2_pae_shadow)
#define SHF_L2H_64   (1U << SH_type_l2h_64_shadow)
#define SHF_L2_64    (1U << SH_type_l2_64_shadow)
#define SHF_L3_64    (1U << SH_type_l3_64_shadow)
#define SHF_L4_64    (1U << SH_type_l4_64_shadow)

#define PGC_page_table (1U << 8)
#define XENLOG_G_ERR ""

#define SHADOW_INTERNAL_NAME(func, level) NULL
#define SHADOW_PRINTK(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define PRI_mfn "lx"
#define mfn_x(mfn) (mfn)
#define ASSERT(cond) ((void)0)
#define unlikely(cond) (cond)

static const char shadow_unshadow[] = "shadow_unshadow";

static inline struct page_info *mfn_to_page(mfn_t mfn) { return NULL; }
static inline int mfn_valid(mfn_t mfn) { return 1; }
static void paging_lock_recursive(struct domain *d) {}
static void paging_unlock(struct domain *d) {}
static mfn_t shadow_hash_lookup(struct domain *d, unsigned long gmfn, unsigned char type) { return 0; }
static int sh_type_is_pinnable(struct domain *d, unsigned char type) { return 0; }
static void sh_unpin(struct domain *d, mfn_t smfn) {}
static int sh_type_has_up_pointer(struct domain *d, unsigned char type) { return 0; }
static void sh_remove_shadow_via_pointer(struct domain *d, mfn_t smfn) {}
static void hash_domain_foreach(struct domain *d, unsigned int mask, const hash_domain_callback_t *callbacks, mfn_t smfn) {}
static void domain_crash(struct domain *d) {}
static void flush_tlb_mask(const void *mask) {}
static void perfc_incr(const char *name) {}
static void printk(const char *fmt, ...) {}

static void sh_remove_l1_shadow_2(struct domain *d, mfn_t smfn) {}
static void sh_remove_l1_shadow_3(struct domain *d, mfn_t smfn) {}
static void sh_remove_l1_shadow_4(struct domain *d, mfn_t smfn) {}
static void sh_remove_l2_shadow_4(struct domain *d, mfn_t smfn) {}
static void sh_remove_l3_shadow_4(struct domain *d, mfn_t smfn) {}