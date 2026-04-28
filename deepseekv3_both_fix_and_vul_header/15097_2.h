#include <stdlib.h>
#include <string.h>

typedef struct _GstTagList GstTagList;
typedef struct _GstBuffer GstBuffer;

typedef char gchar;
typedef unsigned char guchar;
typedef int gint;
typedef unsigned int guint;
typedef size_t gsize;

#define GST_TAG_MERGE_APPEND 0
#define GST_TAG_PREVIEW_IMAGE "preview-image"
#define GST_TAG_IMAGE_TYPE_NONE 0
#define GST_WARNING(...)

static void* g_try_malloc0(size_t size) { return calloc(1, size); }
static void g_free(void* ptr) { free(ptr); }
static size_t g_base64_decode_step(const char* in, size_t len, void* out, int* state, unsigned int* save) { return 0; }
static GstBuffer* gst_tag_image_data_to_image_buffer(void* data, size_t len, int type) { return NULL; }
static void gst_tag_list_add(GstTagList* tags, int mode, const char* tag, GstBuffer* img, void* null) {}
static void gst_buffer_unref(GstBuffer* buf) {}