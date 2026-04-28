#include <stdlib.h>
#include <string.h>

typedef struct fz_context fz_context;
typedef struct pdf_obj pdf_obj;

typedef struct {
    int *list;
    int len;
    int max;
    int local_list[32];
} pdf_mark_list;

int pdf_to_num(fz_context *ctx, pdf_obj *obj);
void *fz_malloc_array(fz_context *ctx, int count, size_t size);
void *fz_realloc_array(fz_context *ctx, void *ptr, int count, size_t size);

#define fz_malloc_array(ctx, count, type) fz_malloc_array(ctx, count, sizeof(type))
#define fz_realloc_array(ctx, ptr, count, type) fz_realloc_array(ctx, ptr, count, sizeof(type))