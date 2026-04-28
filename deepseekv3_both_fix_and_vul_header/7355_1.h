#include <stddef.h>

typedef struct {
    int *data;
    int w, h;
    int dx, dy;
    int prec;
} opj_image_comp_t;

typedef struct {
    opj_image_comp_t *comps;
    int color_space;
    unsigned int x0, y0;
} opj_image_t;

enum {
    OPJ_CLRSPC_SRGB = 1
};

void* opj_image_data_alloc(size_t size);
void opj_image_data_free(void* ptr);
void sycc_to_rgb(int offset, int upb, int y, int cb, int cr, int *r, int *g, int *b);