#include <stddef.h>

typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef void* GVariantTypeInfo;
typedef unsigned char* gconstpointer;
typedef size_t gsize;

typedef struct {
  gconstpointer data;
  gsize size;
  GVariantTypeInfo *type_info;
  gsize depth;
  gsize ordered_offsets_up_to;
} GVariantSerialised;

GVariantTypeInfo *g_variant_type_info_element(GVariantTypeInfo *type_info);
gboolean g_variant_serialised_is_normal(GVariantSerialised value);