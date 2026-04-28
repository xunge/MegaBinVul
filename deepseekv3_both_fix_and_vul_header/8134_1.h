#include <stdint.h>
#include <string.h>

#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_HIGH(...)

#define VEN_S_SUCCESS 0
#define VEN_S_EFAIL 1

#define VEN_MSG_START 0
#define VEN_MSG_STOP 1
#define VEN_MSG_PAUSE 2
#define VEN_MSG_RESUME 3
#define VEN_MSG_FLUSH_INPUT_DONE 4
#define VEN_MSG_FLUSH_OUPUT_DONE 5
#define VEN_MSG_INPUT_BUFFER_DONE 6
#define VEN_MSG_OUTPUT_BUFFER_DONE 7
#define VEN_MSG_NEED_OUTPUT_BUFFER 8
#define VEN_MSG_HW_OVERLOAD 9
#define VEN_MSG_LTRUSE_FAILED 10

#define OMX_COMPONENT_GENERATE_START_DONE 0
#define OMX_COMPONENT_GENERATE_STOP_DONE 1
#define OMX_COMPONENT_GENERATE_PAUSE_DONE 2
#define OMX_COMPONENT_GENERATE_RESUME_DONE 3
#define OMX_COMPONENT_GENERATE_EVENT_INPUT_FLUSH 4
#define OMX_COMPONENT_GENERATE_EVENT_OUTPUT_FLUSH 5
#define OMX_COMPONENT_GENERATE_EBD 6
#define OMX_COMPONENT_GENERATE_FBD 7
#define OMX_COMPONENT_GENERATE_LTRUSE_FAILED 8

typedef uint32_t OMX_U32;

struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_U32 nFlags;
    OMX_U32 nTimeStamp;
    uint8_t* pBuffer;
};

struct venc_buffer {
    void* ptrbuffer;
    void* clientdata;
    uint32_t len;
    uint32_t offset;
    uint64_t timestamp;
    uint32_t flags;
};

struct venc_msg {
    uint32_t msgcode;
    uint32_t statuscode;
    struct venc_buffer buf;
};

struct OMX_PORTDEF {
    OMX_U32 nBufferCountActual;
};

class omx_video {
public:
    OMX_BUFFERHEADERTYPE* m_inp_mem_ptr;
    OMX_BUFFERHEADERTYPE* m_out_mem_ptr;
    OMX_BUFFERHEADERTYPE* meta_buffer_hdr;
    struct OMX_PORTDEF m_sInPortDef;
    struct OMX_PORTDEF m_sOutPortDef;
    bool output_use_buffer;
    bool m_use_output_pmem;
    
    bool is_secure_session();
    void omx_report_hw_overload();
    void omx_report_error();
    void post_event(unsigned long, uint32_t, uint32_t);
    void omx_release_meta_buffer(OMX_BUFFERHEADERTYPE*);
};

class omx_venc {
public:
    int async_message_process(void* context, void* message);
};