#include <stdio.h>
#include <setjmp.h>

#define FALSE 0
#define TRUE 1
#define ICO_PNG_MAGIC 0x474E5089
#define PNG_LIBPNG_VER_STRING "1.6.0"
#define D(x) 

typedef int gboolean;
typedef unsigned int guint32;
typedef int gint32;
typedef unsigned int png_uint_32;

typedef struct {
    guint32 offset;
    gint32 width;
    gint32 height;
} IcoLoadInfo;

typedef struct png_struct_def png_struct;
typedef png_struct * png_structp;
typedef struct png_info_def png_info;
typedef png_info * png_infop;

static gboolean ico_read_int32(FILE *fp, gint32 *data, int count) {
    return FALSE;
}