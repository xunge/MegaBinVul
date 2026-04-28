#include <stdint.h>

typedef uint8_t guint8;
typedef int gboolean;

#define ERROR_INSUFFICIENT_DATA -1
#define ERROR_INVALID -2

#define TYPE_WMVd 0
#define TYPE_WMVe 1
#define TYPE_WMVf 2
#define TYPE_WMVg 3
#define TYPE_WMVh 4
#define TYPE_WMVi 5
#define TYPE_WMVj 6
#define TYPE_RAW 7
#define TYPE_COPY 8
#define TYPE_HEXTILE 9

struct RfbRectangle {
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    uint32_t type;
};

struct GstVMncDec {
    gboolean have_format;
    struct {
        uint16_t width;
        uint16_t height;
    } format;
};

typedef struct GstVMncDec GstVMncDec;
typedef int (*rectangle_handler)(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);

#define RFB_GET_UINT16(p) ((p)[0] << 8 | (p)[1])
#define RFB_GET_UINT32(p) ((p)[0] << 24 | (p)[1] << 16 | (p)[2] << 8 | (p)[3])

#define GST_LOG_OBJECT(dec, ...)
#define GST_WARNING_OBJECT(dec, ...)
#define GST_DEBUG_OBJECT(dec, ...)

int vmnc_handle_wmvd_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_wmve_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_wmvf_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_wmvg_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_wmvh_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_wmvi_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_wmvj_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_raw_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_copy_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);
int vmnc_handle_hextile_rectangle(GstVMncDec *, struct RfbRectangle *, const guint8 *, int, gboolean);