#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    OMX_ErrorNone = 0,
    OMX_ErrorBadParameter
} OMX_ERRORTYPE;

typedef struct OMX_BUFFERHEADERTYPE {
    void* pInputPortPrivate;
} OMX_BUFFERHEADERTYPE;

enum {
    VDEC_BUFFER_TYPE_INPUT
};

struct vdec_bufferpayload {
    int pmem_fd;
    void* bufferaddr;
    unsigned int mmaped_size;
};

struct vdec_setbuffer_cmd {
    int buffer_type;
    struct vdec_bufferpayload buffer;
};

struct ip_buf {
    unsigned int actualcount;
};

struct drv_ctx_ {
    struct ip_buf ip_buf;
    struct vdec_bufferpayload* ptr_inputbuffer;
#ifdef USE_ION
    void* ip_buf_ion_info;
#endif
};

struct desc_buffer {
    void* buf_addr;
    unsigned int desc_data_size;
};

class auto_lock {
public:
    auto_lock(void* lock) {}
};

class omx_vdec {
public:
    OMX_ERRORTYPE free_input_buffer(OMX_BUFFERHEADERTYPE *bufferHdr);
};

static int secure_mode = 0;
static OMX_BUFFERHEADERTYPE* m_inp_mem_ptr = NULL;
static struct drv_ctx_ drv_ctx;
static struct desc_buffer* m_desc_buffer_ptr = NULL;
static void* buf_lock = NULL;

#define DEBUG_PRINT_LOW(fmt, ...)