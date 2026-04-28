#include <stddef.h>

typedef void GFile;
typedef void GimpImage;
typedef void GimpDrawable;
typedef void GeglNode;
typedef void GeglBuffer;
typedef void GError;
typedef int gboolean;
typedef char gchar;

#define TRUE 1
#define FALSE 0

GeglBuffer* gimp_drawable_get_buffer(GimpDrawable *drawable);
GeglNode* gegl_node_new(void);
GeglNode* gegl_node_new_child(GeglNode *graph, const char *property, ...);
const char* g_file_peek_path(GFile *file);
void gegl_node_connect_to(GeglNode *source, const char *output, GeglNode *sink, const char *input);
void gegl_node_process(GeglNode *node);
void g_object_unref(void *object);