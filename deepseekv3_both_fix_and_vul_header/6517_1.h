#include <stdint.h>
#include <stddef.h>

typedef uint64_t mfn_t;
typedef struct pagetable *pagetable_t;
typedef struct vcpu vcpu_t;
typedef struct domain domain_t;
typedef struct page page_t;

#define mfn_valid(mfn) ((mfn) != 0)
#define mfn_x(mfn) (mfn)
#define PRI_mfn "lx"
#define GUEST_PAGING_LEVELS 4
#define SHADOW_PAGING_LEVELS 4
#define SHADOW_ERROR(fmt, ...)
#define SHADOW_PRINTK(fmt, ...)
#define ASSERT(cond)

struct vcpu {
    struct domain *domain;
    struct {
        pagetable_t *shadow_table;
    } arch;
};

struct domain {
    // domain fields
};

struct page {
    struct {
        struct {
            unsigned int pinned;
        } sh;
    } u;
};

static pagetable_t pagetable_null(void) { return NULL; }
static pagetable_t pagetable_from_mfn(mfn_t mfn) { return (pagetable_t)(uintptr_t)mfn; }
static mfn_t pagetable_get_mfn(pagetable_t pt) { return (mfn_t)(uintptr_t)pt; }
static int pagetable_is_null(pagetable_t pt) { return pt == NULL; }
static struct page *mfn_to_page(mfn_t mfn) { return (struct page *)(uintptr_t)mfn; }

static mfn_t get_shadow_status(struct domain *d, mfn_t gmfn, unsigned int root_type) { return 0; }
static void shadow_prealloc(struct domain *d, unsigned int root_type, int count) {}
static mfn_t sh_make_shadow(struct vcpu *v, mfn_t gmfn, unsigned int root_type) { return 0; }
static int sh_pin(struct domain *d, mfn_t smfn) { return 1; }
static int sh_get_ref(struct domain *d, mfn_t smfn, int flags) { return 1; }
static void sh_put_ref(struct domain *d, mfn_t smfn, int flags) {}
static void domain_crash(struct domain *d) {}