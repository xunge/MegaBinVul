#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct gs_memory_s {
    void *stable_memory;
} gs_memory_t;

typedef struct gs_matrix_s {
    double xx, xy, yx, yy, tx, ty;
} gs_matrix;

typedef struct gs_text_enum_s {
    void *dev;
    void *orig_font;
    void *current_font;
    struct {
        size_t size;
    } text;
    void *pgs;
} gs_text_enum_t;

typedef struct textw_text_enum_s {
    unsigned short *TextBuffer;
    float *Widths;
    struct {
        struct {
            double x;
            double y;
        } FontBBox_bottomleft;
        struct {
            double x;
            double y;
        } FontBBox_topright;
    } *text_state;
    struct {
        float total_width;
    } returned;
} textw_text_enum_t;

typedef struct gx_device_txtwrite_s {
    gs_memory_t *memory;
} gx_device_txtwrite_t;

typedef struct gs_font_s {
    int FontType;
} gs_font;

typedef struct gs_font_base_s {
    struct {
        struct {
            double x;
            double y;
        } p;
        struct {
            double x;
            double y;
        } q;
    } FontBBox;
    gs_matrix FontMatrix;
} gs_font_base;

typedef struct gs_point_s {
    double x;
    double y;
} gs_point;

enum {
    ft_CID_encrypted,
    ft_CID_TrueType,
    ft_composite,
    ft_encrypted,
    ft_encrypted2,
    ft_TrueType,
    ft_user_defined,
    ft_PCL_user_defined,
    ft_GL2_stick_user_defined,
    ft_GL2_531
};

#define gs_error_VMerror (-1)
#define gs_error_rangecheck (-15)

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

static void *gs_malloc(gs_memory_t *mem, size_t size, size_t elem_size, const char *name) {
    return malloc(size * elem_size);
}

static int gs_note_error(int code) { return code; }
static int return_error(int code) { return code; }
static double fixed2float(int fixed) { return (double)fixed; }
static gs_matrix ctm_only(void *pgs) { return (gs_matrix){0}; }
static void gs_matrix_multiply(const gs_matrix *a, const gs_matrix *b, gs_matrix *result) {}
static void gs_point_transform(double x, double y, const gs_matrix *mat, gs_point *pt) {}
static int txtwrite_process_cmap_text(gs_text_enum_t *pte) { return 0; }
static int txtwrite_process_plain_text(gs_text_enum_t *pte) { return 0; }
static int txt_shift_text_currentpoint(textw_text_enum_t *penum, float *width) { return 0; }
static int txt_add_fragment(gx_device_txtwrite_t *tdev, textw_text_enum_t *penum) { return 0; }