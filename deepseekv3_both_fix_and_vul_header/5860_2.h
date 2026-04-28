#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SCALE_SHIFT 16
#define SUBSAMPLE_BITS 4
#define SUBSAMPLE_MASK 0xf
#define SUBSAMPLE 16

#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef int gboolean;
typedef unsigned char guchar;
typedef unsigned int guint32;

typedef struct {
    int n;
    double offset;
} PixopsFilterDim;

typedef struct {
    PixopsFilterDim x;
    PixopsFilterDim y;
} PixopsFilter;

typedef guchar* (*PixopsLineFunc)(int*, int, int, guchar*, int, guchar*, int, gboolean, guchar**, int, gboolean, int, int, int, int, guint32, guint32);
typedef void (*PixopsPixelFunc)(int*, int, int, guchar*, int, int, gboolean, guchar**, int, gboolean, int, int, int, guint32, guint32);

static void process_pixel(int*, int, int, guchar*, int, int, gboolean, guchar**, int, gboolean, int, int, int, guint32, guint32, PixopsPixelFunc);
static int* make_filter_table(PixopsFilter*);
static int get_check_shift(int);

#define g_new(type, count) ((type*)malloc(sizeof(type) * (count)))
#define g_free(ptr) free(ptr)