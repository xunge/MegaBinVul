#include <stdint.h>
#include <stddef.h>

#define likely(x) (x)
#define MAPTRACK_TAIL (-1)
#define PAGE_SIZE 4096
#define MAPTRACK_PER_PAGE (PAGE_SIZE / sizeof(struct grant_mapping))
#define max_maptrack_frames 1024

typedef int32_t grant_handle_t;

struct vcpu {
    grant_handle_t maptrack_head;
    grant_handle_t maptrack_tail;
    int vcpu_id;
};

struct grant_mapping {
    grant_handle_t ref;
    int vcpu;
};

struct grant_table {
    grant_handle_t maptrack_limit;
    struct grant_mapping **maptrack;
    int maptrack_lock;
};

extern struct vcpu *current;

static inline int nr_maptrack_frames(struct grant_table *lgt) { return 0; }
static inline grant_handle_t __get_maptrack_handle(struct grant_table *lgt, struct vcpu *curr) { return 0; }
static inline grant_handle_t steal_maptrack_handle(struct grant_table *lgt, struct vcpu *curr) { return 0; }
static inline void *alloc_xenheap_page(void) { return NULL; }
static inline void clear_page(void *page) {}
static inline void write_atomic(grant_handle_t *ptr, grant_handle_t val) {}
static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}