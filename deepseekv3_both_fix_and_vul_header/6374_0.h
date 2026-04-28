#include <stdlib.h>

typedef unsigned int u32;

typedef struct GF_Box GF_Box;

typedef struct {
    u32* view_refs;
} ViewEntry;

typedef struct {
    u32 num_views;
    ViewEntry* views;
} GF_ViewIdentifierBox;

void gf_free(void* ptr);