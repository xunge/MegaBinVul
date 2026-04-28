#include <stddef.h>

typedef struct _GVariantTypeInfo GVariantTypeInfo;

typedef struct {
    GVariantTypeInfo *type_info;
    const void *data;
    size_t size;
    size_t depth;
    size_t ordered_offsets_up_to;
} GVariantSerialised;

GVariantTypeInfo* g_variant_type_info_element(GVariantTypeInfo *type_info);
GVariantTypeInfo* g_variant_type_info_ref(GVariantTypeInfo *type_info);

typedef size_t gsize;