#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define G_MAXSIZE ((size_t)-1)
#define WAVPACK4_HEADER_SIZE 32

typedef enum {
    GST_FLOW_OK,
    GST_FLOW_ERROR
} GstFlowReturn;

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef size_t gsize;
typedef bool gboolean;

typedef struct {
    guint8 ck_id[4];
    guint32 ck_size;
    uint16_t version;
    guint8 track_no;
    guint8 index_no;
    guint32 total_samples;
    guint32 block_index;
} Wavpack4Header;

typedef struct _GstElement GstElement;
typedef struct _GstBuffer GstBuffer;
typedef struct _GstAdapter GstAdapter;
typedef struct _GstMapInfo {
    guint8* data;
    gsize size;
} GstMapInfo;
typedef struct _GstMatroskaTrackContext GstMatroskaTrackContext;
typedef struct _GstMatroskaTrackAudioContext GstMatroskaTrackAudioContext;

struct _GstMatroskaTrackAudioContext {
    guint32 channels;
    guint32 wvpk_block_index;
};

struct _GstMatroskaTrackContext {
    guint8* codec_priv;
};

enum {
    GST_MAP_READ,
    GST_MAP_WRITE
};

enum {
    GST_BUFFER_COPY_TIMESTAMPS = 1,
    GST_BUFFER_COPY_FLAGS = 2,
    GST_BUFFER_COPY_MEMORY = 4
};

#define GST_READ_UINT16_LE(ptr) (*(uint16_t*)(ptr))
#define GST_READ_UINT32_LE(ptr) (*(uint32_t*)(ptr))
#define GUINT32_FROM_LE(val) (val)
#define GST_WRITE_UINT8(ptr, val) (*(ptr) = (val))
#define GST_WRITE_UINT16_LE(ptr, val) (*(uint16_t*)(ptr) = (val))
#define GST_WRITE_UINT32_LE(ptr, val) (*(uint32_t*)(ptr) = (val))
#define GST_ERROR_OBJECT(obj, msg)
#define g_assert(expr) assert(expr)

static inline gsize gst_buffer_get_size(GstBuffer* buf) { return 0; }
static inline void gst_buffer_unmap(GstBuffer* buf, GstMapInfo* info) {}
static inline void gst_buffer_extract(GstBuffer* buf, gsize offset, void* dest, gsize size) {}
static inline GstBuffer* gst_buffer_new_allocate(void* allocator, gsize size, void* params) { return NULL; }
static inline gboolean gst_buffer_map(GstBuffer* buf, GstMapInfo* info, int flags) { return false; }
static inline void gst_buffer_copy_into(GstBuffer* dest, GstBuffer* src, int flags, gsize offset, gsize size) {}
static inline void gst_buffer_unref(GstBuffer* buf) {}
static inline GstAdapter* gst_adapter_new(void) { return NULL; }
static inline void g_object_unref(void* obj) {}
static inline void gst_adapter_push(GstAdapter* adapter, GstBuffer* buf) {}
static inline GstBuffer* gst_adapter_take_buffer(GstAdapter* adapter, gsize nbytes) { return NULL; }
static inline gsize gst_adapter_available(GstAdapter* adapter) { return 0; }