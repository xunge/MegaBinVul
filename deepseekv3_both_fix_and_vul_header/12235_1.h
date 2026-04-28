#include <stdbool.h>
#include <pthread.h>

#define TXG_SIZE 3
#define B_TRUE true
#define B_FALSE false

typedef bool boolean_t;

typedef struct {
    pthread_mutex_t lock;
} mutex;

typedef struct {
    int active;
} multilist_link;

typedef struct {
    int empty;
} list_head;

typedef struct dnode {
    mutex dn_mtx;
    multilist_link dn_dirty_link[TXG_SIZE];
    list_head dn_dirty_records[TXG_SIZE];
} dnode_t;

void mutex_enter(mutex *mtx) { pthread_mutex_lock(&mtx->lock); }
void mutex_exit(mutex *mtx) { pthread_mutex_unlock(&mtx->lock); }
bool multilist_link_active(multilist_link *link) { return link->active; }
bool list_is_empty(list_head *head) { return head->empty; }