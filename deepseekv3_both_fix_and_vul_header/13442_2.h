#include <pthread.h>
#include <stdlib.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct xt_table_info {
    int number;
};

struct xt_table {
    int af;
    void *private;
    char *name;
    struct list_head list;
};

struct {
    pthread_mutex_t mutex;
} xt[256];

#define GFP_KERNEL 0
#define AUDIT_XT_OP_UNREGISTER 0
#define NFPROTO_NUMPROTO 256

void mutex_lock(pthread_mutex_t *mutex);
void mutex_unlock(pthread_mutex_t *mutex);
void list_del(struct list_head *entry);
void audit_log_nfcfg(const char *name, int af, int number, int op, int flags);
void kfree(void *ptr);