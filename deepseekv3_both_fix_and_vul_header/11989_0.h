#include <stddef.h>

typedef void* gpointer;
typedef const void* gconstpointer;
typedef size_t gsize;

typedef struct _GVariantSerialised {
    gconstpointer type_info;
    gsize size;
    gsize depth;
    gpointer data;
    gsize ordered_offsets_up_to;
} GVariantSerialised;

typedef struct _GVariant {
    gconstpointer type_info;
    gsize size;
    gsize depth;
    unsigned int state;
    union {
        struct {
            gsize ordered_offsets_up_to;
        } serialised;
    } contents;
} GVariant;

#define STATE_SERIALISED (1 << 0)

void g_variant_lock(GVariant *value);
void g_variant_unlock(GVariant *value);
void g_variant_ensure_size(GVariant *value);
void g_variant_store(GVariant *value, gpointer data);
#define g_assert(expr) ((void)0)