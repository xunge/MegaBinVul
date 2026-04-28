#include <stdlib.h>
#include <string.h>

typedef struct fz_context fz_context;
typedef struct pdf_obj pdf_obj;

#define FZ_ERROR_GENERIC 1
#define PDF_OBJ_NULL ((pdf_obj *)0)
#define PDF_FLAGS_SORTED (1 << 0)
#define PDF_OBJ_NAME__LIMIT (1 << 8)

struct keyval {
    pdf_obj *k;
    pdf_obj *v;
};

struct dict {
    int len;
    int cap;
    struct keyval *items;
};

#define OBJ_IS_DICT(obj) ((obj)->type == PDF_DICT)
#define OBJ_IS_NAME(obj) ((obj)->type == PDF_NAME)
#define DICT(obj) ((struct dict *)(obj)->data)

enum pdf_obj_type {
    PDF_DICT,
    PDF_NAME
};

struct pdf_obj {
    int type;
    int flags;
    void *data;
};

void fz_throw(fz_context *ctx, int error, const char *msg, ...);
const char *pdf_objkindstr(pdf_obj *obj);
int pdf_dict_find(fz_context *ctx, pdf_obj *obj, pdf_obj *key);
int pdf_dict_finds(fz_context *ctx, pdf_obj *obj, const char *key);
void pdf_sort_dict(fz_context *ctx, pdf_obj *obj);
const char *pdf_to_name(fz_context *ctx, pdf_obj *obj);
void prepare_object_for_alteration(fz_context *ctx, pdf_obj *obj, pdf_obj *val);
void pdf_dict_grow(fz_context *ctx, pdf_obj *obj);
pdf_obj *pdf_keep_obj(fz_context *ctx, pdf_obj *obj);
void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);