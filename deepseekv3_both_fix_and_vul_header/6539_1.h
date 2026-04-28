#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

typedef int gint;
typedef int gint32;
typedef char gchar;
typedef unsigned int guint32;
typedef short gint16;
typedef unsigned short guint16;
typedef int gboolean;

typedef enum {
    G_FILE_ERROR,
    G_FILE_ERROR_FAILED
} GErrorType;

typedef struct {
    GErrorType domain;
    gint code;
    gchar *message;
} GError;

typedef enum {
    PSP_IMAGE_BLOCK,
    PSP_CREATOR_BLOCK,
    PSP_COLOR_BLOCK,
    PSP_LAYER_START_BLOCK,
    PSP_SELECTION_BLOCK,
    PSP_ALPHA_BANK_BLOCK,
    PSP_THUMBNAIL_BLOCK,
    PSP_EXTENDED_DATA_BLOCK,
    PSP_TUBE_BLOCK,
    PSP_COMPOSITE_IMAGE_BANK_BLOCK,
    PSP_LAYER_BLOCK,
    PSP_CHANNEL_BLOCK,
    PSP_ALPHA_CHANNEL_BLOCK,
    PSP_ADJUSTMENT_EXTENSION_BLOCK,
    PSP_VECTOR_EXTENSION_BLOCK,
    PSP_SHAPE_BLOCK,
    PSP_PAINTSTYLE_BLOCK,
    PSP_COMPOSITE_ATTRIBUTES_BLOCK,
    PSP_JPEG_BLOCK
} PSPBlockID;

typedef struct {
    gint width;
    gint height;
    gboolean greyscale;
    gint resolution;
    gint compression;
} PSPimage;

extern gint16 psp_ver_major;
extern gint16 psp_ver_minor;

#define IFDBG(level)
#define GUINT16_FROM_LE(val) (val)
#define GIMP_GRAY 0
#define GIMP_RGB 1

extern int g_stat(const char *path, struct stat *buf);
extern FILE *g_fopen(const char *path, const char *mode);
extern void g_set_error(GError **err, GErrorType domain, gint code, const char *format, ...);
extern int g_file_error_from_errno(int errno_val);
extern const char *g_strerror(int errno_val);
extern char *gimp_filename_to_utf8(const char *filename);
extern char *_(const char *msg);
extern void g_message(const char *format, ...);
extern PSPBlockID read_block_header(FILE *f, guint32 *block_init_len, guint32 *block_total_len);
extern int read_general_image_attribute_block(FILE *f, guint32 init_len, guint32 total_len, PSPimage *ia);
extern int read_creator_block(FILE *f, gint32 image_ID, guint32 total_len, PSPimage *ia);
extern int read_layer_block(FILE *f, gint32 image_ID, guint32 total_len, PSPimage *ia);
extern int read_tube_block(FILE *f, gint32 image_ID, guint32 total_len, PSPimage *ia);
extern const char *block_name(PSPBlockID id);
extern const char *compression_name(gint compression);
extern int try_fseek(FILE *f, long offset, int whence);
extern gint32 gimp_image_new(gint width, gint height, gint type);
extern void gimp_image_set_filename(gint32 image_ID, const char *filename);
extern void gimp_image_set_resolution(gint32 image_ID, double xres, double yres);
extern void gimp_image_delete(gint32 image_ID);