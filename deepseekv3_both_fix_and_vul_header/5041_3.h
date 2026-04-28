#include <stdlib.h>
#include <stddef.h>

typedef struct fz_context fz_context;
typedef struct fz_document fz_document;
typedef struct fz_page fz_page;

typedef struct {
    void (*bound_page)(fz_context*, fz_page*);
    void (*run_page_contents)(fz_context*, fz_page*);
    void (*drop_page)(fz_context*, fz_page*);
} fz_page_derived;

typedef struct svg_document svg_document;

typedef struct svg_page {
    fz_page_derived super;
    svg_document *doc;
} svg_page;

enum {
    FZ_ERROR_GENERIC
};

void fz_throw(fz_context *ctx, int error, const char *fmt, ...);
fz_page *fz_new_derived_page(fz_context *ctx, size_t size);
void svg_bound_page(fz_context *ctx, fz_page *page);
void svg_run_page(fz_context *ctx, fz_page *page);
void svg_drop_page(fz_context *ctx, fz_page *page);

#define fz_new_derived_page(ctx, type) ((type *)fz_new_derived_page(ctx, sizeof(type)))