#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <endian.h>

typedef struct _GNode {
    void *data;
    struct _GNode *next;
    struct _GNode *prev;
    struct _GNode *parent;
    struct _GNode *children;
} GNode;

typedef struct _QtDemuxSample {
    uint32_t size;
    bool keyframe;
    uint32_t chunk;
    uint64_t offset;
    uint64_t timestamp;
    uint64_t duration;
    int64_t pts_offset;
} QtDemuxSample;

typedef struct _QtDemuxStream {
    bool sampled;
    uint32_t n_samples;
    QtDemuxSample *samples;
    uint32_t min_duration;
    uint32_t timescale;
    bool all_keyframe;
    uint32_t samples_per_frame;
    uint32_t bytes_per_frame;
    uint32_t n_channels;
} QtDemuxStream;

typedef struct _GstQTDemux {
    // Placeholder structure
} GstQTDemux;

#define FOURCC_stsc 0x73747363
#define FOURCC_stsz 0x7374737a
#define FOURCC_stco 0x7374636f
#define FOURCC_co64 0x636f3634
#define FOURCC_stts 0x73747473
#define FOURCC_stss 0x73747373
#define FOURCC_ctts 0x63747473

#define QT_UINT32(data) (be32toh(*(uint32_t *)(data)))
#define QT_UINT64(data) (be64toh(*(uint64_t *)(data)))

#define GST_SECOND 1000000000
#define GST_TIME_FORMAT "u:%02u:%02u.%09u"
#define GST_TIME_ARGS(time) \
    (unsigned)((time) / (GST_SECOND * 60 * 60)), \
    (unsigned)(((time) / (GST_SECOND * 60)) % 60), \
    (unsigned)(((time) / GST_SECOND) % 60), \
    (unsigned)((time) % GST_SECOND)

#define GST_DEBUG_OBJECT(obj, ...) 
#define GST_LOG_OBJECT(obj, ...) 
#define GST_ELEMENT_ERROR(obj, domain, code, msg, debug) 

#define G_MAXUINT32 UINT32_MAX
#define G_GUINT64_FORMAT "lu"

#define TRUE true
#define FALSE false

typedef bool gboolean;
typedef int32_t gint32;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef int64_t gint64;
typedef int gint;
typedef unsigned char guint8;

static inline uint64_t gst_util_uint64_scale(uint64_t val, uint64_t num, uint64_t denom) {
    return (val * num) / denom;
}

#define g_new0(type, count) ((type *)calloc((count), sizeof(type)))

static GNode* qtdemux_tree_get_child_by_type(GNode *node, uint32_t type) {
    return NULL;
}