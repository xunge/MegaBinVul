#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_obj pdf_obj;

void pdf_dict_put(fz_context *ctx, pdf_obj *obj, pdf_obj *key, pdf_obj *val);
void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);
void fz_rethrow(fz_context *ctx);

#define fz_try(ctx) 
#define fz_always(ctx) 
#define fz_catch(ctx)