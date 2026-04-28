#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PSD_COMP_RAW 0
#define PSD_COMP_RLE 1

typedef struct {
    int rows;
    int columns;
    char *data;
} PSDchannel;

typedef struct {
    int domain;
    int code;
    char *message;
} GError;

#define IFDBG(level) if (0)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define G_MAXINT32 2147483647
#define G_FILE_ERROR 0
#define G_FILE_ERROR_FAILED 1

typedef int gint;
typedef unsigned short guint16;
typedef unsigned int guint32;
typedef char gchar;

void* g_malloc(size_t size);
void g_free(void *ptr);
void decode_packbits(char *src, char *dst, guint32 src_len, guint32 dst_len);
void convert_16_bit(char *src, char *dst, guint32 len);
void convert_1_bit(char *src, char *dst, int rows, int cols);
void psd_set_error(int eof, int err, GError **error);
void g_set_error(GError **error, int domain, int code, const char *message);
void g_debug(const char *format, ...);
#define _(x) x