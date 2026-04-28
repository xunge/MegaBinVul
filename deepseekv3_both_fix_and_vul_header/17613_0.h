#include <stdlib.h>

struct lh_entry {
    void *k;
};

struct lh_table {
    int count;
    int size;
    struct lh_entry *table;
    void (*free_fn)(void *);
    unsigned long (*hash_fn)(const void *);
    int (*equal_fn)(const void *, const void *);
};

typedef void (*lh_entry_free_fn)(void *);
typedef unsigned long (*lh_hash_fn)(const void *);
typedef int (*lh_equal_fn)(const void *, const void *);

#define LH_EMPTY NULL