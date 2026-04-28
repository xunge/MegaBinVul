#include <stddef.h>

struct list_node {
    struct list_node *next;
    struct list_node *prev;
};

typedef struct list_node list_t;
typedef struct bucket {
    list_t *first;
    list_t *last;
} bucket_t;

typedef struct hashtable {
    unsigned int order;
    size_t size;
    bucket_t *buckets;
    list_t list;
} hashtable_t;

static inline size_t hashsize(unsigned int order) {
    return (size_t)1 << order;
}

static inline size_t num_buckets(hashtable_t *hashtable) {
    return hashsize(hashtable->order);
}

void list_init(list_t *list);
void hashtable_do_clear(hashtable_t *hashtable);