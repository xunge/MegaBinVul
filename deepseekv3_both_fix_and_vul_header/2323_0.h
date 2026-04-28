#include <stddef.h>

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;
typedef long long fz_off_t;

typedef struct {
    int type;
    fz_off_t ofs;
    int gen;
    int num;
} pdf_xref_entry;

typedef struct {
    int has_xref_streams;
} pdf_document;

#define FZ_ERROR_GENERIC 1

pdf_xref_entry *pdf_xref_find_subsection(fz_context *ctx, pdf_document *doc, fz_off_t i0, int i1);
int fz_is_eof(fz_context *ctx, fz_stream *stm);
int fz_read_byte(fz_context *ctx, fz_stream *stm);
void fz_throw(fz_context *ctx, int error, const char *message);