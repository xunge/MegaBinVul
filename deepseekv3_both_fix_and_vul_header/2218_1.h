#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

typedef int gint;
typedef int gint32;
typedef char gchar;

typedef struct _GError GError;

enum {
    G_FILE_ERROR,
    G_FILE_ERROR_FAILED
};

typedef struct {
    long l_file_version;
    long l_header_size;
    long l_colormap_entries;
    long l_pixmap_width;
    long l_pixmap_height;
    long l_pixmap_depth;
    long l_bits_per_pixel;
    long l_bytes_per_line;
    long l_pixmap_format;
} L_XWDFILEHEADER;

typedef struct {
    unsigned long l_pixel;
    unsigned short l_red;
    unsigned short l_green;
    unsigned short l_blue;
    char l_flags;
} L_XWDCOLOR;

#define GIMP_MAX_IMAGE_SIZE 30000
#define _(x) x

#define g_fopen fopen
#define g_strerror strerror
#define g_free free
#define g_new(type, count) malloc((count) * sizeof(type))