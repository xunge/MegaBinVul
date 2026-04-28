#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct fz_shade fz_shade;

#define FZ_MAX_COLORS 4
#define PDF_NAME_VerticesPerRow ((pdf_obj*)1)
#define PDF_NAME_BitsPerFlag ((pdf_obj*)2)
#define PDF_NAME_BitsPerCoordinate ((pdf_obj*)3) 
#define PDF_NAME_BitsPerComponent ((pdf_obj*)4)
#define PDF_NAME_Decode ((pdf_obj*)5)

struct fz_shade {
    int type;
    union {
        struct {
            float x0, y0;
            float x1, y1;
            float c0[FZ_MAX_COLORS];
            float c1[FZ_MAX_COLORS];
            int vprow;
            int bpflag;
            int bpcoord;
            int bpcomp;
        } m;
    } u;
};

int pdf_to_int(fz_context *ctx, pdf_obj *obj);
float pdf_to_real(fz_context *ctx, pdf_obj *obj);
pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *dict, pdf_obj *name);
int pdf_array_len(fz_context *ctx, pdf_obj *array);
pdf_obj *pdf_array_get(fz_context *ctx, pdf_obj *array, int index);
void fz_warn(fz_context *ctx, const char *fmt, ...);