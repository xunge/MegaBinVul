#include <stdint.h>
#include <stddef.h>
#include <assert.h>

typedef size_t gsize;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef void* gpointer;

typedef struct GVariantTypeInfo GVariantTypeInfo;

typedef struct {
    gsize size;
    gsize ordered_offsets_up_to;
    GVariantTypeInfo *type_info;
    gpointer data;
    gsize depth;
} GVariantSerialised;

struct Offsets {
    gpointer array;
    gsize data_size;
    guint offset_size;
};

#define g_assert_not_reached() assert(0)

GVariantTypeInfo* g_variant_type_info_element(GVariantTypeInfo *type_info);
void g_variant_type_info_ref(GVariantTypeInfo *type_info);
void g_variant_type_info_query(GVariantTypeInfo *type_info, guint *alignment, gsize *size);
struct Offsets gvs_variable_sized_array_get_frame_offsets(GVariantSerialised value);
gsize gvs_offsets_get_offset_n(struct Offsets *offsets, gsize index);
gsize find_unordered_guint8(gpointer array, gsize current, gsize target);
gsize find_unordered_guint16(gpointer array, gsize current, gsize target);
gsize find_unordered_guint32(gpointer array, gsize current, gsize target);
gsize find_unordered_guint64(gpointer array, gsize current, gsize target);