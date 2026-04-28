#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdint.h>
#include <string.h>

typedef int gint;
typedef unsigned char* png_bytep;
typedef uint32_t png_uint_32;

typedef struct _GstPad GstPad;
typedef struct _GstBuffer GstBuffer;
typedef struct _GstPngDec {
    jmp_buf* png;
    void* info;
    unsigned int height;
    GstPad* srcpad;
    GstPad* sinkpad;
} GstPngDec;

typedef enum {
    GST_FLOW_OK,
    GST_FLOW_ERROR,
    GST_FLOW_NOT_LINKED
} GstFlowReturn;

#define GST_PNGDEC(obj) ((GstPngDec*)obj)
#define GST_OBJECT_PARENT(obj) ((void*)obj)
#define GST_LOG_OBJECT(obj, ...)
#define GST_INFO_OBJECT(obj, ...)
#define GST_ELEMENT_ERROR(obj, ...)
#define GST_BUFFER_DATA(buf) ((png_bytep)buf)
#define G_MAXUINT32 UINT32_MAX
#define GST_ROUND_UP_4(n) (((n) + 3) & ~3)
#define GST_PAD_CAPS(pad) NULL
#define GST_BUFFER_OFFSET_NONE 0
#define GST_FLOW_IS_FATAL(flow) (0)

typedef void (*user_read_data_fn)(void*, void*, size_t);
static void user_read_data(void* png_ptr, void* data, size_t length) {}

static jmp_buf* png_jmpbuf(void* png_ptr) { return (jmp_buf*)png_ptr; }
static void png_set_read_fn(void* png_ptr, void* io_ptr, user_read_data_fn read_data_fn) {}
static void png_read_info(void* png_ptr, void* info_ptr) {}
static void png_read_image(void* png_ptr, png_bytep* rows) {}
static png_uint_32 png_get_rowbytes(void* png_ptr, void* info_ptr) { return 0; }

static GstFlowReturn gst_pngdec_caps_create_and_set(GstPngDec* pngdec) { return GST_FLOW_OK; }
static GstFlowReturn gst_pad_alloc_buffer_and_set_caps(GstPad* pad, size_t offset, size_t size, void* caps, GstBuffer** buf) { return GST_FLOW_OK; }
static GstFlowReturn gst_pad_push(GstPad* pad, GstBuffer* buf) { return GST_FLOW_OK; }
static void gst_pad_pause_task(GstPad* pad) {}
static void gst_pad_push_event(GstPad* pad, void* event) {}
static void* gst_event_new_eos() { return NULL; }
static const char* gst_flow_get_name(GstFlowReturn ret) { return ""; }

static void* g_malloc(size_t size) { return malloc(size); }
static void g_free(void* ptr) { free(ptr); }