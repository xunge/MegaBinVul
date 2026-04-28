#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

typedef struct _PSDimage PSDimage;
typedef struct _PSDlayer PSDlayer;
typedef struct _GError GError;

typedef int gint;
typedef unsigned int guint32;
typedef int gint32;
typedef short gint16;
typedef unsigned short guint16;
typedef unsigned char guchar;
typedef gint gboolean;

#define TRUE 1
#define FALSE 0

#define MAX_CHANNELS 56
#define GIMP_MAX_IMAGE_SIZE 300000
#define G_MAXINT32 INT_MAX

#define GUINT32_FROM_BE(val) (val)
#define GINT32_FROM_BE(val) (val)
#define GUINT16_FROM_BE(val) (val)
#define GINT16_FROM_BE(val) (val)

#define IFDBG(level) if(0)
#define g_debug printf
#define _(x) x
#define MAX(a, b) ((a) > (b) ? (a) : (b))

enum {
    G_FILE_ERROR,
    G_FILE_ERROR_FAILED
};

typedef struct {
    gint16 channel_id;
    guint32 data_len;
} ChannelLengthInfo;

typedef struct {
    char signature[4];
    char key[4];
    guint32 data_len;
} PSDlayerres;

struct _PSDimage {
    gint32 num_layers;
    guint32 mask_layer_len;
    guint32 mask_layer_start;
    gboolean transparency;
    guint32 layer_data_len;
    guint32 layer_data_start;
};

struct _PSDlayer {
    gint32 top;
    gint32 left;
    gint32 bottom;
    gint32 right;
    guint16 num_channels;
    ChannelLengthInfo *chn_info;
    gboolean drop;
    guint32 id;
    char mode_key[5];
    char blend_mode[5];
    guchar opacity;
    guchar clipping;
    guchar flags;
    guchar filler;
    guint32 extra_len;
    struct {
        gboolean trans_prot;
        gboolean visible;
        gboolean irrelevant;
    } layer_flags;
    struct {
        gint32 top;
        gint32 left;
        gint32 bottom;
        gint32 right;
        guchar def_color;
        guchar flags;
        guchar extra_def_color;
        guchar extra_flags;
        struct {
            gboolean relative_pos;
            gboolean disabled;
            gboolean invert;
        } mask_flags;
    } layer_mask;
    struct {
        gint32 top;
        gint32 left;
        gint32 bottom;
        gint32 right;
    } layer_mask_extra;
    char *name;
};

static void psd_set_error(gboolean eof, int err, GError **error) {}
static char *fread_pascal_string(gint32 *read_len, gint32 *write_len, gint align, FILE *f, GError **error) { return NULL; }
static gint get_layer_resource_header(PSDlayerres *res_a, FILE *f, GError **error) { return 0; }
static gint load_layer_resource(PSDlayerres *res_a, PSDlayer *layer, FILE *f, GError **error) { return 0; }

static void g_set_error(GError **err, int domain, int code, const char *format, ...) {}

#define g_new(type, count) ((type*)malloc(sizeof(type) * (count)))
#define g_malloc(size) malloc(size)