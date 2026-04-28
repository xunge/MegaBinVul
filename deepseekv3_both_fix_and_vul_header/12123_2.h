#include <stddef.h>

#define PERF_ATTACH_GROUP 0x01
#define PERF_ATTACH_CONTEXT 0x02
#define PERF_EV_CAP_SIBLING 0x01
#define PERF_EVENT_STATE_ACTIVE 0x01

struct list_head {
    struct list_head *next, *prev;
};

struct perf_event_context {
    int lock;
};

struct perf_event {
    struct perf_event *group_leader;
    struct perf_event_context *ctx;
    unsigned int attach_state;
    struct list_head sibling_list;
    int nr_siblings;
    int group_generation;
    unsigned int event_caps;
    unsigned int group_caps;
    int state;
    struct list_head active_list;
};

#define list_del_init(entry) do { (void)(entry); } while (0)
#define list_add_tail(new, head) do { (void)(new); (void)(head); } while (0)

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)), \
        n = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)); \
        &pos->member != (head); \
        pos = n, n = (typeof(*pos)*)((char*)n->member.next - offsetof(typeof(*pos), member)))

#define for_each_sibling_event(tmp, leader) \
    for (tmp = leader->group_leader; tmp != leader; tmp = tmp->group_leader)

static inline void lockdep_assert_held(void *lock) { (void)lock; }
static inline void perf_put_aux_event(struct perf_event *event) { (void)event; }
static inline void perf_remove_sibling_event(struct perf_event *event) { (void)event; }
static inline void add_event_to_groups(struct perf_event *event, struct perf_event_context *ctx) { (void)event; (void)ctx; }
static inline struct list_head *get_event_list(struct perf_event *event) { (void)event; return NULL; }
static inline void perf_event__header_size(struct perf_event *event) { (void)event; }
static inline void WARN_ON_ONCE(int condition) { (void)condition; }