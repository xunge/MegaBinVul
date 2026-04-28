#include <stdbool.h>
#include <pthread.h>
#include <errno.h>

enum bp_state {
    BP_ECANCELED,
    BP_DONE
};

#define GFP_USER 0
#define ENOMEM 12

struct list_head {
    struct list_head *next, *prev;
};

extern bool xen_hotplug_unpopulated;
extern pthread_mutex_t balloon_mutex;
extern pthread_cond_t *balloon_wq;
extern struct list_head ballooned_pages;

static inline void mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static inline void mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static inline void wait_event(pthread_cond_t *cond, int condition) {
    while (!condition) pthread_cond_wait(cond, &balloon_mutex);
}
static inline int list_empty(struct list_head *head) { return head->next == head; }

static enum bp_state reserve_additional_memory(void);
static enum bp_state decrease_reservation(int nr_pages, int gfp);