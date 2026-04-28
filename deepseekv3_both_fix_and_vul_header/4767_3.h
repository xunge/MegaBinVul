#include <stdint.h>
#include <string.h>

#define OMX_IN
#define OMX_COMPONENT_GENERATE_EVENT 0
#define OMX_CORE_INPUT_PORT_INDEX 0
#define OMX_CORE_OUTPUT_PORT_INDEX 1
#define VDEC_BUFFER_TYPE_INPUT 0
#define VDEC_BUFFER_TYPE_OUTPUT 1
#define MAX_NUM_INPUT_OUTPUT_BUFFERS 32

#define BITMASK_PRESENT(flags, bit) ((*(flags)) & (bit))
#define BITMASK_CLEAR(flags, bit) (*(flags) &= ~(bit))
#define BITMASK_SET(flags, bit) (*(flags) |= (bit))

#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_HIGH(...)

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
typedef uint32_t OMX_U32;
typedef int32_t OMX_BOOL;
typedef uint32_t OMX_STATETYPE;

struct OMX_BUFFERHEADERTYPE {
    // buffer header structure
};

#define OMX_ErrorNone 0
#define OMX_ErrorBadPortIndex 1
#define OMX_ErrorIncorrectStateOperation 2
#define OMX_ErrorPortUnpopulated 3

#define OMX_FALSE 0
#define OMX_TRUE 1

#define OMX_StateInvalid 0
#define OMX_StateIdle 1
#define OMX_StateExecuting 2
#define OMX_StatePause 3
#define OMX_StateLoaded 4

#define OMX_EventError 0
#define OMX_CommandPortDisable 1
#define OMX_CommandStateSet 2

#define OMX_COMPONENT_LOADING_PENDING 0x1
#define OMX_COMPONENT_INPUT_ENABLE_PENDING 0x2
#define OMX_COMPONENT_OUTPUT_ENABLE_PENDING 0x4
#define OMX_COMPONENT_INPUT_DISABLE_PENDING 0x8
#define OMX_COMPONENT_OUTPUT_DISABLE_PENDING 0x10

struct nativebuffer {
    // placeholder for native buffer structure
};

struct vdec_bufferpayload {
    uint32_t actualcount;
};

class omx_vdec {
public:
    OMX_ERRORTYPE free_buffer(OMX_IN OMX_HANDLETYPE hComp,
                             OMX_IN OMX_U32 port,
                             OMX_IN OMX_BUFFERHEADERTYPE* buffer);
private:
    OMX_STATETYPE m_state;
    uint32_t m_flags;
    OMX_BOOL m_inp_bEnabled;
    OMX_BOOL m_out_bEnabled;
    OMX_BOOL m_inp_bPopulated;
    OMX_BOOL m_out_bPopulated;
    OMX_BOOL arbitrary_bytes;
    OMX_BOOL input_use_buffer;
    uint32_t m_inp_bm_count;
    uint32_t m_heap_inp_bm_count;
    uint32_t m_out_bm_count;
    OMX_BUFFERHEADERTYPE* m_inp_mem_ptr;
    OMX_BUFFERHEADERTYPE* m_inp_heap_ptr;
    OMX_BUFFERHEADERTYPE** m_phdr_pmem_ptr;
    struct {
        struct vdec_bufferpayload ip_buf;
        struct vdec_bufferpayload op_buf;
    } drv_ctx;
    bool m_enable_android_native_buffers;
    struct nativebuffer native_buffer[MAX_NUM_INPUT_OUTPUT_BUFFERS];

    class ClientBuffers {
    public:
        OMX_BUFFERHEADERTYPE* get_il_buf_hdr();
        void free_output_buffer(OMX_BUFFERHEADERTYPE* buffer);
    } client_buffers;

    void free_input_buffer(OMX_BUFFERHEADERTYPE* buffer);
    void free_input_buffer(uint32_t index, OMX_BUFFERHEADERTYPE* buffer);
    void free_input_buffer_header();
    void free_output_buffer_header();
    bool release_input_done();
    bool release_output_done();
    bool release_done();
    void release_buffers(omx_vdec* obj, uint32_t type);
    void post_event(uint32_t event, uint32_t data1, uint32_t data2);
};