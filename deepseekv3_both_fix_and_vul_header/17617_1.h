#include <limits.h>
#include <stddef.h>

#define LH_LOAD_FACTOR 0.75
#define LH_EMPTY ((void *)0)
#define LH_FREED ((void *)-1)
#define JSON_C_OBJECT_KEY_IS_CONSTANT 0x1

struct lh_entry {
    const void *k;
    int k_is_constant;
    const void *v;
    struct lh_entry *next;
    struct lh_entry *prev;
};

struct lh_table {
    struct lh_entry *head;
    struct lh_entry *tail;
    struct lh_entry *table;
    unsigned int size;
    unsigned int count;
};

int lh_table_resize(struct lh_table *t, int new_size);