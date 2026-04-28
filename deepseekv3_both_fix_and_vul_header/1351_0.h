#include <stddef.h>

typedef struct fz_context fz_context;

typedef struct {
    int x0, y0, x1, y1;
} fz_irect;

typedef struct {
    fz_irect ibounds;
    int colorspace;
    int format;
    int num_workers;
    int band_height_multiple;
    int bands_rendered;
    void *bander;
    int n;
} render_details;

enum {
    CS_GRAY,
    CS_RGB,
    CS_CMYK
};

enum {
    OUT_PGM,
    OUT_PPM,
    OUT_PAM,
    OUT_PBM,
    OUT_PKM
};

extern int output_cs;
extern int output_format;
extern int min_band_height;
extern size_t max_band_memory;
extern void *out;

void *fz_new_pnm_band_writer(fz_context *ctx, void *out);
void *fz_new_pam_band_writer(fz_context *ctx, void *out);
void *fz_new_pbm_band_writer(fz_context *ctx, void *out);
void *fz_new_pkm_band_writer(fz_context *ctx, void *out);