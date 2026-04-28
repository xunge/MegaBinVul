#include <stdint.h>
#include <cstddef>

#define OMX_IN
#define OMX_CORE_OUTPUT_PORT_INDEX 1

enum OMX_ErrorType {
    OMX_ErrorNone = 0,
    OMX_ErrorInvalidState,
    OMX_ErrorIncorrectStateOperation,
    OMX_ErrorBadParameter,
    OMX_ErrorBadPortIndex
};

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
typedef uint32_t OMX_U32;
typedef uint8_t OMX_U8;
typedef int32_t OMX_S32;
typedef int32_t OMX_BOOL;

enum OMX_STATETYPE {
    OMX_StateInvalid,
    OMX_StateLoaded,
    OMX_StateIdle,
    OMX_StateExecuting,
    OMX_StatePause,
    OMX_StateWaitForResources,
    OMX_StateKhronosExtensions = 0x6F000000,
    OMX_StateVendorStartUnused = 0x7F000000,
    OMX_StateMax = 0x7FFFFFFF
};

struct OMX_BUFFERHEADERTYPE {
    OMX_U8* pBuffer;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOutputPortIndex;
};

struct private_handle_t {
    int fd;
    int size;
};

struct VideoDecoderOutputMetaData {
    int eType;
    void* pHandle;
};

#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_LOW(...)

class omx_vdec {
public:
    OMX_STATETYPE m_state;
    OMX_BOOL m_out_bEnabled;
    bool dynamic_buf_mode;
    struct {
        unsigned int actualcount;
    } op_buf;
    struct drv_ctx_t {
        struct {
            int pmem_fd;
            OMX_U8* bufferaddr;
        } *ptr_outputbuffer;
        struct {
            unsigned int actualcount;
        } op_buf;
    } drv_ctx;
    struct {
        private_handle_t* privatehandle;
        private_handle_t* nativehandle;
    } *native_buffer;
    class client_buffers {
    public:
        OMX_BUFFERHEADERTYPE* get_il_buf_hdr();
    } client_buffers;
    int m_fill_output_msg;
    void post_event(unsigned long, unsigned long, int);
    
    OMX_ERRORTYPE fill_this_buffer(OMX_IN OMX_HANDLETYPE hComp, OMX_IN OMX_BUFFERHEADERTYPE* buffer);
};