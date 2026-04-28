#include <stddef.h>

typedef struct pair_t pair_t;
typedef struct bucket_t bucket_t;
typedef struct hashtable_t hashtable_t;

struct pair_t {
    const char *key;
    void *value;
    pair_t *next;
};

struct bucket_t {
    pair_t *first;
};

struct hashtable_t {
    unsigned int order;
    bucket_t *buckets;
};

size_t hash_str(const char *str);
pair_t *hashtable_find_pair(hashtable_t *hashtable, bucket_t *bucket, const char *key, size_t hash);
unsigned int num_buckets(hashtable_t *hashtable);
unsigned int hashmask(unsigned int order);