#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#define STATE_LOCKED 0x1
#define STATE_SERIALISED 0x2
#define G_MAXSIZE SIZE_MAX

typedef void* gpointer;
typedef size_t gsize;

typedef struct _GBytes GBytes;

struct _GBytes {
    void* data;
    size_t size;
};

typedef struct {
    union {
        struct {
            gpointer data;
            GBytes *bytes;
            gsize ordered_offsets_up_to;
        } serialised;
    } contents;
    gsize size;
    int state;
} GVariant;

#define g_assert(expr) assert(expr)
#define g_malloc malloc

GBytes* g_bytes_new_take(void* data, size_t size);
void* g_bytes_get_data(GBytes* bytes, size_t* size);
void g_variant_ensure_size(GVariant* value);
void g_variant_serialise(GVariant* value, void* data);
void g_variant_release_children(GVariant* value);