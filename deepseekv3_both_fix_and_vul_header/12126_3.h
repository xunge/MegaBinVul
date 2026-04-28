#include <stddef.h>
#include <errno.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct perf_event {
    struct perf_event *group_leader;
    struct perf_event *aux_event;
    struct list_head sibling_list;
    int group_generation;
};

struct task_struct;
struct perf_event_context;

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define for_each_sibling_event(sibling, event) \
    for ((sibling) = (event)->group_leader; \
         (sibling) != (event); \
         (sibling) = (sibling)->sibling_list.next)

static struct perf_event *inherit_event(struct perf_event *event,
                                      struct task_struct *parent,
                                      struct perf_event_context *parent_ctx,
                                      struct task_struct *child,
                                      struct perf_event *leader,
                                      struct perf_event_context *child_ctx) {
    return NULL;
}

static int perf_get_aux_event(struct perf_event *event, struct perf_event *leader) {
    return 0;
}