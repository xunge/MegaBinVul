#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define ERROR_INSUFFICIENT_DATA -1
#define ERROR_INVALID -2

#define RFB_GET_UINT16(p) ((p)[0] << 8 | (p)[1])
#define G_BIG_ENDIAN 4321
#define G_LITTLE_ENDIAN 1234
#define G_BYTE_ORDER G_LITTLE_ENDIAN
#define GUINT32_SWAP_LE_BE(val) ((val >> 24) | ((val >> 8) & 0xff00) | ((val << 8) & 0xff0000) | (val << 24))
#define GUINT32_FROM_BE(val) (val)
#define TRUE 1
#define FALSE 0
#define GST_VIDEO_FORMAT_UNKNOWN 0

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int32_t gint;
typedef int gboolean;

#define GST_DEBUG_OBJECT(dec, ...)
#define GST_WARNING_OBJECT(dec, ...) 
#define GST_LOG_OBJECT(dec, ...)
#define gst_video_format_to_string(fmt) ""
#define g_free free
#define g_malloc malloc

struct RfbRectangle {
    gint x;
    gint y;
    gint width;
    gint height;
};

typedef struct {
    guint8 descriptor[16];
    gint depth;
    gboolean big_endian;
    gint bytes_per_pixel;
    gint width;
    gint height;
    gint stride;
} VMncFormat;

typedef struct _GstVMncDec {
    gboolean have_format;
    VMncFormat format;
    guint8 *imagedata;
    void *input_state;
} GstVMncDec;

typedef int GstVideoFormat;
typedef void GstVideoCodecState;

static inline GstVideoFormat gst_video_format_from_masks(gint depth, gint bpp, guint32 endianness,
    guint32 redmask, guint32 greenmask, guint32 bluemask, guint32 alphamask) {
    return 0;
}

static inline void* gst_video_decoder_set_output_state(void* decoder, GstVideoFormat format,
    gint width, gint height, void* input_state) {
    return NULL;
}

static inline void gst_video_codec_state_unref(void* state) {
}

#define GST_VIDEO_DECODER(dec) ((void*)dec)