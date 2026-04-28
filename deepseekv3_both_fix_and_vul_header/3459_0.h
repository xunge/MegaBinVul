#include <stdlib.h>
#include <stddef.h>

typedef struct list_t list_t;
typedef struct bucket_t bucket_t;
typedef struct hashtable_t hashtable_t;

struct list_t {
    list_t *next;
    list_t *prev;
};

struct bucket_t {
    list_t *first;
    list_t *last;
};

struct hashtable_t {
    size_t size;
    size_t order;
    size_t num_buckets;
    bucket_t *buckets;
    list_t list;
};

#define hashsize(order) (1UL << (order))
#define num_buckets(hashtable) (1UL << ((hashtable)->order))

void *jsonp_malloc(size_t size);
void list_init(list_t *list);