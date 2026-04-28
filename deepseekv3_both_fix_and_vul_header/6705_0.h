#include <stdlib.h>
#include <limits.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;

typedef struct {
    int do_incremental;
    int do_ascii;
    int do_pretty;
    int do_decompress;
    int do_compress;
    int do_compress_images;
    int do_compress_fonts;
    int do_garbage;
    int do_linear;
    int do_clean;
    int continue_on_error;
    int errors;
} pdf_write_options;

typedef struct {
    int do_incremental;
    int do_ascii;
    int do_tight;
    int do_expand;
    int do_compress;
    int do_compress_images;
    int do_compress_fonts;
    int do_garbage;
    int do_linear;
    int do_clean;
    int start;
    int main_xref_offset;
    int list_len;
    int *use_list;
    int *ofs_list;
    int *gen_list;
    int *renumber_map;
    int *rev_renumber_map;
    int continue_on_error;
    int errors;
} pdf_write_state;

int pdf_xref_len(fz_context *ctx, pdf_document *doc);
void expand_lists(fz_context *ctx, pdf_write_state *opts, int len);