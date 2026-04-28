#include <stddef.h>

typedef struct _cairo_surface {
    int dummy;
} cairo_surface_t;

typedef struct _cairo_user_data_key_t {
    int unused;
} cairo_user_data_key_t;

typedef void (*cairo_destroy_func_t)(void *data);

#define CAIRO_FORMAT_RGB24 0

typedef unsigned char guchar;
typedef int gint;

extern void *g_malloc(size_t size);
extern void g_free(void *data);
extern cairo_surface_t *cairo_image_surface_create_for_data(unsigned char *data, int format, int width, int height, int stride);
extern void cairo_surface_set_user_data(cairo_surface_t *surface, cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);

#define G_BYTE_ORDER 1234
#define G_LITTLE_ENDIAN 1234