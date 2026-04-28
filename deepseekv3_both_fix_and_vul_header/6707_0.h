#include <stdlib.h>

typedef struct fz_context fz_context;

typedef struct {
    int *use_list;
    int *ofs_list;
    int *gen_list;
    int *renumber_map;
    int *rev_renumber_map;
    int list_len;
} pdf_write_state;

void *fz_resize_array(fz_context *ctx, void *array, int count, size_t size);