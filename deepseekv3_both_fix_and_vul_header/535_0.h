#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_filter_processor pdf_filter_processor;
typedef struct pdf_obj pdf_obj;

typedef struct {
    int pos;
    char *utf8;
} string_walker;

typedef struct tag_record {
    pdf_obj *mcid_obj;
    string_walker alt;
    string_walker actualtext;
} tag_record;

#define PDF_NAME(x) NULL

void walk_string(fz_context *ctx, int uni, int remove, string_walker *sw);
void pdf_dict_del(fz_context *ctx, pdf_obj *obj, void *name);
void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);
void fz_free(fz_context *ctx, void *p);