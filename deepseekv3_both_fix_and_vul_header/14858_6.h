#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef int gint;
typedef int gint32;
typedef char gchar;
typedef unsigned char guchar;
typedef double gdouble;

#define _(x) x
#define D(x)

typedef struct _GError GError;
typedef enum {
    G_FILE_ERROR
} GErrorDomain;

typedef enum {
    GIMP_RGB
} GimpImageType;

typedef struct {
    gint width;
    gint height;
    gint bpp;
} IcoLoadInfo;

extern gint32 gimp_image_new(gint width, gint height, GimpImageType type);
extern void gimp_progress_init_printf(const gchar *message, ...);
extern void gimp_progress_update(gdouble percentage);
extern gchar* gimp_filename_to_utf8(const gchar *filename);
extern void* g_malloc(size_t size);
extern void g_free(void *ptr);
extern FILE* g_fopen(const gchar *filename, const gchar *mode);
extern void g_set_error(GError **error, GErrorDomain domain, gint code, const gchar *message, ...);
extern gint g_file_error_from_errno(gint errno_value);
extern gchar* g_strerror(gint errno_value);
extern gint ico_read_init(FILE *fp);
extern IcoLoadInfo* ico_read_info(FILE *fp, gint icon_count, ...);
extern void ico_load_layer(FILE *fp, gint32 image, gint match, guchar *buffer, size_t size, IcoLoadInfo *info);

#define g_new(type, size) ((type*)g_malloc((size)*sizeof(type)))