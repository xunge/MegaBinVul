#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef uint8_t guchar;
typedef int32_t gint;
typedef uint32_t guint32;
typedef int32_t gint32;
typedef int16_t gint16;
typedef uint8_t guint8;

typedef struct {
    guint32 header_size;
    gint32 width;
    gint32 height;
    gint16 planes;
    gint16 bpp;
    gint32 compression;
    gint32 image_size;
    gint32 x_res;
    gint32 y_res;
    gint32 used_clrs;
    gint32 important_clrs;
} IcoFileDataHeader;

#define D(x)
#define R_VAL_GIMP(p) (((guint8 *)(p))[0])
#define G_VAL_GIMP(p) (((guint8 *)(p))[1])
#define B_VAL_GIMP(p) (((guint8 *)(p))[2])
#define A_VAL_GIMP(p) (((guint8 *)(p))[3])
#define R_VAL(c) (((guint8 *)(c))[2])
#define G_VAL(c) (((guint8 *)(c))[1])
#define B_VAL(c) (((guint8 *)(c))[0])

#define g_new0(type, count) calloc(count, sizeof(type))
#define g_free free

static void ico_read_int32(FILE *fp, gint32 *val, int count);
static void ico_read_int16(FILE *fp, gint16 *val, int count);
static void ico_read_int8(FILE *fp, guint8 *val, int count);
static guchar *ico_alloc_map(gint w, gint h, gint bpp, gint *length);
static int ico_get_bit_from_data(guchar *data, int width, int pos);
static int ico_get_nibble_from_data(guchar *data, int width, int pos);
static int ico_get_byte_from_data(guchar *data, int width, int pos);
static int ico_rowstride(int width, int bpp);