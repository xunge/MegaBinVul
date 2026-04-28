#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef unsigned char guchar;
typedef int gboolean;
typedef uint32_t guint32;
typedef int64_t gint64;
typedef size_t gsize;

#define SCALE_SHIFT 16
#define SUBSAMPLE_BITS 4
#define SUBSAMPLE 16
#define SUBSAMPLE_MASK 0xf
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef struct {
    int n;
    double offset;
} PixopsFilterDim;

typedef struct {
    PixopsFilterDim x;
    PixopsFilterDim y;
} PixopsFilter;

typedef guchar* (*PixopsLineFunc)(int *weights, int x_n, int y_n,
                                guchar *dest, int dest_x, guchar *dest_end,
                                int dest_channels, gboolean dest_has_alpha,
                                guchar **line_bufs, int src_channels, gboolean src_has_alpha,
                                gint64 x, gint64 x_step, int src_width,
                                int check_size, guint32 color1, guint32 color2);

typedef void (*PixopsPixelFunc)(int *weights, int x_n, int y_n,
                               guchar *dest, int dest_x, int dest_channels, gboolean dest_has_alpha,
                               guchar **line_bufs, int src_channels, gboolean src_has_alpha,
                               int x, int src_width,
                               int check_size, guint32 color1, guint32 color2);

static void process_pixel(int *weights, int x_n, int y_n,
                        guchar *dest, int dest_x, int dest_channels, gboolean dest_has_alpha,
                        guchar **line_bufs, int src_channels, gboolean src_has_alpha,
                        int x, int src_width,
                        int check_size, guint32 color1, guint32 color2,
                        PixopsPixelFunc pixel_func);

static int* make_filter_table(PixopsFilter *filter);
static int get_check_shift(int check_size);

#define g_new(type, n) ((type*)malloc(sizeof(type) * (n)))
#define g_free free