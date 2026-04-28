#include <stdlib.h>

#define PDF_MAX_OBJECT_NUMBER 8388607
#define FZ_ERROR_GENERIC 1

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_xref pdf_xref;
typedef struct pdf_xref_subsec pdf_xref_subsec;
typedef struct pdf_xref_entry pdf_xref_entry;

struct pdf_xref_entry {
    int dummy;
};

struct pdf_xref_subsec {
    int start;
    int len;
    pdf_xref_entry *table;
    pdf_xref_subsec *next;
};

struct pdf_xref {
    pdf_xref_subsec *subsec;
};

struct pdf_document {
    int num_xref_sections;
    pdf_xref *xref_sections;
};

void fz_throw(fz_context *ctx, int error_code, const char *message, ...);
void *fz_malloc_struct(fz_context *ctx, size_t size);
void ensure_solid_xref(fz_context *ctx, pdf_document *doc, int num, int section);

#define fz_malloc_struct(ctx, type) ((type *)malloc(sizeof(type)))