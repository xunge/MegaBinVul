#include <stdint.h>
#include <string.h>

typedef struct png_struct_def {
    void *io_ptr;
} png_struct;
typedef png_struct *png_structp;
typedef uint8_t *png_bytep;
typedef uint32_t png_uint_32;

typedef struct _GstPngDec GstPngDec;
struct _GstPngDec {
    void *buffer_out;
    size_t rowbytes;
    int ret;
};

#define GST_PNGDEC(obj) ((GstPngDec *)(obj))
#define GST_IS_BUFFER(obj) ((obj) != NULL)
#define GST_BUFFER_DATA(buf) ((uint8_t *)(buf))
#define GST_ROUND_UP_4(num) (((num) + 3) & ~3)
#define GST_LOG(...)
#define GST_FLOW_OK (0)