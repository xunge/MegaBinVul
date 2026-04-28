#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct fz_context fz_context;
typedef struct pdf_mark_list pdf_mark_list;
typedef struct pdf_obj pdf_obj;

typedef struct {
    pdf_obj *doc;
} globals;

enum {
    FZ_ERROR_GENERIC
};

#define PDF_NAME(x) #x
#define FONTS 0x1
#define IMAGES 0x2
#define XOBJS 0x4
#define SHADINGS 0x8
#define PATTERNS 0x10

static void gatherfonts(fz_context *ctx, globals *glo, int page, pdf_obj *pageref, pdf_obj *font);
static void gatherimages(fz_context *ctx, globals *glo, int page, pdf_obj *pageref, pdf_obj *xobj);
static void gatherforms(fz_context *ctx, globals *glo, int page, pdf_obj *pageref, pdf_obj *xobj);
static void gatherpsobjs(fz_context *ctx, globals *glo, int page, pdf_obj *pageref, pdf_obj *xobj);
static void gathershadings(fz_context *ctx, globals *glo, int page, pdf_obj *pageref, pdf_obj *shade);
static void gatherpatterns(fz_context *ctx, globals *glo, int page, pdf_obj *pageref, pdf_obj *pattern);

static int pdf_mark_list_push(fz_context *ctx, pdf_mark_list *mark_list, pdf_obj *obj);
static pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *obj, const char *key);
static pdf_obj *pdf_lookup_page_obj(fz_context *ctx, pdf_obj *doc, int page);
static int pdf_dict_len(fz_context *ctx, pdf_obj *obj);
static pdf_obj *pdf_dict_get_val(fz_context *ctx, pdf_obj *obj, int index);
static void fz_throw(fz_context *ctx, int error, const char *fmt, ...);