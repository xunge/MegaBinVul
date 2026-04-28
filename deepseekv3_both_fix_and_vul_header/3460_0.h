#include <stdlib.h>
#include <stddef.h>

typedef struct list_t list_t;
typedef struct pair_t pair_t;
typedef struct bucket_t bucket_t;
typedef struct hashtable_t hashtable_t;

struct list_t {
    list_t *next;
    list_t *prev;
};

struct pair_t {
    list_t list;
    size_t hash;
};

struct bucket_t {
    list_t *first;
    list_t *last;
};

struct hashtable_t {
    size_t order;
    size_t num_buckets;
    bucket_t *buckets;
    list_t list;
};

static size_t hashsize(size_t order);
static size_t num_buckets(hashtable_t *hashtable);
static void jsonp_free(void *ptr);
static void *jsonp_malloc(size_t size);
static void list_init(list_t *list);
static pair_t *list_to_pair(list_t *list);
static void insert_to_bucket(hashtable_t *hashtable, bucket_t *bucket, list_t *list);