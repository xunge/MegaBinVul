#include <stdlib.h>

typedef unsigned int u32;

typedef struct GF_Box GF_Box;

typedef struct {
    char *name;
} GroupIdToNameEntry;

typedef struct GroupIdToNameBox {
    u32 nb_entries;
    GroupIdToNameEntry *entries;
} GroupIdToNameBox;

void gf_free(void *ptr);