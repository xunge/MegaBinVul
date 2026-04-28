#include <string.h>
#include <stdlib.h>

typedef unsigned char stbi_uc;

typedef struct {
    int w, h;
    stbi_uc *out;
    void *history;
    void *background;
} stbi__gif;

typedef struct {
    // Define necessary fields for stbi__context
} stbi__context;

typedef struct {
    // Define necessary fields for stbi__result_info
} stbi__result_info;

#define STBI_NOTUSED(x) (void)(x)
#define STBI_FREE(p) free(p)

static stbi_uc *stbi__gif_load_next(stbi__context *s, stbi__gif *g, int *comp, int req_comp, int info);
static stbi_uc *stbi__convert_format(stbi_uc *data, int img_n, int req_comp, int x, int y);