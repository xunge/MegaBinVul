#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct _GVariant GVariant;
typedef struct _GVariantTypeInfo GVariantTypeInfo;
typedef struct _GBytes GBytes;

typedef struct {
    GVariantTypeInfo *type_info;
    size_t size;
    uint8_t *data;
    size_t depth;
    size_t ordered_offsets_up_to;
    size_t checked_offsets_up_to;
} GVariantSerialised;

#define G_MAXSIZE SIZE_MAX
#define TRUE 1

typedef uint32_t guint;

// 函数声明
GVariantTypeInfo* g_variant_get_type_info(GVariant*);
void g_variant_type_info_query(GVariantTypeInfo*, guint*, void*);
GVariant* g_variant_get_normal_form(GVariant*);
size_t g_variant_get_size(GVariant*);
void* g_malloc(size_t);
size_t g_variant_get_depth(GVariant*);
void g_variant_store(GVariant*, void*);
void g_variant_unref(GVariant*);
void g_variant_serialised_byteswap(GVariantSerialised);
GBytes* g_bytes_new_take(void*, size_t);
GVariant* g_variant_ref_sink(GVariant*);
GVariant* g_variant_new_from_bytes(const char*, GBytes*, int);
const char* g_variant_get_type(GVariant*);
void g_bytes_unref(GBytes*);
int g_variant_is_trusted(GVariant*);
void* g_steal_pointer(void*);