#include <stdio.h>
#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_write_state pdf_write_state;
typedef struct pdf_write_options pdf_write_options;
typedef struct fz_output fz_output;

struct pdf_write_options {
    int do_incremental;
};

struct pdf_write_state {
    fz_output *out;
    int do_incremental;
    int do_garbage;
    int do_linear;
    int *use_list;
    int *gen_list;
    int64_t *ofs_list;
    int page_count;
    int64_t first_xref_offset;
    int64_t main_xref_offset;
    int64_t file_len;
    int64_t hintstream_len;
    int do_ascii;
    int start;
};

struct pdf_document {
    int num_incremental_sections;
    int xref_base;
    int disallow_new_increments;
    int has_xref_streams;
    int dirty;
    int freeze_updates;
    struct {
        int64_t end_ofs;
    } *xref_sections;
};

#define fz_try(ctx) do {
#define fz_always(ctx) } while (0); do {
#define fz_catch(ctx) } while (0); if (0)

void fz_seek_output(fz_context *ctx, fz_output *out, long offset, int whence);
void fz_write_string(fz_context *ctx, fz_output *out, const char *str);
int pdf_xref_len(fz_context *ctx, pdf_document *doc);
void fz_rethrow(fz_context *ctx);
int64_t fz_tell_output(fz_context *ctx, fz_output *out);