#include <stddef.h>
#include <stdint.h>

typedef size_t gsize;
#define G_MAXSIZE ((gsize)-1)

typedef enum {
    G_VARIANT_MEMBER_ENDING_LAST,
    G_VARIANT_MEMBER_ENDING_FIXED,
    G_VARIANT_MEMBER_ENDING_OFFSET
} GVariantMemberEndingType;

typedef struct {
    gsize i;
    gsize a;
    gsize b;
    gsize c;
    GVariantMemberEndingType ending_type;
    void *type_info;
} GVariantMemberInfo;

typedef struct {
    void *data;
    gsize size;
    void *type_info;
} GVariantSerialised;

gsize gvs_read_unaligned_le(const void *data, gsize size);
void *g_variant_type_info_member_info(void *type_info, gsize index);
void g_variant_type_info_query(void *type_info, void *alignment, gsize *size);