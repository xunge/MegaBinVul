#include <stddef.h>

#define MAX_RT_PRIO 100
#define BUG_ON(condition) ((void)0)

struct list_head {
    struct list_head *next, *prev;
};

struct sched_rt_entity {
    struct list_head run_list;
};

struct rt_prio_array {
    unsigned long bitmap[1];
    struct list_head queue[MAX_RT_PRIO];
};

struct rt_rq {
    struct rt_prio_array active;
};

static inline int sched_find_first_bit(const unsigned long *b)
{
    return 0;
}

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))