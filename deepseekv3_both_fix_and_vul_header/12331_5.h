#include <stdlib.h>
#include <string.h>

typedef long long fz_off_t;

typedef struct fz_context fz_context;
typedef struct pdf_obj pdf_obj;
typedef struct pdf_xref_entry pdf_xref_entry;
typedef struct pdf_document pdf_document;
typedef struct pdf_lexbuf pdf_lexbuf;
typedef int pdf_token;

struct pdf_lexbuf {
    unsigned char *scratch;
    size_t size;
    int i;
};

struct entry {
    int num;
    int gen;
    fz_off_t ofs;
    fz_off_t stm_ofs;
    int stm_len;
};

struct pdf_document {
    void *file;
    int repair_attempted;
    int dirty;
    int freeze_updates;
    struct {
        pdf_lexbuf base;
    } lexbuf;
};

struct pdf_xref_entry {
    char type;
    fz_off_t ofs;
    int gen;
    int num;
    fz_off_t stm_ofs;
    pdf_obj *obj;
};

#define FZ_ERROR_GENERIC 1
#define FZ_ERROR_TRYLATER 2
#define MAX_OBJECT_NUMBER 1000000
#define PDF_NAME_Encrypt 0
#define PDF_NAME_ID 0
#define PDF_NAME_Root 0
#define PDF_NAME_Info 0
#define PDF_NAME_Length 0
#define PDF_NAME_Size 0
#define PDF_TOK_INT 0
#define PDF_TOK_OBJ 0
#define PDF_TOK_OPEN_DICT 0
#define PDF_TOK_EOF 0
#define PDF_TOK_ERROR 0

void fz_throw(fz_context *ctx, int error, const char *message);
void fz_warn(fz_context *ctx, const char *message, ...);
void *fz_malloc_array(fz_context *ctx, int count, size_t size);
void *fz_resize_array(fz_context *ctx, void *p, int count, size_t size);
void fz_free(fz_context *ctx, void *p);
fz_off_t fz_tell(fz_context *ctx, void *file);
void fz_seek(fz_context *ctx, void *file, fz_off_t offset, int whence);
size_t fz_read(fz_context *ctx, void *file, unsigned char *buf, size_t len);
int fz_read_byte(fz_context *ctx, void *file);
void fz_unread_byte(fz_context *ctx, void *file);
int fz_mini(int a, int b);
int fz_clampi(int x, int low, int high);

void pdf_ensure_solid_xref(fz_context *ctx, pdf_document *doc, int maxnum);
pdf_xref_entry *pdf_get_populating_xref_entry(fz_context *ctx, pdf_document *doc, int num);
int pdf_xref_len(fz_context *ctx, pdf_document *doc);
pdf_obj *pdf_trailer(fz_context *ctx, pdf_document *doc);
void pdf_set_populating_xref_trailer(fz_context *ctx, pdf_document *doc, pdf_obj *obj);
pdf_obj *pdf_load_object(fz_context *ctx, pdf_document *doc, int num);
pdf_obj *pdf_new_dict(fz_context *ctx, pdf_document *doc, int size);
pdf_obj *pdf_new_int(fz_context *ctx, pdf_document *doc, int i);
pdf_obj *pdf_new_indirect(fz_context *ctx, pdf_document *doc, int num, int gen);
void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);
pdf_obj *pdf_keep_obj(fz_context *ctx, pdf_obj *obj);
pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *dict, int key);
void pdf_dict_put(fz_context *ctx, pdf_obj *dict, int key, pdf_obj *val);
int pdf_is_dict(fz_context *ctx, pdf_obj *obj);
int pdf_is_indirect(fz_context *ctx, pdf_obj *obj);
int pdf_to_num(fz_context *ctx, pdf_obj *obj);
int pdf_to_gen(fz_context *ctx, pdf_obj *obj);
pdf_token pdf_lex_no_string(fz_context *ctx, void *file, pdf_lexbuf *buf);
pdf_obj *pdf_parse_dict(fz_context *ctx, pdf_document *doc, void *file, pdf_lexbuf *buf);
pdf_token pdf_repair_obj(fz_context *ctx, pdf_document *doc, pdf_lexbuf *buf, fz_off_t *stm_ofs, int *stm_len, pdf_obj **encrypt, pdf_obj **id, void *unused, fz_off_t *tmpofs, pdf_obj **root);
void add_root(fz_context *ctx, pdf_obj *root, pdf_obj ***roots, int *num_roots, int *max_roots);

#define fz_var(var)
#define fz_try(ctx)
#define fz_catch(ctx)
#define fz_always(ctx)
#define fz_rethrow(ctx)
#define fz_rethrow_if(ctx, cond)