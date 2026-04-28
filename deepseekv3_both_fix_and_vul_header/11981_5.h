#include <stdbool.h>
#include <assert.h>

typedef struct _GVariant GVariant;

#define g_assert assert
#define FALSE false

GVariant* g_variant_ref(GVariant* value);
bool g_variant_is_normal_form(GVariant* value);
GVariant* g_variant_deep_copy(GVariant* value, ...);
bool g_variant_is_trusted(GVariant* value);
GVariant* g_variant_ref_sink(GVariant* value);