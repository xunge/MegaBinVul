#include <stddef.h>
#include <assert.h>

typedef struct {
    unsigned long x;
} gfn_t;

typedef struct lpae_t {
    unsigned long entry;
} lpae_t;

struct p2m_domain {
    lpae_t *root;
};

#define gfn_x(gfn) ((gfn).x)
#define P2M_ROOT_LEVEL 1
#define P2M_ROOT_PAGES 1
#define LPAE_SHIFT 9
#define LPAE_ENTRY_MASK 0x1FF
#define ASSERT(x) assert(x)

unsigned int level_orders[] = {12, 21, 30};
lpae_t *__map_domain_page(void *page);