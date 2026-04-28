#include <stdint.h>
#include <stdlib.h>

typedef struct png_struct_def {
    void* io_ptr;
} png_struct;
typedef png_struct* png_structp;

typedef struct png_info_def png_info;
typedef png_info* png_infop;

typedef struct _GstBuffer GstBuffer;
typedef struct _GstPad GstPad;

typedef struct _GstPngDec {
    png_structp png;
    png_infop info;
    uint32_t rowbytes;
    uint32_t height;
    GstPad* srcpad;
    GstBuffer* buffer_out;
    int ret;
} GstPngDec;

#define GST_PNGDEC(obj) ((GstPngDec*)(obj))
#define GST_LOG(...)
#define GST_FLOW_OK 0
#define GST_FLOW_ERROR 1
#define GST_BUFFER_OFFSET_NONE 0
#define GST_PAD_CAPS(pad) NULL
#define GST_ROUND_UP_4(n) (((n) + 3) & ~3)
#define G_MAXUINT32 UINT32_MAX

typedef int GstFlowReturn;

unsigned long png_get_rowbytes(png_structp png_ptr, png_infop info_ptr);
GstFlowReturn gst_pngdec_caps_create_and_set(GstPngDec* pngdec);
GstFlowReturn gst_pad_alloc_buffer_and_set_caps(GstPad* pad, uint64_t offset, size_t size, void* caps, GstBuffer** buf);