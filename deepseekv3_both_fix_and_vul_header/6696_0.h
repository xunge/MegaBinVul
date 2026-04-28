#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_xref_entry pdf_xref_entry;

#define PDF_MAX_OBJECT_NUMBER 8388607
#define FZ_ERROR_GENERIC 1

struct pdf_xref_entry {
    char type;
    int ofs;
    int gen;
    int num;
    int stm_ofs;
    void *stm_buf;
    void *obj;
};

int pdf_xref_len(fz_context *ctx, pdf_document *doc);
pdf_xref_entry *pdf_get_incremental_xref_entry(fz_context *ctx, pdf_document *doc, int num);
void fz_throw(fz_context *ctx, int error_code, const char *message);