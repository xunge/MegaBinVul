#include <stdint.h>
#include <stddef.h>

typedef struct pdf_obj pdf_obj;
typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct fz_stream fz_stream;
typedef struct pdf_lexbuf pdf_lexbuf;

typedef enum {
    PDF_TOK_CLOSE_ARRAY,
    PDF_TOK_INT,
    PDF_TOK_R,
    PDF_TOK_OPEN_ARRAY,
    PDF_TOK_OPEN_DICT,
    PDF_TOK_NAME,
    PDF_TOK_REAL,
    PDF_TOK_STRING,
    PDF_TOK_TRUE,
    PDF_TOK_FALSE,
    PDF_TOK_NULL
} pdf_token;

struct pdf_lexbuf {
    int64_t i;
    double f;
    char *scratch;
    size_t len;
};

enum {
    FZ_ERROR_SYNTAX
};

#define fz_var(x) do {} while(0)
#define fz_try(ctx) if(1)
#define fz_catch(ctx) else