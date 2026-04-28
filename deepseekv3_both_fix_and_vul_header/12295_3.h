#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef uint16_t guint16;
typedef uint64_t guint64;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef int gboolean;
#define FALSE 0
#define TRUE 1
typedef char gchar;
typedef void* GType;
typedef size_t gsize;

typedef enum {
  GST_ASF_3D_NONE,
  GST_ASF_3D_SIDE_BY_SIDE_HALF_RL,
  GST_ASF_3D_SIDE_BY_SIDE_HALF_LR,
  GST_ASF_3D_TOP_AND_BOTTOM_HALF_RL,
  GST_ASF_3D_TOP_AND_BOTTOM_HALF_LR,
  GST_ASF_3D_DUAL_STREAM
} GstASF3DMode;

typedef enum {
  ASF_DEMUX_DATA_TYPE_UTF16LE_STRING,
  ASF_DEMUX_DATA_TYPE_BYTE_ARRAY,
  ASF_DEMUX_DATA_TYPE_DWORD,
  ASF_DEMUX_DATA_TYPE_BOOL
} ASFDemuxDataType;

typedef struct _GstASFDemux GstASFDemux;
struct _GstASFDemux {
  GstASF3DMode asf_3D_mode;
  void *global_metadata;
};

typedef void GstTagList;
typedef struct {
  int dummy;
} GValue;
typedef int GstFlowReturn;
typedef int GstTagMergeMode;

#define GST_INFO_OBJECT(obj, ...)
#define GST_DEBUG(...)
#define GST_WARNING(...)
#define GST_FIXME(...)
#define GST_INFO(...)
#define GST_WARNING_OBJECT(obj, ...)
#define GST_STR_NULL(str) (str)
#define GST_TAG_DATE_TIME "datetime"
#define GST_TAG_GENRE "genre"
#define GST_TAG_IMAGE "image"
#define GST_READ_UINT32_LE(ptr) (*(uint32_t*)(ptr))
#define G_N_ELEMENTS(arr) (sizeof(arr)/sizeof(arr[0]))
#define G_IS_VALUE(val) (1)
#define G_TYPE_STRING (0)
#define G_TYPE_UINT (0)
#define GST_TYPE_DATE_TIME (0)
#define GST_TAG_MERGE_APPEND (0)
#define GST_TAG_MERGE_REPLACE (1)
#define GST_FLOW_OK (0)

static const char* g_type_name(GType type) { return ""; }

static GstTagList* gst_tag_list_new_empty() { return NULL; }
static void gst_tag_list_unref(GstTagList* taglist) {}
static void gst_tag_list_add_values(GstTagList* taglist, int mode, const char* tag, GValue* value, void* null) {}
static const char* gst_asf_demux_get_gst_tag_from_tag_name(const char* name) { return NULL; }
static GType gst_tag_get_type(const char* name) { return 0; }
static void g_value_init(GValue* value, GType type) {}
static void g_value_set_string(GValue* value, const char* str) {}
static void g_value_set_uint(GValue* value, unsigned int val) {}
static void g_value_take_boxed(GValue* value, void* boxed) {}
static void g_value_unset(GValue* value) {}
static int g_value_transform(GValue* src, GValue* dest) { return 0; }
static int gst_value_deserialize(GValue* value, const char* str) { return 0; }
static void* gst_date_time_new_y(int year) { return NULL; }
static const char* gst_tag_id3_genre_get(unsigned int id) { return NULL; }
static char* g_convert(const char* str, int len, const char* to, const char* from, size_t* in, size_t* out, void* null) { return NULL; }
static void g_free(void* ptr) {}
static char* g_strdup(const char* str) { return NULL; }
static int g_str_equal(const char* a, const char* b) { return 0; }
static void gst_structure_set_value(void* structure, const char* name, GValue* value) {}
static GstFlowReturn gst_asf_demux_add_global_tags(GstASFDemux* demux, GstTagList* taglist) { return 0; }
static guint16 gst_asf_demux_get_uint16(guint8** data, guint64* size) { return 0; }
static gboolean gst_asf_demux_get_string(gchar** str, guint16* len, guint8** data, guint64* size) { return 0; }
static void asf_demux_parse_picture_tag(GstTagList* taglist, guint8* data, guint size) {}