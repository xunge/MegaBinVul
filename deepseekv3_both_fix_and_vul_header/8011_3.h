#include <stdint.h>
#include <cstddef>

typedef int OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;

#define OMX_IN
#define OMX_CORE_INPUT_PORT_INDEX 0
#define OMX_ErrorNone 0
#define OMX_ErrorInvalidState 1
#define OMX_ErrorBadParameter 2
#define OMX_ErrorIncorrectStateOperation 3
#define OMX_ErrorBadPortIndex 4
#define OMX_BUFFERFLAG_CODECCONFIG (1 << 0)
#define OMX_COMPONENT_GENERATE_ETB 0
#define OMX_COMPONENT_GENERATE_ETB_ARBITRARY 1

#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_LOW(...)

enum OMX_STATETYPE {
    OMX_StateInvalid,
    OMX_StateLoaded,
    OMX_StateIdle,
    OMX_StateExecuting,
    OMX_StatePause,
    OMX_StateWaitForResources
};

struct OMX_BUFFERHEADERTYPE {
    unsigned int nInputPortIndex;
    void* pBuffer;
    long long nTimeStamp;
    unsigned int nFilledLen;
    unsigned int nFlags;
};

struct drv_ctx_ip_buf {
    unsigned int actualcount;
};

struct drv_ctx {
    struct drv_ctx_ip_buf ip_buf;
};

struct omx_vdec {
    OMX_STATETYPE m_state;
    bool m_inp_bEnabled;
    bool arbitrary_bytes;
    bool input_use_buffer;
    bool perf_flag;
    bool codec_config_flag;
    unsigned int latency;
    OMX_BUFFERHEADERTYPE* m_inp_heap_ptr;
    OMX_BUFFERHEADERTYPE* m_inp_mem_ptr;
    struct drv_ctx drv_ctx;
    struct {
        void stop();
        unsigned int processing_time_us();
        void start();
    } dec_time;
    struct {
        void insert_timestamp(OMX_BUFFERHEADERTYPE* buffer);
    } time_stamp_dts;
    void post_event(unsigned long hComp, unsigned long buffer, unsigned long event);
#ifdef _ANDROID_
    struct {
        OMX_ERRORTYPE Decrypt(OMX_BUFFERHEADERTYPE* buffer);
    } *iDivXDrmDecrypt;
#endif
    
    OMX_ERRORTYPE empty_this_buffer(OMX_IN OMX_HANDLETYPE hComp,
                                   OMX_IN OMX_BUFFERHEADERTYPE* buffer);
};