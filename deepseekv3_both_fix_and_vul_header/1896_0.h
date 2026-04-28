#include <stddef.h>

typedef unsigned char stbi_uc;

typedef struct {
    int img_x, img_y;
    int img_n;
} stbi__context;

typedef struct {
    stbi_uc *data;
    stbi_uc *linebuf;
    int id;
    int h, v;
    int tq;
    int x, y;
    int w2, h2;
    int coeff_w, coeff_h;
    short *coeff;
    void *raw_coeff;
    void *raw_data;
} stbi__jpeg_comp;

typedef struct {
    stbi__context *s;
    stbi__jpeg_comp img_comp[4];
    int img_h_max, img_v_max;
    int img_mcu_w, img_mcu_h;
    int img_mcu_x, img_mcu_y;
    int rgb;
    int progressive;
} stbi__jpeg;

#define STBI_MAX_DIMENSIONS (1 << 24)
#define STBI__SCAN_load 0

static int stbi__err(const char *str1, const char *str2);
static int stbi__get16be(stbi__context *s);
static unsigned char stbi__get8(stbi__context *s);
static int stbi__mad3sizes_valid(int a, int b, int c, int add);
static void *stbi__malloc_mad2(int a, int b, int add);
static void *stbi__malloc_mad3(int a, int b, int c, int add);
static int stbi__free_jpeg_components(stbi__jpeg *z, int n, int err);