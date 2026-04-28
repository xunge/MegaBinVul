#include <stdint.h>
#include <string.h>
#include <mutex>

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
typedef uint32_t OMX_U32;
typedef uint8_t OMX_U8;

#define OMX_IN
#define OMX_COMPONENT_GENERATE_EBD 0
#define OMX_ErrorNone 0
#define OMX_ErrorBadParameter 1
#define OMX_ErrorUndefined 2
#define OMX_ErrorInsufficientResources 3
#define OMX_COLOR_FormatYUV420SemiPlanar 0x15
#define PORT_INDEX_IN 0
#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_ERROR(...)

typedef struct OMX_BUFFERHEADERTYPE {
    OMX_U8* pBuffer;
    OMX_U32 nOffset;
    OMX_U32 nFilledLen;
} OMX_BUFFERHEADERTYPE;

struct omx_video {
    OMX_ERRORTYPE empty_this_buffer_proxy(OMX_IN OMX_HANDLETYPE hComp, OMX_IN OMX_BUFFERHEADERTYPE* buffer);
    std::mutex m_lock;
};

typedef struct OMX_PORTDEFINITIONTYPE {
    OMX_U32 nBufferCountActual;
    struct {
        struct {
            OMX_U32 nFrameWidth;
            OMX_U32 nFrameHeight;
            OMX_U32 eColorFormat;
        } video;
    } format;
} OMX_PORTDEFINITIONTYPE;

typedef enum {
    kMetadataBufferTypeCameraSource,
    kMetadataBufferTypeGrallocSource
} MetadataBufferType;

typedef struct encoder_media_buffer_type {
    MetadataBufferType buffer_type;
    struct {
        int numFds;
        int numInts;
        int data[3];
    } *meta_handle;
} encoder_media_buffer_type;

typedef struct private_handle_t {
    int fd;
    int size;
} private_handle_t;

typedef struct pmem {
    void* buffer;
    int fd;
    int offset;
    int size;
} pmem;

#define auto_lock std::lock_guard<std::mutex>

extern OMX_BUFFERHEADERTYPE* meta_buffer_hdr;
extern OMX_BUFFERHEADERTYPE* m_inp_mem_ptr;
extern OMX_PORTDEFINITIONTYPE m_sInPortDef;
extern pmem* m_pInput_pmem;
extern bool meta_mode_enable;
extern bool mUsesColorConversion;
extern bool input_flush_progress;
extern bool input_use_buffer;
extern bool m_use_input_pmem;
extern bool mUseProxyColorFormat;
extern bool hw_overload;
extern int pending_input_buffers;
extern int fd;

bool dev_use_buf(pmem* info, int port_index, int unused);
bool dev_empty_buf(OMX_BUFFERHEADERTYPE* buffer, OMX_U8* pmem_data_buf, int nBufIndex, int fd);
bool dev_color_align(OMX_BUFFERHEADERTYPE* buffer, OMX_U32 width, OMX_U32 height);
void post_event(unsigned long buffer, int unused, int event);
void omx_release_meta_buffer(OMX_BUFFERHEADERTYPE* buffer);