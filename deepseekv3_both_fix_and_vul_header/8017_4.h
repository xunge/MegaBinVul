#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t OMX_ERRORTYPE;
typedef uint8_t OMX_U8;

#define OMX_ErrorNone 0
#define OMX_ErrorBadParameter 1
#define OMX_FALSE 0

#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_LOW(...)

#define PORT_INDEX_IN 0
#define _ANDROID_ICS_
#define USE_ION

struct OMX_BUFFERHEADERTYPE {
    // 添加必要的成员
};

struct pmem {
    void *buffer;
    size_t size;
    int fd;
};

struct ion {
    // 添加必要的成员
};

struct auto_lock {
    auto_lock(struct lock&) {}
};

struct lock {
    // 添加必要的成员
};

struct MetaBuffer {
    // 添加必要的成员
};

struct omx_video {
    OMX_ERRORTYPE free_input_buffer(OMX_BUFFERHEADERTYPE *bufferHdr);
    
    OMX_BUFFERHEADERTYPE *m_inp_mem_ptr;
    OMX_BUFFERHEADERTYPE *meta_buffer_hdr;
    MetaBuffer *meta_buffers;
    OMX_BUFFERHEADERTYPE **opaque_buffer_hdr;
    struct pmem *m_pInput_pmem;
    struct ion **m_pInput_ion;
    int m_sInPortDef_nBufferCountActual;
    bool meta_mode_enable;
    bool mUseProxyColorFormat;
    bool input_use_buffer;
    bool m_use_input_pmem;
    bool secure_session;
    struct {
        int nBufferCountActual;
    } m_sInPortDef;
    struct {
        void close();
    } c2d_conv;
    struct lock m_lock;
};

bool dev_free_buf(struct pmem *, int);
void free_ion_memory(struct ion **);