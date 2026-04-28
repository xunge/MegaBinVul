#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;
typedef struct fz_buffer fz_buffer;
typedef struct pdf_document pdf_document;

typedef struct pdf_lexbuf {
    int i;
} pdf_lexbuf;

typedef struct pdf_obj pdf_obj;

typedef struct pdf_xref_entry {
    char type;
    int ofs;
    pdf_obj *obj;
    fz_buffer *stm_buf;
} pdf_xref_entry;

typedef enum {
    PDF_TOK_INT,
} pdf_token;

#define PDF_NAME_N NULL
#define PDF_NAME_First NULL

#define FZ_ERROR_GENERIC 1

#define SEEK_SET 0

#define fz_var(x) 
#define fz_try(ctx) if (1)
#define fz_always(ctx) if (1)
#define fz_catch(ctx) if (0)
#define fz_throw(ctx, code, ...) 
#define fz_warn(ctx, ...) 

static inline void *fz_calloc(fz_context *ctx, int count, size_t size) { return calloc(count, size); }
static inline void fz_free(fz_context *ctx, void *p) { free(p); }
static inline void fz_seek(fz_context *ctx, fz_stream *stm, int64_t off, int whence) {}
static inline void fz_drop_stream(fz_context *ctx, fz_stream *stm) {}
static inline void fz_drop_buffer(fz_context *ctx, fz_buffer *buf) {}
static inline void fz_rethrow(fz_context *ctx) {}

static inline pdf_obj *pdf_load_object(fz_context *ctx, pdf_document *doc, int num) { return NULL; }
static inline int pdf_to_int(fz_context *ctx, pdf_obj *obj) { return 0; }
static inline pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *obj, void *name) { return NULL; }
static inline fz_stream *pdf_open_stream_number(fz_context *ctx, pdf_document *doc, int num) { return NULL; }
static inline pdf_token pdf_lex(fz_context *ctx, fz_stream *stm, pdf_lexbuf *buf) { return PDF_TOK_INT; }
static inline int pdf_xref_len(fz_context *ctx, pdf_document *doc) { return 0; }
static inline pdf_obj *pdf_parse_stm_obj(fz_context *ctx, pdf_document *doc, fz_stream *stm, pdf_lexbuf *buf) { return NULL; }
static inline void pdf_drop_obj(fz_context *ctx, pdf_obj *obj) {}
static inline pdf_xref_entry *pdf_get_xref_entry(fz_context *ctx, pdf_document *doc, int num) { return NULL; }
static inline void pdf_set_obj_parent(fz_context *ctx, pdf_obj *obj, int num) {}
static inline int pdf_objcmp(fz_context *ctx, pdf_obj *a, pdf_obj *b) { return 0; }