#include <stdint.h>

typedef uint64_t gfn_t;
typedef uint64_t mfn_t;

struct domain;
int p2m_remove_mapping(struct domain *d, gfn_t gfn, unsigned long nr, mfn_t mfn);