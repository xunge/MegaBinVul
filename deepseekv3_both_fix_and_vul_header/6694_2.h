#include <stdint.h>
#include <limits.h>

#define PDF_MAX_OBJECT_NUMBER 8388607

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;

struct pdf_document {
    int has_xref_streams;
};
typedef struct pdf_document pdf_document;

typedef struct {
    char type;
    int64_t ofs;
    int gen;
    int num;
} pdf_xref_entry;

enum {
    FZ_ERROR_GENERIC
};

void fz_throw(fz_context *ctx, int error, const char *message);
pdf_xref_entry *pdf_xref_find_subsection(fz_context *ctx, pdf_document *doc, int64_t i0, int i1);
int fz_is_eof(fz_context *ctx, fz_stream *stm);
int fz_read_byte(fz_context *ctx, fz_stream *stm);