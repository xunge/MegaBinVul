#include <stddef.h>
#include <stdint.h>
#include <pthread.h>

typedef uint32_t u32;
typedef uint64_t u64;

struct list_head {
    struct list_head *next, *prev;
};

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof(*pos), member))

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

struct nfp_cpp;
struct nfp_cpp_area_cache {
    u32 id;
    u64 addr;
    size_t size;
    struct list_head entry;
    void *area;
};

struct nfp_cpp {
    pthread_mutex_t area_cache_mutex;
    struct list_head area_cache_list;
    void *imb_cat_table;
    struct {
        int (*area_init)(void *, u32, u64, size_t);
    } *op;
};

int nfp_target_cpp(u32 id, u64 addr, u32 *new_id, u64 *new_addr, void *imb_cat_table);
int nfp_cpp_area_acquire(void *area);
void nfp_cpp_area_release(void *area);

static inline u64 round_down(u64 x, size_t y) {
    return x & ~(y - 1);
}