#include <stdlib.h>
#include <string.h>

typedef struct pdf_obj pdf_obj;
typedef struct fz_context fz_context;

struct pdf_processor;

typedef struct tag_record {
    int bdc;
    char *tag;
    pdf_obj *raw;
    pdf_obj *cooked;
    struct tag_record *prev;
    int mcid_num;
    pdf_obj *mcid_obj;
    struct {
        char *utf8;
    } alt;
    struct {
        char *utf8;
    } actualtext;
} tag_record;

struct pdf_filter_processor {
    struct pdf_processor *super;
    tag_record *pending_tags;
    pdf_obj *structarray;
};

typedef struct pdf_processor pdf_processor;
typedef struct pdf_filter_processor pdf_filter_processor;

#define PDF_NAME(x) ((pdf_obj*)0)
#define fz_malloc_struct(ctx, type) ((type*)malloc(sizeof(type)))
#define fz_strdup(ctx, str) strdup(str)
#define pdf_keep_obj(ctx, obj) (obj)
#define pdf_drop_obj(ctx, obj)
#define fz_free(ctx, ptr) free(ptr)
#define fz_try(ctx)
#define fz_catch(ctx)
#define fz_rethrow(ctx)
#define pdf_dict_get(ctx, obj, key) (NULL)
#define pdf_is_number(ctx, obj) (0)
#define pdf_to_int(ctx, obj) (0)
#define pdf_array_get(ctx, obj, idx) (NULL)
#define pdf_new_utf8_from_pdf_string_obj(ctx, obj) (NULL)