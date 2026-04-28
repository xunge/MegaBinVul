#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef int gint32;
typedef char gchar;
typedef unsigned char guchar;

typedef struct {
    int imageType;
    int imageCompression;
    int idLength;
    int colorMapType;
    int colorMapIndex;
    int colorMapLength;
    int colorMapSize;
    int xOrigin;
    int yOrigin;
    int width;
    int height;
    int bpp;
    int bytes;
    int alphaBits;
    int flipHoriz;
    int flipVert;
} tga_info;

typedef struct {
    int domain;
    int code;
    char *message;
} GError;

#define TGA_TYPE_MAPPED 1
#define TGA_TYPE_COLOR 2
#define TGA_TYPE_GRAY 3
#define TGA_COMP_NONE 0
#define TGA_COMP_RLE 1
#define G_FILE_ERROR 0

extern const gchar magic[8];
extern gint32 ReadImage(FILE *fp, tga_info *info, const gchar *filename);
extern void gimp_progress_init_printf(const gchar *format, ...);
extern gchar* gimp_filename_to_utf8(const gchar *filename);
extern FILE* g_fopen(const gchar *filename, const gchar *mode);
extern void g_set_error(GError **error, int domain, int code, const gchar *format, ...);
extern int g_file_error_from_errno(int errno_val);
extern gchar* g_strerror(int errno_val);
extern void g_message(const gchar *format, ...);