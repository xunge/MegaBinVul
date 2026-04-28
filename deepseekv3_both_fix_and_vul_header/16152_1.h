#include <limits.h>
#include <stddef.h>

typedef struct fz_context fz_context;
typedef struct fz_colorspace fz_colorspace;
typedef struct fz_separations fz_separations;
typedef struct fz_pixmap fz_pixmap;

#define FZ_ERROR_GENERIC 1

int fz_count_active_separations(fz_context *ctx, fz_separations *seps);
int fz_colorspace_n(fz_context *ctx, fz_colorspace *colorspace);
void fz_throw(fz_context *ctx, int error_code, const char *message);
fz_pixmap *fz_new_pixmap_with_data(fz_context *ctx, fz_colorspace *colorspace, int w, int h, fz_separations *seps, int alpha, int stride, void *data);