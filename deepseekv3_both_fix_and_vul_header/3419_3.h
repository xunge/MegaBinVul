#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct fz_context fz_context;
typedef struct fz_colorspace fz_colorspace;

typedef struct xps_document {
    fz_context *ctx;
} xps_document;

#define FZ_MAX_COLORS 32

fz_colorspace *fz_device_rgb(fz_context *ctx);
fz_colorspace *fz_device_gray(fz_context *ctx);
fz_colorspace *fz_device_cmyk(fz_context *ctx);
void fz_warn(fz_context *ctx, const char *fmt, ...);
size_t fz_strlcpy(char *dst, const char *src, size_t siz);
float fz_atof(const char *s);

static int unhex(int c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

static int count_commas(const char *s) {
    int n = 0;
    while (*s) if (*s++ == ',') n++;
    return n;
}