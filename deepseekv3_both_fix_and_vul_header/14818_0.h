#include <stddef.h>
#include <stdlib.h>

typedef unsigned char guchar;
typedef int gboolean;
typedef enum {
    PIXOPS_INTERP_NEAREST
} PixopsInterpType;

typedef struct {
    int n;
    double *weights;
} PixopsFilterDim;

typedef struct {
    PixopsFilterDim x;
    PixopsFilterDim y;
    double overall_alpha;
} PixopsFilter;

typedef void (*PixopsLineFunc)();
typedef void (*PixopsPixelFunc)();

void g_return_if_fail(int condition);
void pixops_composite_nearest_noscale(guchar *dest_buf, int render_x0, int render_y0, int render_x1, int render_y1, int dest_rowstride, int dest_channels, gboolean dest_has_alpha, const guchar *src_buf, int src_width, int src_height, int src_rowstride, int src_channels, gboolean src_has_alpha, int overall_alpha);
void pixops_composite_nearest(guchar *dest_buf, int render_x0, int render_y0, int render_x1, int render_y1, int dest_rowstride, int dest_channels, gboolean dest_has_alpha, const guchar *src_buf, int src_width, int src_height, int src_rowstride, int src_channels, gboolean src_has_alpha, double scale_x, double scale_y, int overall_alpha);
gboolean make_weights(PixopsFilter *filter, PixopsInterpType interp_type, double scale_x, double scale_y);
void pixops_process(guchar *dest_buf, int render_x0, int render_y0, int render_x1, int render_y1, int dest_rowstride, int dest_channels, gboolean dest_has_alpha, const guchar *src_buf, int src_width, int src_height, int src_rowstride, int src_channels, gboolean src_has_alpha, double scale_x, double scale_y, int check_x, int check_y, int check_size, int check_threshold, int check_color, PixopsFilter *filter, PixopsLineFunc line_func, PixopsPixelFunc pixel_func);
void composite_line_22_4a4();
void composite_line_22_4a4_mmx_stub();
void composite_line();
void composite_pixel();
void g_free(void *ptr);
gboolean _pixops_have_mmx(void);