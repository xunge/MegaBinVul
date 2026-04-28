#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct pdf_obj pdf_obj;
typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct fz_stream fz_stream;
typedef struct pdf_lexbuf pdf_lexbuf;

enum pdf_token {
    PDF_TOK_CLOSE_DICT,
    PDF_TOK_KEYWORD,
    PDF_TOK_NAME,
    PDF_TOK_OPEN_ARRAY,
    PDF_TOK_OPEN_DICT,
    PDF_TOK_REAL,
    PDF_TOK_STRING,
    PDF_TOK_TRUE,
    PDF_TOK_FALSE,
    PDF_TOK_NULL,
    PDF_TOK_INT,
    PDF_TOK_R
};

typedef enum pdf_token pdf_token;

struct pdf_lexbuf {
    char scratch[256];
    float f;
    int64_t i;
    int len;
};

pdf_obj *pdf_new_dict(fz_context *ctx, pdf_document *doc, int size);
pdf_obj *pdf_new_name(fz_context *ctx, pdf_document *doc, const char *name);
pdf_obj *pdf_new_real(fz_context *ctx, pdf_document *doc, float f);
pdf_obj *pdf_new_string(fz_context *ctx, pdf_document *doc, const char *str, int len);
pdf_obj *pdf_new_bool(fz_context *ctx, pdf_document *doc, int b);
pdf_obj *pdf_new_null(fz_context *ctx, pdf_document *doc);
pdf_obj *pdf_new_int(fz_context *ctx, pdf_document *doc, int64_t i);
pdf_obj *pdf_new_indirect(fz_context *ctx, pdf_document *doc, int64_t a, int64_t b);
void pdf_dict_put(fz_context *ctx, pdf_obj *dict, pdf_obj *key, pdf_obj *val);
void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);
pdf_token pdf_lex(fz_context *ctx, fz_stream *file, pdf_lexbuf *buf);
pdf_obj *pdf_parse_array(fz_context *ctx, pdf_document *doc, fz_stream *file, pdf_lexbuf *buf);

#define fz_var(var)
#define fz_try(ctx) if (1)
#define fz_catch(ctx) if (0)
#define fz_throw(ctx, err, msg) return NULL
#define fz_rethrow(ctx) return NULL