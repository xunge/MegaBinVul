#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct list_item_t {
    char *key;
    char *value;
    struct list_item_t *nextPtr;
} list_item_t;

static void list_insert(list_item_t **list, char *key, char *value);
static void list_free(list_item_t **list);