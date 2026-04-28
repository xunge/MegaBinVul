#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;

typedef struct {
    int *renumber_map;
    int *rev_renumber_map;
    int *use_list;
    int list_len;
} pdf_write_state;

int pdf_xref_len(fz_context *ctx, pdf_document *doc);
void expand_lists(fz_context *ctx, pdf_write_state *opts, int new_len);