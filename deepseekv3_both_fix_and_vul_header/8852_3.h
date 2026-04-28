#include <stdatomic.h>
#include <pthread.h>
#include <stddef.h>

#define RING_BUFFER_ALL_CPUS -1
#define BUF_PAGE_SIZE 4096
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define ENOMEM 12
#define EBUSY 16

struct list_head {
    struct list_head *next, *prev;
};

struct buffer_page {
    struct list_head list;
};

struct ring_buffer_per_cpu {
    unsigned long nr_pages;
    unsigned long nr_pages_to_update;
    struct list_head new_pages;
    struct {
        void (*func)(void *);
        void *data;
    } update_pages_work;
    pthread_cond_t update_done;
};

struct ring_buffer {
    struct ring_buffer_per_cpu **buffers;
    unsigned long *cpumask;
    atomic_int resize_disabled;
    atomic_int record_disabled;
    pthread_mutex_t mutex;
};

static inline int atomic_read(atomic_int *v) {
    return atomic_load(v);
}

static inline void atomic_inc(atomic_int *v) {
    atomic_fetch_add(v, 1);
}

static inline void atomic_dec(atomic_int *v) {
    atomic_fetch_sub(v, 1);
}

static inline void mutex_lock(pthread_mutex_t *mutex) {
    pthread_mutex_lock(mutex);
}

static inline void mutex_unlock(pthread_mutex_t *mutex) {
    pthread_mutex_unlock(mutex);
}

static inline int cpumask_test_cpu(int cpu, unsigned long *mask) {
    return mask[cpu / (sizeof(unsigned long)*8)] & (1UL << (cpu % (sizeof(unsigned long)*8)));
}

#define for_each_buffer_cpu(buffer, cpu) \
    for (cpu = 0; cpu < sizeof(buffer->cpumask)*8; cpu++) \
        if (cpumask_test_cpu(cpu, buffer->cpumask))

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline int list_empty(const struct list_head *head) {
    return head->next == head;
}

static inline void list_del_init(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
    INIT_LIST_HEAD(entry);
}

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)), \
         n = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = n, n = (typeof(*pos)*)((char*)n->member.next - offsetof(typeof(*pos), member)))

static inline int cpu_online(int cpu) {
    return 1;
}

static inline void get_online_cpus() {}
static inline void put_online_cpus() {}
static inline int __rb_allocate_pages(int n, struct list_head *list, int cpu) { return 0; }
static inline void rb_update_pages(struct ring_buffer_per_cpu *cpu_buffer) {}
static inline void schedule_work_on(int cpu, void *work) {}
static inline void wait_for_completion(pthread_cond_t *done) {}
static inline void synchronize_sched() {}
static inline void rb_check_pages(struct ring_buffer_per_cpu *cpu_buffer) {}
static inline void free_buffer_page(struct buffer_page *bpage) {}