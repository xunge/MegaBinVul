#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

struct fq {
    struct list_head backlogs;
    int lock;
    uint32_t flows_cnt;
    uint32_t perturbation;
    uint32_t quantum;
    uint32_t limit;
    uint32_t memory_limit;
    void *flows;
};

#define max_t(type, x, y) ((x) > (y) ? (x) : (y))
#define INIT_LIST_HEAD(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define GFP_KERNEL 0
#define ENOMEM 12

static inline uint32_t prandom_u32(void) { return rand(); }
static inline void spin_lock_init(int *lock) { *lock = 0; }
static inline void fq_flow_init(void *flow) {}
static inline void *kcalloc(size_t n, size_t size, int flags) { return calloc(n, size); }