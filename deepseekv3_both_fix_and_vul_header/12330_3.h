#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct fz_stream fz_stream;
typedef struct pdf_crypt pdf_crypt;
typedef struct fz_font fz_font;

struct pdf_lexbuf {
    void *base;
};

struct pdf_document {
    void *js;
    void *xref_index;
    pdf_obj *focus_obj;
    fz_stream *file;
    pdf_crypt *crypt;
    pdf_obj *linear_obj;
    pdf_obj **linear_page_refs;
    int page_count;
    void *hint_page;
    void *hint_shared_ref;
    void *hint_shared;
    void *hint_obj_offsets;
    fz_font **type3_fonts;
    int num_type3_fonts;
    void *ocg;
    struct pdf_lexbuf lexbuf;
    pdf_obj **orphans;
    int orphans_count;
};

#define fz_try(ctx) if (1)
#define fz_always(ctx) if (1)
#define fz_catch(ctx) if (0)

void fz_defer_reap_start(fz_context *ctx);
void fz_purge_glyph_cache(fz_context *ctx);
void pdf_drop_js(fz_context *ctx, void *js);
void pdf_drop_xref_sections(fz_context *ctx, pdf_document *doc);
void fz_free(fz_context *ctx, void *p);
void pdf_drop_obj(fz_context *ctx, pdf_obj *obj);
void fz_drop_stream(fz_context *ctx, fz_stream *stm);
void pdf_drop_crypt(fz_context *ctx, pdf_crypt *crypt);
void fz_decouple_type3_font(fz_context *ctx, fz_font *font, void *doc);
void fz_drop_font(fz_context *ctx, fz_font *font);
void pdf_drop_ocg(fz_context *ctx, void *ocg);
void pdf_empty_store(fz_context *ctx, pdf_document *doc);
void pdf_lexbuf_fin(fz_context *ctx, void *base);
void pdf_drop_resource_tables(fz_context *ctx, pdf_document *doc);
void fz_defer_reap_end(fz_context *ctx);
void fz_rethrow(fz_context *ctx);