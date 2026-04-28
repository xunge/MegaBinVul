#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define unlikely(x) (x)
#define BUG() do { } while (1)
#define _PGC_allocated 0

struct domain;
struct page_info;
struct page_list_head;

struct page_info {
    unsigned long count_info;
};

struct domain {
    int page_alloc_lock;
};

static inline bool get_page(struct page_info *page, struct domain *d) { return true; }
static inline void put_page(struct page_info *page) { }
static inline bool test_and_clear_bit(int nr, volatile unsigned long *addr) { return true; }
static inline void spin_lock_recursive(int *lock) { }
static inline void spin_unlock_recursive(int *lock) { }
static inline bool hypercall_preempt_check(void) { return false; }

#define page_list_for_each_safe(pos, tmp, head) \
    for (pos = NULL, tmp = NULL; pos != NULL; pos = tmp)

#define ERESTART 512