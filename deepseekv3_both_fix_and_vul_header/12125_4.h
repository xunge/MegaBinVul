#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint64_t u64;
#define __user

struct mutex {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct perf_event_context {
    struct mutex mutex;
};

struct perf_event {
    struct perf_event *group_leader;
    struct perf_event_context *ctx;
    size_t read_size;
    unsigned int nr_siblings;
    struct mutex child_mutex;
    struct list_head child_list;
};

#define GFP_KERNEL 0
#define ENOMEM 1
#define EFAULT 2

#define lockdep_assert_held(lock) ((void)0)

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (head); pos = pos->member.next)

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *p) { free(p); }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline void mutex_lock(struct mutex *lock) { }
static inline void mutex_unlock(struct mutex *lock) { }

int __perf_read_group_add(struct perf_event *event, u64 read_format, u64 *values);