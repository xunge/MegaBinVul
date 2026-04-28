#include <stddef.h>

typedef struct pair_t pair_t;
typedef struct bucket_t bucket_t;
typedef struct hashtable_t hashtable_t;

struct pair_t {
    void *list;
};

struct bucket_t {
    pair_t *pairs;
};

struct hashtable_t {
    bucket_t *buckets;
    size_t order;
};

size_t hash_str(const char *key);
size_t hashmask(size_t order);
size_t num_buckets(hashtable_t *hashtable);
pair_t *hashtable_find_pair(hashtable_t *hashtable, bucket_t *bucket, const char *key, size_t hash);