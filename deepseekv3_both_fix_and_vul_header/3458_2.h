#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_t json_t;

typedef struct list_t {
    struct list_t *next;
    struct list_t *prev;
} list_t;

typedef struct pair_t {
    size_t hash;
    size_t serial;
    json_t *value;
    list_t list;
    char key[];
} pair_t;

typedef struct bucket_t {
    list_t list;
} bucket_t;

typedef struct hashtable_t {
    bucket_t *buckets;
    size_t size;
    size_t order;
} hashtable_t;

static size_t hash_str(const char *str) { return 0; }
static size_t hashsize(size_t order) { return 0; }
static size_t hashmask(size_t order) { return 0; }
static size_t num_buckets(hashtable_t *hashtable) { return 0; }
static int hashtable_do_rehash(hashtable_t *hashtable) { return 0; }
static pair_t *hashtable_find_pair(hashtable_t *hashtable, bucket_t *bucket, const char *key, size_t hash) { return NULL; }
static void insert_to_bucket(hashtable_t *hashtable, bucket_t *bucket, list_t *list) {}
static void json_decref(json_t *json) {}
static void *jsonp_malloc(size_t size) { return NULL; }
static void list_init(list_t *list) {}