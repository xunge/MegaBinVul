#include <stdbool.h>
#include <stddef.h>

typedef unsigned long pfn_t;
typedef int bool_t;
typedef struct { } spinlock_t;

struct page_info {
    pfn_t mfn;
};

extern spinlock_t heap_lock;
extern void spin_lock(spinlock_t *);
extern void spin_unlock(spinlock_t *);

extern unsigned long first_valid_mfn;
extern bool avail[];
extern bool scrub_debug;

static inline pfn_t page_to_mfn(struct page_info *pg) { return pg->mfn; }
static inline unsigned long page_to_maddr(struct page_info *pg) { return (unsigned long)pg; }
extern unsigned long phys_to_nid(unsigned long);
extern unsigned long pfn_to_paddr(pfn_t);
extern unsigned long find_first_set_bit(unsigned long);
extern unsigned long init_node_heap(unsigned int, pfn_t, unsigned long, bool_t *);
extern void free_heap_pages(struct page_info *, int, bool);

#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))
#define unlikely(x) (x)
#define BUG_ON(condition) do { if (condition) {} } while (0)
#define MAX_ORDER 10