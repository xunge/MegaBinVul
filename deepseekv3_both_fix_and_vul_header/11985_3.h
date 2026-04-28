#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define G_MAXSIZE ((size_t)-1)

typedef struct _GVariantType GVariantType;
typedef struct _GBytes GBytes;
typedef unsigned int guint;
typedef size_t gsize;
typedef unsigned char guchar;
typedef int gboolean;
typedef void* gpointer;

typedef struct {
    const GVariantType *type_info;
    guchar *data;
    gsize size;
    guint depth;
    gsize ordered_offsets_up_to;
} GVariantSerialised;

typedef struct {
    const GVariantType *type_info;
    struct {
        struct {
            GBytes *bytes;
            guchar *data;
            gsize ordered_offsets_up_to;
        } serialised;
        gsize size;
    } contents;
    gsize size;
} GVariant;

GVariant* g_variant_alloc(const GVariantType *type, gboolean b, gboolean trusted);
void g_variant_type_info_query(const GVariantType *type, guint *alignment, gsize *size);
gpointer g_bytes_get_data(GBytes *bytes, gsize *size);
gsize g_bytes_get_size(GBytes *bytes);
gboolean g_variant_serialised_check(GVariantSerialised serialised);
GBytes* g_bytes_new(gpointer data, gsize size);
GBytes* g_bytes_new_with_free_func(gpointer data, gsize size, void (*free_func)(gpointer), gpointer user_data);
GBytes* g_bytes_ref(GBytes *bytes);
void g_bytes_unref(GBytes *bytes);
static inline void g_clear_pointer(void *pp, void (*destroy)(void*)) {
    void *ptr = *(void**)pp;
    if (ptr) {
        *(void**)pp = NULL;
        destroy(ptr);
    }
}
void g_error(const char *message);