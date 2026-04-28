#include <stdint.h>
#include <stddef.h>

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;
typedef struct fz_buffer fz_buffer;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct pdf_xref_entry pdf_xref_entry;
typedef struct pdf_crypt pdf_crypt;

enum {
    PDF_NAME_Length
};

struct pdf_xref_entry {
    int num;
    int gen;
    fz_buffer *stm_buf;
};

struct pdf_document {
    pdf_crypt *crypt;
};

#define fz_var(chain) do {} while(0)
#define fz_try(ctx) if(1)
#define fz_catch(ctx) if(0)

static pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *obj, int key);
static int pdf_to_int(fz_context *ctx, pdf_obj *obj);
static int pdf_xref_len(fz_context *ctx, pdf_document *doc);
static pdf_xref_entry *pdf_get_xref_entry(fz_context *ctx, pdf_document *doc, int num);
static fz_stream *fz_open_buffer(fz_context *ctx, fz_buffer *buf);
static fz_stream *fz_keep_stream(fz_context *ctx, fz_stream *stm);
static fz_stream *fz_open_null(fz_context *ctx, fz_stream *stm, int len, int64_t offset);
static int pdf_stream_has_crypt(fz_context *ctx, pdf_obj *stmobj);
static fz_stream *pdf_open_crypt(fz_context *ctx, fz_stream *stm, pdf_crypt *crypt, int num, int gen);
static void fz_drop_stream(fz_context *ctx, fz_stream *stm);
static void fz_rethrow(fz_context *ctx);