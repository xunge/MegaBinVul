#include <stdio.h>
#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_write_state pdf_write_state;
typedef struct pdf_write_options pdf_write_options;
typedef struct pdf_obj pdf_obj;

#define PDF_NAME_Encrypt 0
#define SEEK_END 2
#define DEBUG_WRITING 0
#define DEBUG_LINEARIZATION 0

struct pdf_write_options {
    int do_incremental;
};

struct pdf_write_state {
    int *use_list;
    int *renumber_map;
    int *gen_list;
    int *ofs_list;
    int do_incremental;
    int do_garbage;
    int do_linear;
    int do_ascii;
    int crypt_object_number;
    int first_xref_offset;
    int main_xref_offset;
    int file_len;
    int hintstream_len;
    int page_count;
    int start;
    void *out;
};

struct pdf_document {
    int num_incremental_sections;
    int xref_base;
    int disallow_new_increments;
    int has_xref_streams;
    int dirty;
    int freeze_updates;
    struct {
        int end_ofs;
    } *xref_sections;
    void *crypt;
};

static int pdf_xref_len(fz_context *ctx, pdf_document *doc) { return 0; }
static void initialise_write_state(fz_context *ctx, pdf_document *doc, pdf_write_options *in_opts, pdf_write_state *opts) {}
static void pdf_ensure_solid_xref(fz_context *ctx, pdf_document *doc, int xref_len) {}
static void preloadobjstms(fz_context *ctx, pdf_document *doc) {}
static void change_identity(fz_context *ctx, pdf_document *doc) {}
static int markobj(fz_context *ctx, pdf_document *doc, pdf_write_state *opts, pdf_obj *obj) { return 0; }
static pdf_obj *pdf_trailer(fz_context *ctx, pdf_document *doc) { return NULL; }
static void removeduplicateobjs(fz_context *ctx, pdf_document *doc, pdf_write_state *opts) {}
static void compactxref(fz_context *ctx, pdf_document *doc, pdf_write_state *opts) {}
static pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *obj, int name) { return NULL; }
static int pdf_to_num(fz_context *ctx, pdf_obj *obj) { return 0; }
static void renumberobjs(fz_context *ctx, pdf_document *doc, pdf_write_state *opts) {}
static void linearize(fz_context *ctx, pdf_document *doc, pdf_write_state *opts) {}
static void writeobjects(fz_context *ctx, pdf_document *doc, pdf_write_state *opts, int flag) {}
static int pdf_xref_is_incremental(fz_context *ctx, pdf_document *doc, int num) { return 0; }
static void writexrefstream(fz_context *ctx, pdf_document *doc, pdf_write_state *opts, int a, int b, int c, int d, int e) {}
static void writexref(fz_context *ctx, pdf_document *doc, pdf_write_state *opts, int a, int b, int c, int d, int e) {}
static void make_hint_stream(fz_context *ctx, pdf_document *doc, pdf_write_state *opts) {}
static void update_linearization_params(fz_context *ctx, pdf_document *doc, pdf_write_state *opts) {}
static void padto(fz_context *ctx, void *out, int offset) {}
static void complete_signatures(fz_context *ctx, pdf_document *doc, pdf_write_state *opts) {}
static void finalise_write_state(fz_context *ctx, pdf_write_state *opts) {}

static void fz_seek_output(fz_context *ctx, void *out, int offset, int whence) {}
static void fz_write_string(fz_context *ctx, void *out, const char *str) {}
static int fz_tell_output(fz_context *ctx, void *out) { return 0; }
static void fz_rethrow(fz_context *ctx) {}

#define fz_try(ctx) if (1)
#define fz_always(ctx) if (1)
#define fz_catch(ctx) if (0)