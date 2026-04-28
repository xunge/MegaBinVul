#include <stdint.h>

#define PAGE_SHIFT 12
#define PAGE_MASK (~((1UL << PAGE_SHIFT) - 1))
#define _PAGE_PRESENT (1UL << 0)
#define SHADOW_SET_ERROR (-1)
#define SHADOW_SET_CHANGED (1 << 0)
#define SHADOW_SET_FLUSH (1 << 1)
#define SH_type_l3_64_shadow 0

typedef uint64_t paddr_t;
typedef struct { uint64_t l4; } shadow_l4e_t;
typedef unsigned long mfn_t;
typedef struct domain domain_t;

#define mfn_x(mfn) (mfn)
#define ASSERT(cond) ((void)0)

static int sh_get_ref(struct domain *d, mfn_t mfn, paddr_t paddr) { return 0; }
static int sh_pin(struct domain *d, mfn_t mfn) { return 0; }
static void domain_crash(struct domain *d) {}
static void shadow_write_entries(shadow_l4e_t *dst, shadow_l4e_t *src, int count, mfn_t mfn) {}
static unsigned long shadow_l4e_get_flags(shadow_l4e_t sl4e) { return 0; }
static mfn_t shadow_l4e_get_mfn(shadow_l4e_t sl4e) { return 0; }
static int sh_type_is_pinnable(struct domain *d, int type) { return 0; }
static int perms_strictly_increased(unsigned long old_flags, unsigned long new_flags) { return 0; }
static void sh_put_ref(struct domain *d, mfn_t mfn, paddr_t paddr) {}