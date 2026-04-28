#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_CHANNELS 56
#define GIMP_MAX_IMAGE_SIZE 300000
#define G_MAXINT32 2147483647

#define PSD_BITMAP 0
#define PSD_GRAYSCALE 1
#define PSD_INDEXED 2
#define PSD_RGB 3
#define PSD_DUOTONE 8

#define CONVERSION_WARNINGS 1
#define IFDBG(x) if(0)

#define G_FILE_ERROR 0
#define G_FILE_ERROR_FAILED 1

typedef int16_t gint;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef char gchar;

typedef struct {
    guint16 channels;
    guint32 rows;
    guint32 columns;
    guint16 bps;
    guint16 color_mode;
} PSDimage;

typedef struct {
    int domain;
    int code;
    char *message;
} GError;

#define GUINT16_FROM_BE(x) __builtin_bswap16(x)
#define GUINT32_FROM_BE(x) __builtin_bswap32(x)

static void psd_set_error(int feof, int errno_val, GError **error) {
    if (error) {
        *error = malloc(sizeof(GError));
        (*error)->domain = G_FILE_ERROR;
        (*error)->code = errno_val;
        (*error)->message = strerror(errno_val);
    }
}

static void g_set_error(GError **error, int domain, int code, const char *format, ...) {
    if (error) {
        *error = malloc(sizeof(GError));
        (*error)->domain = domain;
        (*error)->code = code;
        (*error)->message = strdup(format);
    }
}

static void g_debug(const char *format, ...) {}
static void g_message(const char *format, ...) {}

#define _(x) x

static const char *get_psd_color_mode_name(guint16 mode) {
    static const char *names[] = {
        "Bitmap", "Grayscale", "Indexed", "RGB", "", "", "", "", "Duotone"
    };
    return (mode < sizeof(names)/sizeof(names[0])) ? names[mode] : "Unknown";
}