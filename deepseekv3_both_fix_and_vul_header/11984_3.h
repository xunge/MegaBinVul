#include <stddef.h>
#include <stdatomic.h>
#include <stdint.h>
#include <assert.h>

typedef size_t gsize;
typedef struct _GVariant GVariant;
typedef struct _GVariantSerialised GVariantSerialised;
typedef struct _GVariantTypeInfo GVariantTypeInfo;
typedef struct _GBytes GBytes;

#define g_return_val_if_fail(expr, val) if (!(expr)) return val
#define g_assert(expr) assert(expr)
#define g_atomic_int_get(ptr) atomic_load(ptr)
#define g_variant_lock(v) 
#define g_variant_unlock(v) 
#define g_variant_ref(v) (v)
#define g_variant_to_serialised(v) (GVariantSerialised){0}
#define g_variant_serialised_get_child(s, i) (GVariantSerialised){0}
#define g_variant_type_info_query_depth(t) 0
#define g_variant_is_of_type(v, t) 1
#define g_variant_new_tuple(p, n) NULL
#define g_slice_new(type) ((type*)malloc(sizeof(type)))
#define g_atomic_ref_count_init(ptr) atomic_init(ptr, 1)
#define g_bytes_ref(b) (b)
#define g_variant_n_children(v) 0

struct _GVariant {
    GVariantTypeInfo *type_info;
    gsize state;
    gsize size;
    atomic_uint ref_count;
    gsize depth;
    union {
        struct {
            GBytes *bytes;
            const void *data;
            gsize ordered_offsets_up_to;
        } serialised;
        struct {
            GVariant **children;
        } tree;
    } contents;
};

struct _GVariantSerialised {
    GVariantTypeInfo *type_info;
    gsize size;
    const void *data;
    gsize ordered_offsets_up_to;
};

#define G_MAXSIZE ((gsize)-1)
#define G_VARIANT_MAX_RECURSION_DEPTH 64
#define STATE_SERIALISED (1 << 0)
#define STATE_TRUSTED (1 << 1)
#define G_VARIANT_TYPE_VARIANT 0