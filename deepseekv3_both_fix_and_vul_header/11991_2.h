#include <stddef.h>
#include <stdint.h>
#include <assert.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef size_t gsize;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef char gchar;

typedef struct GVariantTypeInfo GVariantTypeInfo;

typedef struct {
    gsize size;
    const gchar *data;
    GVariantTypeInfo *type_info;
    gsize depth;
    gsize ordered_offsets_up_to;
} GVariantSerialised;

struct Offsets {
    gboolean is_normal;
    gsize length;
    gsize offset_size;
    gsize data_size;
    const guint8 *array;
};

#define G_MAXSIZE ((gsize)-1)
#define g_assert(expr) assert(expr)

GVariantTypeInfo* g_variant_type_info_element(GVariantTypeInfo *type_info);
void g_variant_type_info_query(GVariantTypeInfo *type_info, guint *alignment, gsize *size);
gboolean g_variant_serialised_is_normal(GVariantSerialised value);
struct Offsets gvs_variable_sized_array_get_frame_offsets(GVariantSerialised value);
gsize gvs_read_unaligned_le(const guint8 *data, gsize size);