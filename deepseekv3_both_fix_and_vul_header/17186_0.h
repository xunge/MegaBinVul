#include <stdio.h>

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;

int fz_peek_byte(fz_context *ctx, fz_stream *stm);
int fz_read_byte(fz_context *ctx, fz_stream *stm);