#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

typedef struct fz_context fz_context;
typedef struct pdf_lexbuf pdf_lexbuf;

typedef struct pdf_document {
    int startxref;
    int file_size;
} pdf_document;

typedef struct pdf_xref_entry {
    char type;
    int gen;
    int num;
    int64_t ofs;
} pdf_xref_entry;

enum {
    FZ_ERROR_GENERIC
};

typedef int64_t fz_off_t;

void pdf_read_start_xref(fz_context *ctx, pdf_document *doc);
void pdf_read_xref_sections(fz_context *ctx, pdf_document *doc, int startxref, pdf_lexbuf *buf, int flag);
int pdf_xref_len(fz_context *ctx, pdf_document *doc);
void fz_throw(fz_context *ctx, int error, const char *msg, ...);
void pdf_prime_xref_index(fz_context *ctx, pdf_document *doc);
pdf_xref_entry *pdf_get_xref_entry(fz_context *ctx, pdf_document *doc, int num);
void fz_warn(fz_context *ctx, const char *msg);