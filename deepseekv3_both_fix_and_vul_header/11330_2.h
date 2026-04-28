#include <stdlib.h>
#include <pthread.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct ucma_context {
    struct list_head mc_list;
};

struct ucma_multicast {
    int id;
    struct ucma_context *ctx;
    struct list_head list;
};

#define GFP_KERNEL 0

static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static struct {
    int (*alloc)(void*, void*, int, int, int);
} multicast_idr;

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }
static void mutex_lock(pthread_mutex_t *mutex) { pthread_mutex_lock(mutex); }
static void mutex_unlock(pthread_mutex_t *mutex) { pthread_mutex_unlock(mutex); }
static int idr_alloc(void *idr, void *ptr, int start, int end, int flags) { return 0; }
static void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}