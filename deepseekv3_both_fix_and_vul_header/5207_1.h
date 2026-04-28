#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define PARAM_SIZE 0
#define PARAM_COLOR 1
#define PARAM_FACE 2
#define PARAM_NUMBER 3

typedef struct SrtStack {
    char tag[16];
    char param[PARAM_NUMBER][16];
} SrtStack;

#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define FFMIN(a,b) ((a) > (b) ? (b) : (a))
#define AVERROR(e) (-(e))

typedef struct AVBPrint {
    char *str;
    unsigned len;
    unsigned size;
} AVBPrint;

void av_bprint_chars(AVBPrint *buf, char c, unsigned n);
void av_bprintf(AVBPrint *buf, const char *fmt, ...);
int av_bprint_is_complete(AVBPrint *buf);
void rstrip_spaces_buf(AVBPrint *buf);
int scantag(const char *in, char *buf, int *len);
unsigned html_color_parse(void *log_ctx, const char *str);
void av_strlcpy(char *dst, const char *src, size_t size);