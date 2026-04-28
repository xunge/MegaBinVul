#include <stddef.h>

typedef void* gpointer;
typedef size_t gsize;

typedef struct {
    char *data;
    size_t size;
    int depth;
} GVariantSerialised;

typedef void (*GVariantSerialisedFiller)(GVariantSerialised *, const void *);