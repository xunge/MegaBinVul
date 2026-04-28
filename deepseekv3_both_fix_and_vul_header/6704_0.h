#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct pdf_xref_entry pdf_xref_entry;

struct pdf_xref_entry {
    char type;
};

int pdf_xref_len(fz_context *ctx, pdf_document *doc);
pdf_xref_entry *pdf_get_xref_entry(fz_context *ctx, pdf_document *doc, int num);
pdf_obj *pdf_load_object(fz_context *ctx, pdf_document *doc, int num);
void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);