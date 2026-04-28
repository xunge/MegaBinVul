#include <stddef.h>
#include <stdint.h>
#include <assert.h>

typedef enum {
  G_VARIANT_CLASS_BOOLEAN,
  G_VARIANT_CLASS_BYTE,
  G_VARIANT_CLASS_INT16,
  G_VARIANT_CLASS_UINT16,
  G_VARIANT_CLASS_INT32,
  G_VARIANT_CLASS_UINT32,
  G_VARIANT_CLASS_INT64,
  G_VARIANT_CLASS_UINT64,
  G_VARIANT_CLASS_HANDLE,
  G_VARIANT_CLASS_DOUBLE,
  G_VARIANT_CLASS_STRING,
  G_VARIANT_CLASS_OBJECT_PATH,
  G_VARIANT_CLASS_SIGNATURE,
  G_VARIANT_CLASS_VARIANT,
  G_VARIANT_CLASS_MAYBE,
  G_VARIANT_CLASS_ARRAY,
  G_VARIANT_CLASS_TUPLE,
  G_VARIANT_CLASS_DICT_ENTRY
} GVariantClass;

typedef struct _GVariant GVariant;
typedef struct _GVariantType GVariantType;
typedef struct _GVariantBuilder {
    GVariantType *type;
    GVariant **children;
    size_t n_children;
    size_t allocated;
} GVariantBuilder;

typedef size_t gsize;
typedef int gboolean;
typedef uint8_t guint8;
typedef int16_t gint16;
typedef uint16_t guint16;
typedef int32_t gint32;
typedef uint32_t guint32;
typedef int64_t gint64;
typedef uint64_t guint64;
typedef double gdouble;
typedef char gchar;

#define g_clear_pointer(pp, destroy) \
    do { \
        if (*(pp)) { \
            (destroy)(*(pp)); \
            *(pp) = NULL; \
        } \
    } while (0)

GVariantClass g_variant_classify(GVariant *value);
void g_variant_builder_init(GVariantBuilder *builder, GVariantType *type);
GVariantType *g_variant_get_type(GVariant *value);
gsize g_variant_n_children(GVariant *value);
GVariant *g_variant_get_child_value(GVariant *value, gsize index);
void g_variant_builder_add_value(GVariantBuilder *builder, GVariant *value);
void g_variant_unref(GVariant *value);
GVariant *g_variant_builder_end(GVariantBuilder *builder);
GVariant *g_variant_maybe_get_child_value(GVariant *value, gsize index);
GVariant *g_variant_ref_sink(GVariant *value);
GVariant *g_variant_new_boolean(gboolean value);
gboolean g_variant_get_boolean(GVariant *value);
GVariant *g_variant_new_byte(guint8 value);
guint8 g_variant_get_byte(GVariant *value);
GVariant *g_variant_new_int16(gint16 value);
gint16 g_variant_get_int16(GVariant *value);
GVariant *g_variant_new_uint16(guint16 value);
guint16 g_variant_get_uint16(GVariant *value);
GVariant *g_variant_new_int32(gint32 value);
gint32 g_variant_get_int32(GVariant *value);
GVariant *g_variant_new_uint32(guint32 value);
guint32 g_variant_get_uint32(GVariant *value);
GVariant *g_variant_new_int64(gint64 value);
gint64 g_variant_get_int64(GVariant *value);
GVariant *g_variant_new_uint64(guint64 value);
guint64 g_variant_get_uint64(GVariant *value);
GVariant *g_variant_new_handle(gint32 value);
gint32 g_variant_get_handle(GVariant *value);
GVariant *g_variant_new_double(gdouble value);
gdouble g_variant_get_double(GVariant *value);
GVariant *g_variant_new_string(const gchar *value);
const gchar *g_variant_get_string(GVariant *value, gsize *length);
GVariant *g_variant_new_object_path(const gchar *value);
GVariant *g_variant_new_signature(const gchar *value);
void g_assert_not_reached(void);