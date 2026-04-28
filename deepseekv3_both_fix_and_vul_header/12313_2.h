#include <string.h>
#include <stddef.h>

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct lockdep_map {
    const char *name;
    struct lock_class_key *key;
    unsigned int subclass;
};

struct timer_list {
    struct hlist_node entry;
    unsigned long flags;
#ifdef CONFIG_TIMER_STATS
    void *start_site;
    int start_pid;
    char start_comm[16];
#endif
    struct lockdep_map lockdep_map;
};

struct lock_class_key;

#define TASK_COMM_LEN 16

unsigned int raw_smp_processor_id(void);
void lockdep_init_map(struct lockdep_map *lock, const char *name, struct lock_class_key *key, int subclass);