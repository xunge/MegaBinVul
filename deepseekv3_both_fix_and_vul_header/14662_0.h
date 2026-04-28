#include <stdbool.h>
#include <stddef.h>

typedef struct ASS_Shaper {
    size_t n_glyphs;
    void *event_text;
    void *ctypes;
    void *emblevels;
    void *cmap;
} ASS_Shaper;

#define ASS_REALLOC_ARRAY(ptr, size) ((ptr) = realloc((ptr), (size) * sizeof(*(ptr))))