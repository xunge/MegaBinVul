#include <stddef.h>
#include <stdbool.h>

#define PERF_ATTACH_GROUP      0x01
#define PERF_ATTACH_CONTEXT    0x02
#define PERF_EV_CAP_SIBLING    0x01
#define PERF_EVENT_STATE_ACTIVE 0x01

struct list_head {
    struct list_head *next, *prev;
};

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct perf_event {
    struct perf_event *group_leader;
    struct perf_event_context *ctx;
    struct list_head sibling_list;
    unsigned int attach_state;
    unsigned int event_caps;
    unsigned int group_caps;
    unsigned int nr_siblings;
    unsigned int state;
    struct rb_node group_node;
    struct list_head active_list;
};

struct perf_event_context {
    void *lock;
};

static inline void lockdep_assert_held(void *lock) {}
static void perf_put_aux_event(struct perf_event *event) {}
static void perf_remove_sibling_event(struct perf_event *event) {}
static void add_event_to_groups(struct perf_event *event, struct perf_event_context *ctx) {}
static struct list_head *get_event_list(struct perf_event *event) { return NULL; }
static void perf_event__header_size(struct perf_event *event) {}
static void WARN_ON_ONCE(bool condition) {}

#define list_del_init(ptr) do { (ptr)->next = (ptr); (ptr)->prev = (ptr); } while (0)
#define list_add_tail(new, head) do { \
    (new)->next = (head); \
    (new)->prev = (head)->prev; \
    (head)->prev->next = (new); \
    (head)->prev = (new); \
} while (0)

#define RB_EMPTY_NODE(node) ((node)->__rb_parent_color == 0)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member), \
        n = list_entry(pos->member.next, typeof(*pos), member); \
        &pos->member != (head); \
        pos = n, n = list_entry(n->member.next, typeof(*n), member))

#define for_each_sibling_event(sibling, leader) \
    for ((sibling) = (leader); (sibling); (sibling) = NULL)