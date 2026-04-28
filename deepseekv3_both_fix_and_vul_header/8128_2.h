#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdint.h>

#define PROPERTY_VALUE_MAX 92
#define COLOR_FMT_NV12 1
#define VENUS_Y_STRIDE(color_fmt, width) (width)
#define VENUS_Y_SCANLINES(color_fmt, height) (height)
#define VENUS_BUFFER_SIZE(color_fmt, width, height) (width * height * 3 / 2)
#define DEBUG_PRINT_ERROR(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", ##__VA_ARGS__)
#define DEBUG_PRINT_HIGH(fmt, ...) fprintf(stderr, "HIGH: " fmt "\n", ##__VA_ARGS__)

typedef struct OMX_BUFFERHEADERTYPE {
    char *pBuffer;
    uint32_t nFilledLen;
} OMX_BUFFERHEADERTYPE;

struct venc_debug {
    FILE *infile;
    char infile_name[PROPERTY_VALUE_MAX];
    char *log_loc;
};

struct venc_cfg {
    unsigned long input_width;
    unsigned long input_height;
};

struct venc_handle_t {
    int is_secure_session();
};

class venc_dev {
public:
    int venc_input_log_buffers(OMX_BUFFERHEADERTYPE *pbuffer, int fd, int plane_offset);
    venc_handle_t *venc_handle;
    venc_debug m_debug;
    venc_cfg m_sVenc_cfg;
    int metadatamode;
};