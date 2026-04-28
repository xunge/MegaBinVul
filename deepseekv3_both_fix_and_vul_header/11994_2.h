#include <stddef.h>
#include <stdbool.h>

typedef bool gboolean;
typedef size_t gsize;
typedef unsigned int guint;

typedef struct GVariantTypeInfo GVariantTypeInfo;

typedef struct {
    GVariantTypeInfo *type_info;
    gsize size;
    guint depth;
    guint ordered_offsets_up_to;
} GVariantSerialised;

GVariantTypeInfo* g_variant_type_info_element(GVariantTypeInfo *type_info);
void g_variant_type_info_query_element(GVariantTypeInfo *type_info, gsize *alignment, gsize *size);
gboolean g_variant_serialised_is_normal(GVariantSerialised value);

#define FALSE false
#define TRUE true