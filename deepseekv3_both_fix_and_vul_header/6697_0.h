#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>

#define MAX_OBJECT_NUMBER 8388607
#define PDF_MAX_OBJECT_NUMBER MAX_OBJECT_NUMBER

struct entry {
    int num;
    int gen;
    int64_t ofs;
    int64_t stm_ofs;
    int stm_len;
};

typedef struct pdf_obj pdf_obj;
typedef struct pdf_document {
    void *file;
    struct {
        struct {
            unsigned char *scratch;
            int size;
            int i;
        } base;
    } lexbuf;
    int repair_attempted;
    int dirty;
    int freeze_updates;
} pdf_document;
typedef struct fz_context fz_context;
typedef struct pdf_lexbuf {
    unsigned char *scratch;
    int size;
    int i;
} pdf_lexbuf;
typedef struct pdf_xref_entry {
    char type;
    int64_t ofs;
    int gen;
    int num;
    int64_t stm_ofs;
    pdf_obj *obj;
} pdf_xref_entry;

enum pdf_token {
    PDF_TOK_ERROR,
    PDF_TOK_EOF,
    PDF_TOK_OPEN_DICT,
    PDF_TOK_CLOSE_DICT,
    PDF_TOK_OPEN_ARRAY,
    PDF_TOK_CLOSE_ARRAY,
    PDF_TOK_NAME,
    PDF_TOK_INT,
    PDF_TOK_REAL,
    PDF_TOK_STRING,
    PDF_TOK_KEYWORD,
    PDF_TOK_R,
    PDF_TOK_TRUE,
    PDF_TOK_FALSE,
    PDF_TOK_NULL,
    PDF_TOK_OBJ,
    PDF_TOK_ENDOBJ,
    PDF_TOK_STREAM,
    PDF_TOK_ENDSTREAM,
    PDF_TOK_XREF,
    PDF_TOK_TRAILER,
    PDF_TOK_STARTXREF,
    PDF_TOK_N
};

typedef enum pdf_token pdf_token;

#define PDF_NAME_Encrypt 0
#define PDF_NAME_ID 1
#define PDF_NAME_Root 2
#define PDF_NAME_Info 3
#define PDF_NAME_Length 4
#define PDF_NAME_Size 5

#define FZ_ERROR_GENERIC 1
#define FZ_ERROR_TRYLATER 2

#define fz_var(var) do { (void)var; } while (0)
#define fz_warn(ctx, ...) do {} while (0)
#define fz_throw(ctx, code, ...) do {} while (0)
#define fz_rethrow(ctx) do {} while (0)
#define fz_rethrow_if(ctx, code) do {} while (0)
#define fz_try(ctx) if (1)
#define fz_catch(ctx) else
#define fz_always(ctx) if (1)
#define fz_mini(a, b) ((a) < (b) ? (a) : (b))
#define fz_clampi(x, lo, hi) ((x) < (lo) ? (lo) : (x) > (hi) ? (hi) : (x))

static inline int is_white(int ch) {
    return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

static inline void *fz_malloc_array(fz_context *ctx, int count, size_t size) {
    return malloc(count * size);
}
static inline void *fz_resize_array(fz_context *ctx, void *p, int count, size_t size) {
    return realloc(p, count * size);
}
static inline void fz_free(fz_context *ctx, void *p) {
    free(p);
}
static inline int64_t fz_tell(fz_context *ctx, void *file) {
    return 0;
}
static inline void fz_seek(fz_context *ctx, void *file, int64_t offset, int whence) {}
static inline size_t fz_read(fz_context *ctx, void *file, unsigned char *buf, size_t len) {
    return 0;
}
static inline int fz_read_byte(fz_context *ctx, void *file) {
    return EOF;
}
static inline void fz_unread_byte(fz_context *ctx, void *file) {}

static inline pdf_token pdf_lex_no_string(fz_context *ctx, void *file, pdf_lexbuf *buf) {
    return PDF_TOK_EOF;
}
static inline pdf_obj *pdf_parse_dict(fz_context *ctx, pdf_document *doc, void *file, pdf_lexbuf *buf) {
    return NULL;
}
static inline pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *dict, int name) {
    return NULL;
}
static inline void pdf_drop_obj(fz_context *ctx, pdf_obj *obj) {}
static inline pdf_obj *pdf_keep_obj(fz_context *ctx, pdf_obj *obj) {
    return NULL;
}
static inline void add_root(fz_context *ctx, pdf_obj *root, pdf_obj ***roots, int *num_roots, int *max_roots) {}
static inline void pdf_forget_xref(fz_context *ctx, pdf_document *doc) {}
static inline pdf_xref_entry *pdf_get_populating_xref_entry(fz_context *ctx, pdf_document *doc, int num) {
    return NULL;
}
static inline void pdf_ensure_solid_xref(fz_context *ctx, pdf_document *doc, int maxnum) {}
static inline pdf_obj *pdf_load_object(fz_context *ctx, pdf_document *doc, int num) {
    return NULL;
}
static inline pdf_obj *pdf_new_int(fz_context *ctx, pdf_document *doc, int val) {
    return NULL;
}
static inline void pdf_dict_get_put_drop(fz_context *ctx, pdf_obj *dict, int name, pdf_obj *obj, pdf_obj **old_obj) {}
static inline void orphan_object(fz_context *ctx, pdf_document *doc, pdf_obj *obj) {}
static inline int pdf_xref_len(fz_context *ctx, pdf_document *doc) {
    return 0;
}
static inline pdf_obj *pdf_new_dict(fz_context *ctx, pdf_document *doc, int size) {
    return NULL;
}
static inline void pdf_set_populating_xref_trailer(fz_context *ctx, pdf_document *doc, pdf_obj *obj) {}
static inline pdf_obj *pdf_trailer(fz_context *ctx, pdf_document *doc) {
    return NULL;
}
static inline void pdf_dict_put(fz_context *ctx, pdf_obj *dict, int name, pdf_obj *obj) {}
static inline int pdf_is_dict(fz_context *ctx, pdf_obj *obj) {
    return 0;
}
static inline int pdf_is_indirect(fz_context *ctx, pdf_obj *obj) {
    return 0;
}
static inline pdf_obj *pdf_new_indirect(fz_context *ctx, pdf_document *doc, int num, int gen) {
    return NULL;
}
static inline int pdf_to_num(fz_context *ctx, pdf_obj *obj) {
    return 0;
}
static inline int pdf_to_gen(fz_context *ctx, pdf_obj *obj) {
    return 0;
}
static inline pdf_token pdf_repair_obj(fz_context *ctx, pdf_document *doc, pdf_lexbuf *buf, int64_t *stm_ofs, int *stm_len, pdf_obj **encrypt, pdf_obj **id, void *unused, int64_t *tmpofs, pdf_obj **root) {
    return PDF_TOK_EOF;
}