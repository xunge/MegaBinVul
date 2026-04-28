#include <stdio.h>
#include <stdlib.h>

#define IS_WHITE 0
#define IS_DELIM 1
#define RANGE_0_9 2
#define PDF_TOK_ERROR -1
#define PDF_TOK_REAL 0
#define PDF_TOK_INT 1

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;
typedef struct pdf_lexbuf pdf_lexbuf;

struct pdf_lexbuf {
    char *scratch;
    int size;
    float f;
    int i;
};

float acrobat_compatible_atof(const char *s);
float fz_atof(const char *s);
int fast_atoi(const char *s);
int fz_read_byte(fz_context *ctx, fz_stream *f);
void fz_unread_byte(fz_context *ctx, fz_stream *f);