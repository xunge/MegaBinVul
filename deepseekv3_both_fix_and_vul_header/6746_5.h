#include <stdint.h>
#include <stddef.h>

typedef struct pdf_obj pdf_obj;
typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct fz_stream fz_stream;
typedef struct pdf_lexbuf pdf_lexbuf;

enum pdf_token {
    PDF_TOK_INT,
    PDF_TOK_OBJ,
    PDF_TOK_OPEN_ARRAY,
    PDF_TOK_OPEN_DICT,
    PDF_TOK_NAME,
    PDF_TOK_REAL,
    PDF_TOK_STRING,
    PDF_TOK_TRUE,
    PDF_TOK_FALSE,
    PDF_TOK_NULL,
    PDF_TOK_STREAM,
    PDF_TOK_ENDOBJ,
    PDF_TOK_R
};

#define PDF_MAX_OBJECT_NUMBER 8388607
#define FZ_ERROR_SYNTAX 1

struct pdf_lexbuf {
    int i;
    float f;
    char *scratch;
    int len;
};

typedef enum pdf_token pdf_token;

void fz_var(void *);
void fz_throw(fz_context *, int, const char *, ...);
void fz_warn(fz_context *, const char *, ...);
pdf_token pdf_lex(fz_context *, fz_stream *, pdf_lexbuf *);
pdf_obj *pdf_parse_array(fz_context *, pdf_document *, fz_stream *, pdf_lexbuf *);
pdf_obj *pdf_parse_dict(fz_context *, pdf_document *, fz_stream *, pdf_lexbuf *);
pdf_obj *pdf_new_name(fz_context *, pdf_document *, const char *);
pdf_obj *pdf_new_real(fz_context *, pdf_document *, float);
pdf_obj *pdf_new_string(fz_context *, pdf_document *, const char *, int);
pdf_obj *pdf_new_bool(fz_context *, pdf_document *, int);
pdf_obj *pdf_new_null(fz_context *, pdf_document *);
pdf_obj *pdf_new_int(fz_context *, pdf_document *, int64_t);
pdf_obj *pdf_new_indirect(fz_context *, pdf_document *, int64_t, int64_t);
void pdf_drop_obj(fz_context *, pdf_obj *);
int fz_read_byte(fz_context *, fz_stream *);
int fz_peek_byte(fz_context *, fz_stream *);
int64_t fz_tell(fz_context *, fz_stream *);
void fz_rethrow(fz_context *);
#define fz_try(ctx) if (1)
#define fz_catch(ctx) else