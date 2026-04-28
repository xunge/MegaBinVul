#include <stdint.h>

#define _mfn(x) (x)
#define map_domain_page(x) ((uint64_t *)(x))
#define unmap_domain_page(x) 
#define pfn_to_pde_idx(x, y) (x)

typedef uint64_t u64;