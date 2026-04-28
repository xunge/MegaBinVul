#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int gint;
typedef unsigned char guint8;
typedef unsigned short guint16;
typedef unsigned int guint32;

typedef struct {
    guint8 width;
    guint8 height;
    guint8 color_count;
    guint8 reserved;
    guint16 planes;
    guint16 bpp;
    guint32 size;
    guint32 offset;
} IcoFileEntry;

typedef struct {
    guint8 width;
    guint8 height;
    guint16 bpp;
    guint32 size;
    guint32 offset;
} IcoLoadInfo;

typedef struct _GError GError;
#define G_FILE_ERROR 0

#define g_new(type, count) ((type*)malloc(sizeof(type) * (count)))
#define g_free(ptr) free(ptr)
#define g_set_error(err, domain, code, fmt, ...) 
#define _(str) str
#define GUINT16_FROM_LE(val) (val)
#define GUINT32_FROM_LE(val) (val)
#define D(x)