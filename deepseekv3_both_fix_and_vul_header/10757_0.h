#include <stdint.h>

#define __must_check
#define EINVAL 22

struct domain;
static inline int is_domain_direct_mapped(struct domain *d) { return 0; }
static inline unsigned long _gfn(unsigned long gfn) { return gfn; }
static inline unsigned long _mfn(unsigned long gfn) { return gfn; }
static inline int guest_physmap_remove_page(struct domain *d, unsigned long gfn1, unsigned long gfn2, int flags) { return 0; }