#include <stdint.h>

typedef unsigned char guchar;
typedef int gboolean;
typedef unsigned int guint32;

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

void g_return_if_fail(int condition);
void g_free(void *ptr);
void pixops_composite_color_nearest(guchar *dest_buf, int render_x0, int render_y0, int render_x1, int render_y1, int dest_rowstride, int dest_channels, gboolean dest_has_alpha, const guchar *src_buf, int src_width, int src_height, int src_rowstride, int src_channels, gboolean src_has_alpha, double scale_x, double scale_y, int overall_alpha, int check_x, int check_y, int check_size, guint32 color1, guint32 color2);
gboolean make_weights(PixopsFilter *filter, PixopsInterpType interp_type, double scale_x, double scale_y);
void pixops_process(guchar *dest_buf, int render_x0, int render_y0, int render_x1, int render_y1, int dest_rowstride, int dest_channels, gboolean dest_has_alpha, const guchar *src_buf, int src_width, int src_height, int src_rowstride, int src_channels, gboolean src_has_alpha, double scale_x, double scale_y, int check_x, int check_y, int check_size, guint32 color1, guint32 color2, PixopsFilter *filter, PixopsLineFunc line_func, void (*composite_pixel_color)());
void composite_line_color();
void composite_pixel_color();