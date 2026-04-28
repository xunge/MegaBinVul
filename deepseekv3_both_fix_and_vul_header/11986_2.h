#include <stddef.h>
#include <assert.h>

typedef void* gpointer;
typedef size_t gsize;

typedef struct _GVariant GVariant;
typedef struct _GVariantTypeInfo GVariantTypeInfo;

typedef struct {
    GVariantTypeInfo *type_info;
    gpointer data;
    gsize size;
    gsize depth;
    gsize ordered_offsets_up_to;
} GVariantSerialised;

typedef union {
    struct {
        gpointer data;
        gsize ordered_offsets_up_to;
    } serialised;
} GVariantContents;

typedef struct _GVariant {
    GVariantTypeInfo *type_info;
    GVariantContents contents;
    gsize size;
    gsize depth;
    int state;
} GVariant;

#define STATE_SERIALISED (1 << 0)
#define g_assert(expr) assert(expr)