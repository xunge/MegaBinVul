#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct fz_compression_params fz_compression_params;

static fz_stream *build_filter(fz_context *ctx, fz_stream *chain, pdf_document *doc, pdf_obj *f, pdf_obj *p, int num, int gen, fz_compression_params *params);

#define fz_try(ctx) 
#define fz_catch(ctx) 
#define fz_rethrow(ctx) 

void fz_drop_stream(fz_context *ctx, fz_stream *stm);

int pdf_array_len(fz_context *ctx, pdf_obj *array);
pdf_obj *pdf_array_get(fz_context *ctx, pdf_obj *array, int index);