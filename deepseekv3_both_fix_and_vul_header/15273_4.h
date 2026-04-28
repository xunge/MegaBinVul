#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_CHANNELS 16
#define COMP_MODE_SIZE 2
#define PSD_COMP_RAW 0
#define PSD_COMP_RLE 1
#define PSD_COMP_ZIP 2
#define PSD_COMP_ZIP_PRED 3
#define PSD_CHANNEL_MASK -1
#define PSD_CHANNEL_ALPHA -2
#define CONVERSION_WARNINGS 1
#define IFDBG(level) if(0)
#define TRUE 1
#define FALSE 0
#define GUINT16_FROM_BE(x) (x)
#define G_FILE_ERROR 0
#define G_FILE_ERROR_FAILED 1
#define GIMP_NORMAL_MODE 0
#define GIMP_TRANSPARENT_FILL 0
#define GIMP_ADD_WHITE_MASK 0
#define GIMP_ADD_BLACK_MASK 1

typedef int gint;
typedef unsigned char guchar;
typedef unsigned short guint16;
typedef int gint32;
typedef int gboolean;
typedef void GError;
typedef struct {
    gint32 drawable_id;
    gint32 width;
    gint32 height;
} GimpDrawable;
typedef struct {
    int dummy;
} GimpPixelRgn;
typedef int GimpImageType;
typedef int GimpLayerModeEffects;

typedef struct _PSDchannel PSDchannel;
typedef struct _PSDlayer PSDlayer;
typedef struct _PSDimage PSDimage;

struct _PSDchannel {
    gint id;
    guint16 rows;
    guint16 columns;
    guchar *data;
};

struct _PSDlayer {
    gboolean drop;
    gint32 top;
    gint32 bottom;
    gint32 left;
    gint32 right;
    gint32 id;
    char *name;
    gint32 opacity;
    gint32 blend_mode;
    struct {
        gint32 top;
        gint32 bottom;
        gint32 left;
        gint32 right;
        guchar def_color;
        struct {
            gboolean disabled;
            gboolean relative_pos;
        } mask_flags;
    } layer_mask;
    struct {
        gboolean visible;
        gboolean trans_prot;
        gboolean irrelevant;
    } layer_flags;
    gint num_channels;
    struct {
        gint channel_id;
        gint32 data_len;
    } *chn_info;
};

struct _PSDimage {
    gint num_layers;
    gint32 layer_data_start;
    gint columns;
    gint rows;
    gint bps;
    gint base_type;
};

static void *g_malloc(size_t size) { return malloc(size); }
static void g_free(void *ptr) { free(ptr); }
static void *g_new0(size_t n, size_t size) { return calloc(n, size); }
static void g_set_error(GError **err, int domain, int code, const char *format, ...) {}
static void g_message(const char *format, ...) {}
static void g_debug(const char *format, ...) {}
static const char *_(const char *str) { return str; }

static void psd_set_error(gboolean eof, int err, GError **error) {}
static gint read_channel_data(PSDchannel *channel, gint bps, gint comp_mode, guint16 *rle_pack_len, FILE *f, GError **error) { return 0; }
static GimpImageType get_gimp_image_type(gint base_type, gboolean alpha) { return 0; }
static GimpLayerModeEffects psd_to_gimp_blend_mode(gint blend_mode) { return 0; }

static gint32 gimp_layer_new(gint32 image_id, const char *name, gint32 width, gint32 height, GimpImageType type, gint32 opacity, GimpLayerModeEffects mode) { return 0; }
static void gimp_image_add_layer(gint32 image_id, gint32 layer_id, gint32 position) {}
static GimpDrawable *gimp_drawable_get(gint32 drawable_id) { static GimpDrawable d; return &d; }
static void gimp_drawable_fill(gint32 drawable_id, gint32 fill_type) {}
static void gimp_drawable_set_visible(gint32 drawable_id, gboolean visible) {}
static void gimp_drawable_set_tattoo(gint32 drawable_id, gint32 tattoo) {}
static void gimp_drawable_flush(GimpDrawable *drawable) {}
static void gimp_drawable_detach(GimpDrawable *drawable) {}
static void gimp_layer_set_offsets(gint32 layer_id, gint32 x, gint32 y) {}
static void gimp_layer_set_lock_alpha(gint32 layer_id, gboolean lock_alpha) {}
static void gimp_pixel_rgn_init(GimpPixelRgn *rgn, GimpDrawable *drawable, gint32 x, gint32 y, gint32 width, gint32 height, gboolean dirty, gboolean shadow) {}
static void gimp_pixel_rgn_set_rect(GimpPixelRgn *rgn, guchar *pixels, gint32 x, gint32 y, gint32 width, gint32 height) {}
static gint32 gimp_layer_create_mask(gint32 layer_id, gint32 mask_type) { return 0; }
static void gimp_layer_add_mask(gint32 layer_id, gint32 mask_id) {}
static void gimp_layer_set_apply_mask(gint32 layer_id, gboolean apply) {}

#define g_new(type, n) ((type *)g_new0(n, sizeof(type)))