#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct perf_event {
    struct perf_event *group_leader;
    struct perf_event_context *ctx;
    unsigned int attach_state;
    unsigned long event_caps;
    unsigned long group_caps;
    struct list_head sibling_list;
    unsigned int nr_siblings;
    unsigned int group_generation;
};

struct perf_event_context {
    void *lock;
};

#define PERF_ATTACH_GROUP 0x01

#define WARN_ON_ONCE(cond) (void)(cond)
#define lockdep_assert_held(lock) (void)(lock)

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

#define for_each_sibling_event(pos, leader) \
    for (pos = container_of((leader)->sibling_list.next, struct perf_event, sibling_list); \
         &pos->sibling_list != &(leader)->sibling_list; \
         pos = container_of(pos->sibling_list.next, struct perf_event, sibling_list))

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

static void perf_event__header_size(struct perf_event *event) {}