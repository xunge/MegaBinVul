#include <stddef.h>
#include <stdint.h>
#include <assert.h>

typedef int gboolean;
typedef size_t gsize;
typedef unsigned int guint;
typedef const void* gconstpointer;
typedef unsigned char* gucharptr;

typedef struct GVariantTypeInfo GVariantTypeInfo;
typedef struct GVariantMemberInfo GVariantMemberInfo;

typedef enum {
    G_VARIANT_MEMBER_ENDING_FIXED,
    G_VARIANT_MEMBER_ENDING_LAST,
    G_VARIANT_MEMBER_ENDING_OFFSET
} GVariantMemberEndingType;

typedef struct {
    gucharptr data;
    gsize size;
    GVariantTypeInfo *type_info;
    gsize depth;
    gsize ordered_offsets_up_to;
    gsize checked_offsets_up_to;
} GVariantSerialised;

struct GVariantMemberInfo {
    GVariantTypeInfo *type_info;
    GVariantMemberEndingType ending_type;
};

#define G_UNLIKELY(expr) (expr)
#define G_MAXSIZE ((gsize)-1)
#define FALSE 0
#define TRUE 1

static void g_assert_not_reached(void) { assert(0); }
static void g_assert(int condition) { assert(condition); }
static gsize gvs_read_unaligned_le(gconstpointer data, guint offset_size) { return 0; }
static gboolean g_variant_serialised_is_normal(GVariantSerialised child) { return TRUE; }
static guint gvs_get_offset_size(gsize size) { return 0; }
static GVariantMemberInfo *g_variant_type_info_member_info(GVariantTypeInfo *type_info, gsize i) { return NULL; }
static void g_variant_type_info_query(GVariantTypeInfo *type_info, guint *alignment, gsize *fixed_size) {}
static gsize g_variant_type_info_n_members(GVariantTypeInfo *type_info) { return 0; }