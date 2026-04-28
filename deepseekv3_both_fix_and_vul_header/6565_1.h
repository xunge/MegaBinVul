#include <stdint.h>
#include <limits.h>
#include <stddef.h>

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
    int64_t *ofs_list;
    int *gen_list;
    int *renumber_map;
    int *rev_renumber_map;
    int continue_on_error;
    int errors;
} pdf_write_state;

int pdf_xref_len(fz_context *ctx, pdf_document *doc);
void *fz_malloc_array(fz_context *ctx, int count, size_t size);
void *fz_calloc(fz_context *ctx, int count, size_t size);
void expand_lists(fz_context *ctx, pdf_write_state *opts, int len);