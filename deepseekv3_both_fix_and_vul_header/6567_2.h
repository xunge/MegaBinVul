#include <stdlib.h>
#include <string.h>

typedef struct fz_context fz_context;
typedef struct fz_buffer fz_buffer;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct pdf_write_state pdf_write_state;

struct pdf_xref_entry {
    pdf_obj *obj;
};

struct pdf_write_state {
    int *use_list;
    int *renumber_map;
    int *rev_renumber_map;
    int list_len;
    int do_garbage;
};

static inline int fz_mini(int a, int b) { return a < b ? a : b; }
static inline int fz_maxi(int a, int b) { return a > b ? a : b; }

#define fz_try(ctx) 
#define fz_catch(ctx) 
#define fz_always(ctx) 
#define fz_var(var) 
#define fz_rethrow(ctx) 

static int pdf_obj_num_is_stream(fz_context *ctx, pdf_document *doc, int num) { return 0; }
static int pdf_objcmp(fz_context *ctx, pdf_obj *a, pdf_obj *b) { return 0; }
static struct pdf_xref_entry *pdf_get_xref_entry(fz_context *ctx, pdf_document *doc, int num) { return NULL; }
static int pdf_xref_len(fz_context *ctx, pdf_document *doc) { return 0; }
static fz_buffer *pdf_load_raw_stream_number(fz_context *ctx, pdf_document *doc, int num) { return NULL; }
static void fz_drop_buffer(fz_context *ctx, fz_buffer *buf) {}
static size_t fz_buffer_storage(fz_context *ctx, fz_buffer *buf, unsigned char **datap) { return 0; }
static void expand_lists(fz_context *ctx, pdf_write_state *opts, int max_num) {}