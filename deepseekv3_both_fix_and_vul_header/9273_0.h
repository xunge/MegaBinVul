#include <stddef.h>

struct vcpu;
struct paging_mode {
    int (*invlpg)(struct vcpu *, unsigned long);
};

static inline struct paging_mode *paging_get_hostmode(struct vcpu *v);