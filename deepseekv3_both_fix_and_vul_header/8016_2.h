#include <stdint.h>
#include <cstddef>

#define OMX_SPEC_VERSION 0x00000101
#define PORT_INDEX_IN 0
#define OMX_IN
#define OMX_HANDLETYPE void*
#define OMX_U32 uint32_t
#define OMX_ERRORTYPE int
#define OMX_ErrorNone 0
#define OMX_ErrorInvalidState 1
#define OMX_ErrorBadParameter 2
#define OMX_ErrorVersionMismatch 3
#define OMX_ErrorBadPortIndex 4
#define OMX_ErrorIncorrectStateOperation 5

typedef enum {
    OMX_StateInvalid,
    OMX_StateLoaded,
    OMX_StateIdle,
    OMX_StateExecuting,
    OMX_StatePause,
    OMX_StateWaitForResources,
    OMX_StateKhronosExtensions = 0x6F000000,
    OMX_StateVendorStartUnused = 0x7F000000,
    OMX_StateMax = 0x7FFFFFFF
} OMX_STATETYPE;

typedef struct OMX_BUFFERHEADERTYPE {
    uint32_t nSize;
    struct {
        uint32_t nVersion;
    } nVersion;
    uint8_t* pBuffer;
    uint32_t nInputPortIndex;
    uint32_t nTimeStamp;
} OMX_BUFFERHEADERTYPE;

struct omx_video {
    OMX_ERRORTYPE empty_this_buffer(OMX_IN OMX_HANDLETYPE hComp,
                                   OMX_IN OMX_BUFFERHEADERTYPE* buffer);
    
    OMX_STATETYPE m_state;
    struct {
        int bEnabled;
        uint32_t nBufferCountActual;
    } m_sInPortDef;
    OMX_BUFFERHEADERTYPE* m_inp_mem_ptr;
    OMX_BUFFERHEADERTYPE* meta_buffer_hdr;
    int meta_mode_enable;
    unsigned int m_etb_count;
    unsigned int m_input_msg_id;
};

#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_ERROR(...)

void post_event(unsigned long hComp, unsigned long buffer, unsigned int msg_id);