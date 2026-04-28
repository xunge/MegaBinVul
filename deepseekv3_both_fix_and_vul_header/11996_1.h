#include <stddef.h>
#include <stdint.h>

typedef int gboolean;
typedef unsigned int guint;
typedef size_t gsize;
typedef uint8_t guchar;

typedef struct _GVariantSerialised GVariantSerialised;
typedef struct _GVariantMemberInfo GVariantMemberInfo;
typedef struct _GVariantTypeInfo GVariantTypeInfo;

struct _GVariantSerialised {
    const guchar *data;
    gsize size;
    GVariantTypeInfo *type_info;
    gsize depth;
    gsize ordered_offsets_up_to;
};

struct _GVariantMemberInfo {
    GVariantTypeInfo *type_info;
    guint ending_type;
};

enum {
    G_VARIANT_MEMBER_ENDING_FIXED,
    G_VARIANT_MEMBER_ENDING_LAST,
    G_VARIANT_MEMBER_ENDING_OFFSET
};

#define G_UNLIKELY(expr) (expr)
#define G_MAXSIZE ((gsize)-1)
#define g_assert(expr) ((void)0)
#define g_assert_not_reached() (abort())

#define FALSE 0
#define TRUE 1

guint gvs_get_offset_size(gsize size);
gsize g_variant_type_info_n_members(GVariantTypeInfo *type_info);
GVariantMemberInfo *g_variant_type_info_member_info(GVariantTypeInfo *type_info, gsize index);
void g_variant_type_info_query(GVariantTypeInfo *type_info, guint *alignment, gsize *fixed_size);
gsize gvs_read_unaligned_le(const guchar *data, guint offset_size);
gboolean g_variant_serialised_is_normal(GVariantSerialised child);