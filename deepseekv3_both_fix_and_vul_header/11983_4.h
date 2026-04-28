#include <stddef.h>
#include <stdint.h>
#include <stdatomic.h>
#include <stdlib.h>

typedef size_t gsize;
typedef struct _GVariant GVariant;
typedef struct _GVariantSerialised GVariantSerialised;
typedef struct _GVariantTypeInfo GVariantTypeInfo;
typedef struct _GBytes GBytes;

struct _GVariant {
    GVariantTypeInfo *type_info;
    gsize size;
    _Atomic int ref_count;
    gsize depth;
    union {
        struct {
            GVariant **children;
        } tree;
        struct {
            GBytes *bytes;
            const void *data;
            gsize ordered_offsets_up_to;
            gsize checked_offsets_up_to;
        } serialised;
    } contents;
    int state;
};

struct _GVariantSerialised {
    GVariantTypeInfo *type_info;
    const void *data;
    gsize size;
    gsize ordered_offsets_up_to;
    gsize checked_offsets_up_to;
};

#define G_MAXSIZE ((gsize)-1)
#define STATE_SERIALISED (1 << 0)
#define STATE_TRUSTED (1 << 1)
#define G_VARIANT_MAX_RECURSION_DEPTH 64
#define G_VARIANT_TYPE_VARIANT ((const void*)0x1)

#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define g_assert(expr) do { if (!(expr)) abort(); } while (0)

GVariant *g_variant_ref(GVariant *value);
void g_variant_unref(GVariant *value);
void g_variant_lock(GVariant *value);
void g_variant_unlock(GVariant *value);
gsize g_variant_n_children(GVariant *value);
GVariantSerialised g_variant_to_serialised(GVariant *value);
GVariantSerialised g_variant_serialised_get_child(GVariantSerialised serialised, gsize index_);
int g_variant_is_of_type(GVariant *value, const void *type);
GVariant *g_variant_new_tuple(GVariant **children, gsize n_children);
void g_variant_type_info_unref(GVariantTypeInfo *type_info);
gsize g_variant_type_info_query_depth(GVariantTypeInfo *type_info);
GBytes *g_bytes_ref(GBytes *bytes);
int g_atomic_int_get(const volatile int *atomic);
void g_atomic_ref_count_init(_Atomic int *atomic);
GVariant *g_slice_new(size_t size);

static inline GVariant* g_slice_new_helper(size_t size) {
    return (GVariant*)malloc(size);
}
#define g_slice_new(type) g_slice_new_helper(sizeof(type))