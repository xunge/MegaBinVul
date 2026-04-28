#include <stdint.h>
#include <stddef.h>

typedef struct pdf_document pdf_document;
typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;
typedef struct pdf_lexbuf pdf_lexbuf;
typedef struct pdf_obj pdf_obj;

typedef enum {
    PDF_TOK_OPEN_ARRAY,
    PDF_TOK_OPEN_DICT,
    PDF_TOK_NAME,
    PDF_TOK_REAL,
    PDF_TOK_STRING,
    PDF_TOK_TRUE,
    PDF_TOK_FALSE,
    PDF_TOK_NULL,
    PDF_TOK_INT,
    PDF_TOK_STREAM,
    PDF_TOK_ENDOBJ,
    PDF_TOK_OBJ,
    PDF_TOK_R
} pdf_token;

#define PDF_MAX_OBJECT_NUMBER 8388607
#define FZ_ERROR_SYNTAX 1
#define PDF_TRUE ((pdf_obj *)1)
#define PDF_FALSE ((pdf_obj *)2)
#define PDF_NULL ((pdf_obj *)0)

struct pdf_lexbuf {
    int i;
    float f;
    char *scratch;
    int len;
};

extern pdf_token pdf_lex(fz_context *ctx, fz_stream *file, pdf_lexbuf *buf);
extern pdf_obj *pdf_parse_array(fz_context *ctx, pdf_document *doc, fz_stream *file, pdf_lexbuf *buf);
extern pdf_obj *pdf_parse_dict(fz_context *ctx, pdf_document *doc, fz_stream *file, pdf_lexbuf *buf);
extern pdf_obj *pdf_new_name(fz_context *ctx, const char *name);
extern pdf_obj *pdf_new_real(fz_context *ctx, float f);
extern pdf_obj *pdf_new_string(fz_context *ctx, const char *str, int len);
extern pdf_obj *pdf_new_int(fz_context *ctx, int64_t i);
extern pdf_obj *pdf_new_indirect(fz_context *ctx, pdf_document *doc, int num, int gen);
extern void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);
extern int fz_read_byte(fz_context *ctx, fz_stream *file);
extern int fz_peek_byte(fz_context *ctx, fz_stream *file);
extern int64_t fz_tell(fz_context *ctx, fz_stream *file);
extern void fz_var(void *);
extern void fz_throw(fz_context *ctx, int error_code, const char *fmt, ...);
extern void fz_warn(fz_context *ctx, const char *fmt, ...);
extern void fz_rethrow(fz_context *ctx);

#define fz_try(ctx) if (1)
#define fz_catch(ctx) else