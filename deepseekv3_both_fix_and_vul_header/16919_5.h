#include <stdlib.h>

#define FW_START 0
#define FW_SAME 1
#define FW_RUN 2

typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct fz_context fz_context;
typedef struct fz_font fz_font;

struct FT_FaceRec_ {
    int num_glyphs;
};

typedef struct FT_FaceRec_* FT_Face;

struct fz_font {
    FT_Face ft_face;
    int *width_table;
    int width_default;
};

void fz_var(void*);
void fz_try(fz_context*);
void fz_catch(fz_context*);
void fz_rethrow(fz_context*);
void fz_always(fz_context*, void (*)(void*));

pdf_obj* pdf_add_new_array(fz_context*, pdf_document*, int);
int fz_advance_glyph(fz_context*, fz_font*, int, int);
pdf_obj* pdf_new_array(fz_context*, pdf_document*, int);
void pdf_array_push_int(fz_context*, pdf_obj*, int);
void pdf_array_push(fz_context*, pdf_obj*, pdf_obj*);
int pdf_array_len(fz_context*, pdf_obj*);
void pdf_drop_obj(fz_context*, pdf_obj*);
void pdf_dict_put_int(fz_context*, pdf_obj*, const char*, int);
void pdf_dict_put(fz_context*, pdf_obj*, const char*, pdf_obj*);

#define PDF_NAME(x) #x

#define fz_try(ctx) do {
#define fz_catch(ctx) } while(0); if(0) {
#define fz_always(ctx) } while(0); {
#define fz_rethrow(ctx) } while(0)