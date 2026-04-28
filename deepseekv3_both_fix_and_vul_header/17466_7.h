#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int32_t gint32;
typedef unsigned int guint;
typedef int gint;
typedef uint64_t guint64;

typedef struct _GstBuffer {
    int dummy;
} GstBuffer;

typedef struct {
    guint8 *data;
    size_t size;
} GstMapInfo;

typedef struct {
    struct {
        guint32 type;
        guint32 fcc_handler;
    } *strh;
    struct {
        struct {
            guint32 compression;
            gint32 height;
            guint32 width;
            guint32 bit_cnt;
        } *vids;
    } strf;
    GstBuffer *rgb8_palette;
} GstAviStream;

#define GST_RIFF_FCC_vids 0x73646976
#define GST_WARNING(...)
#define GST_ROUND_UP_4(n) (((n) + 3) & ~3)
#define G_MAXUINT UINT32_MAX
#define GST_MAP_READWRITE 0

static GstBuffer* gst_buffer_make_writable(GstBuffer* buf) { return buf; }
static void gst_buffer_map(GstBuffer* buf, GstMapInfo* map, int flags) {}
static void gst_buffer_unmap(GstBuffer* buf, GstMapInfo* map) {}
static GstBuffer* gst_buffer_ref(GstBuffer* buf) { return buf; }
static GstBuffer* gst_buffer_append(GstBuffer* buf1, GstBuffer* buf2) { return buf1; }
static void* g_malloc(size_t size) { return malloc(size); }
static void g_free(void* ptr) { free(ptr); }
static void swap_line(guint8 *line1, guint8 *line2, guint8 *tmp, guint stride) {
    memcpy(tmp, line1, stride);
    memcpy(line1, line2, stride);
    memcpy(line2, tmp, stride);
}
static int gst_avi_demux_is_uncompressed(guint32 fourcc) { return 1; }