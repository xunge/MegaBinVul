#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;

struct pdf_xobject {
    int refs;
    pdf_obj *obj;
    int iteration;
};

typedef struct pdf_xobject pdf_xobject;

void pdf_store_item(fz_context *ctx, pdf_obj *dict, void *item, size_t size);
void *pdf_find_item(fz_context *ctx, void (*drop)(fz_context *, void *), pdf_obj *dict);
void pdf_drop_xobject_imp(fz_context *ctx, void *form);
size_t pdf_xobject_size(pdf_xobject *form);
pdf_obj *pdf_keep_obj(fz_context *ctx, pdf_obj *obj);
void *fz_malloc(fz_context *ctx, size_t size);
int pdf_is_stream(fz_context *ctx, pdf_obj *dict);
void fz_throw(fz_context *ctx, int error, const char *message);

#define FZ_INIT_STORABLE(ptr, initial_refs, drop_fn) \
    do { \
        ((pdf_xobject *)(ptr))->refs = (initial_refs); \
    } while (0)

#define fz_malloc_struct(ctx, type) ((type *)fz_malloc(ctx, sizeof(type)))

enum { FZ_ERROR_SYNTAX };