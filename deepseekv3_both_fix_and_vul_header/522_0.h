#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int obj_id;
    long offset;
} xref_entry_t;

typedef struct {
    int n_entries;
    xref_entry_t *entries;
} xref_t;