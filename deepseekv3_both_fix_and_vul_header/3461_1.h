#include <stddef.h>
#include <stdlib.h>

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
    const char *key;
    size_t hash;
    void *value;
};

struct bucket_t {
    list_t *first;
    list_t *last;
};

struct hashtable_t {
    size_t order;
    size_t size;
    bucket_t *buckets;
    list_t list;
};

#define hashmask(order) ((1 << (order)) - 1)
#define num_buckets(hashtable) (1 << (hashtable)->order)

void json_decref(void *value);
void jsonp_free(void *ptr);
void list_remove(list_t *list);
pair_t *hashtable_find_pair(hashtable_t *hashtable, bucket_t *bucket, const char *key, size_t hash);