#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define PAGE_SIZE 4096
#define EINVAL 22
#define ENOMEM 12

typedef struct {
    uint64_t val;
} mfn_t;

struct vcpu_info {
#ifdef CONFIG_COMPAT
    struct {
        uint32_t evtchn_pending_sel;
    } compat;
#endif
    struct {
        uint64_t evtchn_pending_sel;
        uint8_t evtchn_upcall_mask;
    } native;
};

typedef struct vcpu_info vcpu_info_t;

struct domain {
    int dummy;
};

struct page_info {
    int dummy;
};

struct vcpu {
    struct domain *domain;
    mfn_t vcpu_info_mfn;
    vcpu_info_t *vcpu_info;
    unsigned int pause_flags;
};

#define INVALID_MFN ((mfn_t){0})
#define P2M_ALLOC 0
#define PGT_writable_page 0
#define VPF_down 0

extern struct vcpu *current;
extern vcpu_info_t dummy_vcpu_info;

#define mfn_eq(a, b) ((a).val == (b).val)
#define page_to_mfn(p) ((mfn_t){0})
#define smp_wmb() __asm__ __volatile__("": : :"memory")

#define __alignof__(type) offsetof(struct { char c; type member; }, member)

static inline int has_32bit_shinfo(struct domain *d) { return 0; }
static inline struct page_info *get_page_from_gfn(struct domain *d, unsigned long gfn, void *null, int flags) { return NULL; }
static inline int get_page_type(struct page_info *page, int type) { return 0; }
static inline void put_page(struct page_info *page) {}
static inline void put_page_and_type(struct page_info *page) {}
static inline void *__map_domain_page_global(struct page_info *page) { return NULL; }
static inline void vcpu_mark_events_pending(struct vcpu *v) {}
static inline void write_atomic(uint64_t *addr, uint64_t val) { *addr = val; }

#define vcpu_info(v, field) ((v)->vcpu_info->native.field)
#define __vcpu_info(v, info, field) ((info)->native.field)