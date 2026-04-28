#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct fz_color_converter fz_color_converter;
typedef struct fz_colorspace fz_colorspace;
typedef struct fz_color_params fz_color_params;
typedef struct fz_cached_color_converter fz_cached_color_converter;
typedef struct fz_hash_table fz_hash_table;

#define FZ_ENABLE_ICC 1
#define FZ_HASH_TABLE_KEY_LENGTH 16
#define fz_malloc_struct(ctx, type) ((type *)malloc(sizeof(type)))

struct fz_color_converter {
    void *opaque;
    void (*convert)(fz_context *ctx, fz_color_converter *cc, const float *src, float *dst);
    fz_colorspace *ss;
    fz_colorspace *ds;
#if FZ_ENABLE_ICC
    void *link;
#endif
};

struct fz_colorspace {
    int n;
};

struct fz_color_params {
    int dummy;
};

struct fz_cached_color_converter {
    fz_color_converter base;
    fz_hash_table *hash;
};

void fz_free(fz_context *ctx, void *p);
void fz_warn(fz_context *ctx, const char *fmt, ...);
void fz_rethrow(fz_context *ctx);
void fz_find_color_converter(fz_context *ctx, fz_color_converter *cc, fz_colorspace *ss, fz_colorspace *ds, fz_colorspace *is, fz_color_params params);
void fz_drop_color_converter(fz_context *ctx, fz_color_converter *cc);
fz_hash_table *fz_new_hash_table(fz_context *ctx, int initialsize, int keysize, int valsize, void (*drop_val)(fz_context *ctx, void *val));
void fz_drop_hash_table(fz_context *ctx, fz_hash_table *table);
void fz_cached_color_convert(fz_context *ctx, fz_color_converter *cc, const float *src, float *dst);

#define fz_try(ctx) do {
#define fz_catch(ctx) } while (0); if (0)