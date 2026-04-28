#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define ARMPMU_MAX_HWEVENTS 32
#define EINVAL 22

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }
#define list_for_each_entry(pos, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = container_of(pos->member.next, typeof(*pos), member))

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

struct perf_event {
    struct perf_event *group_leader;
    struct list_head sibling_list;
    struct list_head group_entry;
    void *pmu;
};

struct pmu_hw_events {
    unsigned long *used_mask;
};

#define DECLARE_BITMAP(name, bits) unsigned long name[((bits) + (8*sizeof(long)) - 1)/(8*sizeof(long))]

int validate_event_3args(void *pmu, struct pmu_hw_events *fake_pmu, struct perf_event *event);
int validate_event_2args(struct pmu_hw_events *fake_pmu, struct perf_event *event);