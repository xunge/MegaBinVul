#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define GEGL_ABYSS_NONE 0

typedef enum
{
  GIMP_RGB,
  GIMP_GRAY,
  GIMP_INDEXED
} GimpImageBaseType;

typedef enum
{
  GIMP_RGB_IMAGE,
  GIMP_RGBA_IMAGE,
  GIMP_GRAY_IMAGE,
  GIMP_GRAYA_IMAGE,
  GIMP_INDEXED_IMAGE,
  GIMP_INDEXEDA_IMAGE
} GimpImageType;

typedef enum
{
  GIMP_PRECISION_U8_LINEAR,
  GIMP_PRECISION_U16_LINEAR,
  GIMP_PRECISION_U32_LINEAR,
  GIMP_PRECISION_HALF_LINEAR,
  GIMP_PRECISION_FLOAT_LINEAR,
  GIMP_PRECISION_U8_NON_LINEAR,
  GIMP_PRECISION_U16_NON_LINEAR,
  GIMP_PRECISION_U32_NON_LINEAR,
  GIMP_PRECISION_HALF_NON_LINEAR,
  GIMP_PRECISION_FLOAT_NON_LINEAR
} GimpPrecision;

typedef enum
{
  G_FILE_ERROR,
  G_FILE_ERROR_FAILED
} GFileError;

typedef struct _GFile GFile;
typedef struct _GimpImage GimpImage;
typedef struct _GimpLayer GimpLayer;
typedef struct _GeglNode GeglNode;
typedef struct _GeglBuffer GeglBuffer;
typedef struct _Babl Babl;
typedef struct _GError GError;

typedef int gint;
typedef char gchar;
typedef int gboolean;

#define _(x) x
#define GIMP_DRAWABLE(x) ((void*)(x))

static void gimp_progress_init_printf(const char *fmt, ...) {}
static char* gimp_file_get_utf8_name(GFile *file) { return NULL; }
static GeglNode* gegl_node_new() { return NULL; }
static GeglNode* gegl_node_new_child(GeglNode *parent, ...) { return NULL; }
static char* g_file_peek_path(GFile *file) { return NULL; }
static void gegl_node_connect_to(GeglNode *src, const char *port, GeglNode *dest, const char *port2) {}
static void gegl_node_process(GeglNode *node) {}
static void g_object_unref(void *obj) {}
static void g_set_error(GError **err, int domain, int code, const char *format, ...) {}
static void gimp_progress_update(double progress) {}
static int gegl_buffer_get_width(GeglBuffer *buf) { return 0; }
static int gegl_buffer_get_height(GeglBuffer *buf) { return 0; }
static const Babl* gegl_buffer_get_format(GeglBuffer *buf) { return NULL; }
static int babl_format_is_palette(const Babl *format) { return 0; }
static int babl_format_has_alpha(const Babl *format) { return 0; }
static const Babl* babl_format_get_model(const Babl *format) { return NULL; }
static const Babl* babl_format_get_type(const Babl *format, int index) { return NULL; }
static const Babl* babl_model(const char *name) { return NULL; }
static const Babl* babl_type(const char *name) { return NULL; }
static GimpImage* gimp_image_new_with_precision(int width, int height, GimpImageBaseType base_type, GimpPrecision precision) { return NULL; }
static void gimp_image_set_file(GimpImage *image, GFile *file) {}
static GimpLayer* gimp_layer_new(GimpImage *image, const char *name, int width, int height, GimpImageType type, int opacity, int mode) { return NULL; }
static int gimp_image_get_default_new_layer_mode(GimpImage *image) { return 0; }
static void gimp_image_insert_layer(GimpImage *image, GimpLayer *layer, void *parent, int position) {}
static GeglBuffer* gimp_drawable_get_buffer(void *drawable) { return NULL; }
static void gegl_buffer_copy(GeglBuffer *src, void *roi, int abyss, GeglBuffer *dest, void *dest_roi) {}