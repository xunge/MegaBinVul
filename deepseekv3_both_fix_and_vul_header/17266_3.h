#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_obj pdf_obj;
typedef struct pdf_font_desc pdf_font_desc;
typedef struct pdf_xobject pdf_xobject;
typedef struct fz_colorspace fz_colorspace;

typedef struct pdf_processor pdf_processor;
typedef struct pdf_csi pdf_csi;

struct pdf_processor {
    void (*op_w)(fz_context *ctx, pdf_processor *proc, float w);
    void (*op_J)(fz_context *ctx, pdf_processor *proc, int J);
    void (*op_j)(fz_context *ctx, pdf_processor *proc, int j);
    void (*op_M)(fz_context *ctx, pdf_processor *proc, float M);
    void (*op_d)(fz_context *ctx, pdf_processor *proc, pdf_obj *array, float phase);
    void (*op_ri)(fz_context *ctx, pdf_processor *proc, const char *ri);
    void (*op_i)(fz_context *ctx, pdf_processor *proc, float i);
    void (*op_Tf)(fz_context *ctx, pdf_processor *proc, const char *tag, pdf_font_desc *font, float size);
    void (*op_gs_OP)(fz_context *ctx, pdf_processor *proc, int OP);
    void (*op_gs_op)(fz_context *ctx, pdf_processor *proc, int op);
    void (*op_gs_OPM)(fz_context *ctx, pdf_processor *proc, int OPM);
    void (*op_gs_UseBlackPtComp)(fz_context *ctx, pdf_processor *proc, pdf_obj *obj);
    void (*op_gs_CA)(fz_context *ctx, pdf_processor *proc, float CA);
    void (*op_gs_ca)(fz_context *ctx, pdf_processor *proc, float ca);
    void (*op_gs_BM)(fz_context *ctx, pdf_processor *proc, const char *BM);
    void (*op_gs_SMask)(fz_context *ctx, pdf_processor *proc, pdf_xobject *xobj, pdf_obj *rdb, float *bc, int luminosity);
};

struct pdf_csi {
    void *doc;
    pdf_obj *rdb;
    void *cookie;
};

#define PDF_NAME_LW 0
#define PDF_NAME_LC 0
#define PDF_NAME_LJ 0
#define PDF_NAME_ML 0
#define PDF_NAME_D 0
#define PDF_NAME_RI 0
#define PDF_NAME_FL 0
#define PDF_NAME_Font 0
#define PDF_NAME_OP 0
#define PDF_NAME_op 0
#define PDF_NAME_OPM 0
#define PDF_NAME_UseBlackPtComp 0
#define PDF_NAME_TR2 0
#define PDF_NAME_Identity 0
#define PDF_NAME_Default 0
#define PDF_NAME_TR 0
#define PDF_NAME_CA 0
#define PDF_NAME_ca 0
#define PDF_NAME_BM 0
#define PDF_NAME_SMask 0
#define PDF_NAME_G 0
#define PDF_NAME_BC 0
#define PDF_NAME_S 0
#define PDF_NAME_Luminosity 0
#define PDF_NAME_None 0

#define FZ_MAX_COLORS 4
#define FZ_ERROR_SYNTAX 1

static int pdf_is_number(fz_context *ctx, pdf_obj *obj) { return 0; }
static int pdf_is_int(fz_context *ctx, pdf_obj *obj) { return 0; }
static int pdf_is_array(fz_context *ctx, pdf_obj *obj) { return 0; }
static int pdf_is_name(fz_context *ctx, pdf_obj *obj) { return 0; }
static int pdf_is_bool(fz_context *ctx, pdf_obj *obj) { return 0; }
static int pdf_is_dict(fz_context *ctx, pdf_obj *obj) { return 0; }
static pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *dict, int name) { return NULL; }
static pdf_obj *pdf_array_get(fz_context *ctx, pdf_obj *array, int index) { return NULL; }
static float pdf_to_real(fz_context *ctx, pdf_obj *obj) { return 0.0f; }
static int pdf_to_int(fz_context *ctx, pdf_obj *obj) { return 0; }
static int pdf_to_bool(fz_context *ctx, pdf_obj *obj) { return 0; }
static const char *pdf_to_name(fz_context *ctx, pdf_obj *obj) { return NULL; }
static int pdf_name_eq(fz_context *ctx, pdf_obj *a, int b) { return 0; }
static int pdf_to_num(fz_context *ctx, pdf_obj *obj) { return 0; }
static int fz_clampi(int a, int b, int c) { return 0; }
static pdf_font_desc *load_font_or_hail_mary(fz_context *ctx, void *doc, pdf_obj *rdb, pdf_obj *font_ref, int flags, void *cookie) { return NULL; }
static void pdf_drop_font(fz_context *ctx, pdf_font_desc *font) {}
static void fz_rethrow(fz_context *ctx) {}
static void fz_warn(fz_context *ctx, const char *msg) {}
static void fz_throw(fz_context *ctx, int error, const char *msg, ...) {}
static pdf_xobject *pdf_load_xobject(fz_context *ctx, void *doc, pdf_obj *obj) { return NULL; }
static fz_colorspace *pdf_xobject_colorspace(fz_context *ctx, pdf_xobject *xobj) { return NULL; }
static int fz_colorspace_n(fz_context *ctx, fz_colorspace *cs) { return 0; }
static int fz_colorspace_is_cmyk(fz_context *ctx, fz_colorspace *cs) { return 0; }
static void fz_drop_colorspace(fz_context *ctx, fz_colorspace *cs) {}
static void pdf_drop_xobject(fz_context *ctx, pdf_xobject *xobj) {}

#define fz_try(ctx) if(1)
#define fz_always(ctx) if(1)
#define fz_catch(ctx) if(0)
#define fz_var(var)