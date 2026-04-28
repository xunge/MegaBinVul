#include <stdbool.h>
#include <stddef.h>

struct hw_perf_event {
    unsigned long last_period;
    unsigned long sample_period;
    int state;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct perf_event {
    struct hw_perf_event hw;
    struct hlist_node hlist_entry;
};

struct swevent_htable {
    bool online;
};

#define PERF_EF_START 0x01
#define EINVAL 22

extern struct swevent_htable swevent_htable;

static inline struct swevent_htable *this_cpu_ptr(struct swevent_htable *ptr)
{
    return ptr;
}

static inline bool is_sampling_event(struct perf_event *event)
{
    return false;
}

static inline void perf_swevent_set_period(struct perf_event *event)
{
}

static inline struct hlist_head *find_swevent_head(struct swevent_htable *swhash, struct perf_event *event)
{
    return NULL;
}

static inline void perf_event_update_userpage(struct perf_event *event)
{
}

static inline void hlist_add_head_rcu(struct hlist_node *n, struct hlist_head *h)
{
}

static inline int WARN_ON_ONCE(bool condition)
{
    return condition ? 1 : 0;
}