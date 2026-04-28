#include <stdint.h>
#include <stddef.h>

typedef struct fz_context fz_context;
typedef struct fz_stream fz_stream;
typedef struct pdf_document pdf_document;
typedef struct pdf_lexbuf pdf_lexbuf;
typedef struct pdf_obj pdf_obj;

struct pdf_xref_entry {
    int num;
    int gen;
    int64_t ofs;
    int64_t stm_ofs;
    char type;
    pdf_obj *obj;
};

typedef struct pdf_xref_entry pdf_xref_entry;

#define PDF_NAME(x) NULL
#define FZ_ERROR_GENERIC 0

#define fz_var(x) 
#define fz_try(ctx) 
#define fz_catch(ctx) 
#define fz_always(ctx) 
#define fz_throw(ctx, err, ...) 
#define fz_warn(ctx, ...) 
#define fz_rethrow(ctx) 
#define fz_tell(ctx, file) 0
#define fz_drop_stream(ctx, stm) 

#define pdf_parse_ind_obj(ctx, doc, file, buf, num, gen, stm_ofs, obj) NULL
#define pdf_drop_obj(ctx, obj) 
#define pdf_dict_get(ctx, dict, key) NULL
#define pdf_to_int(ctx, obj) 0
#define pdf_array_get_int(ctx, array, index) 0
#define pdf_array_len(ctx, array) 0
#define pdf_open_stream_with_offset(ctx, doc, num, trailer, stm_ofs) NULL
#define pdf_read_new_xref_section(ctx, doc, stm, i0, i1, w0, w1, w2) 
#define pdf_get_populating_xref_entry(ctx, doc, num) ((pdf_xref_entry*)0)
#define pdf_keep_obj(ctx, obj) NULL