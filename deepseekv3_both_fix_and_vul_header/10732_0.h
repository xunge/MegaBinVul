#include <stdint.h>
#include <stddef.h>

#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define _PAGE_PRESENT (1U << 0)

#define SHADOW_OPTIMIZATIONS 0
#define SHOPT_SKIP_VERIFY 0

#define SHF_32 (1U << 0)
#define SHF_PAE (1U << 1)
#define SHF_64 (1U << 2)

#define unlikely(x) (x)
#define likely(x) (x)
#define ASSERT(x) ((void)0)

struct page {
    uint32_t shadow_flags;
};

struct domain {
    struct {
        struct {
            struct {
                int gtable_dirty_version;
            } shadow;
        } paging;
    } arch;
};

struct vcpu {
    struct domain *domain;
};

struct sh_emulate_ctxt {
    unsigned long mfn[2];
    int low_bit_was_clear;
};

typedef uint32_t u32;
typedef uint8_t u8;

static inline struct page *mfn_to_page(unsigned long mfn) { return NULL; }
static inline int mfn_valid(unsigned long mfn) { return 0; }
static inline void sh_validate_guest_pt_write(struct vcpu *v, unsigned long mfn, void *addr, unsigned int bytes) {}
static inline void paging_mark_dirty(struct domain *d, unsigned long mfn) {}
static inline void vunmap(void *addr) {}
static inline void unmap_domain_page(void *addr) {}
static inline void atomic_inc(int *counter) {}