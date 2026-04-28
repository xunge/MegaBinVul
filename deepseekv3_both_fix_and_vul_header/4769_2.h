#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define OMX_IN
#define OMX_COMPONENT_GENERATE_EVENT 0
#define OMX_CommandPortDisable 0
#define OMX_CommandStateSet 0
#define OMX_ErrorNone 0
#define OMX_ErrorBadPortIndex 0
#define OMX_ErrorPortUnpopulated 0
#define OMX_ErrorHardware 0
#define OMX_EventError 0
#define OMX_StateIdle 0
#define OMX_StateExecuting 0
#define OMX_StatePause 0
#define OMX_StateLoaded 0
#define OMX_FALSE 0
#define PORT_INDEX_IN 0
#define PORT_INDEX_OUT 0
#define OMX_COMPONENT_LOADING_PENDING 0
#define OMX_COMPONENT_INPUT_DISABLE_PENDING 0
#define OMX_COMPONENT_OUTPUT_DISABLE_PENDING 0
#define USE_ION
#define _ANDROID_ICS_

typedef int OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
typedef unsigned int OMX_U32;
typedef struct OMX_BUFFERHEADERTYPE OMX_BUFFERHEADERTYPE;

struct OMX_BUFFERHEADERTYPE {
    // dummy structure
};

class omx_video {
public:
    OMX_ERRORTYPE free_buffer(OMX_IN OMX_HANDLETYPE hComp,
                             OMX_IN OMX_U32 port,
                             OMX_IN OMX_BUFFERHEADERTYPE* buffer);
    
    int m_state;
    unsigned long m_flags;
    struct {
        int bEnabled;
        unsigned int nBufferCountActual;
        int bPopulated;
    } m_sInPortDef, m_sOutPortDef;
    OMX_BUFFERHEADERTYPE* m_inp_mem_ptr;
    OMX_BUFFERHEADERTYPE* m_out_mem_ptr;
    OMX_BUFFERHEADERTYPE* meta_buffer_hdr;
    unsigned long m_inp_bm_count;
    unsigned long m_out_bm_count;
    bool meta_mode_enable;
    bool input_use_buffer;
    bool output_use_buffer;
    void* m_pInput_pmem;
    void* m_pOutput_pmem;
    void* m_pInput_ion;
    void* m_pOutput_ion;

    void post_event(int, int, int);
    void free_input_buffer(OMX_BUFFERHEADERTYPE*);
    void free_output_buffer(OMX_BUFFERHEADERTYPE*);
    bool release_input_done();
    bool release_output_done();
    bool release_done();
    int dev_stop();
};

#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_HIGH(...)

#define BITMASK_PRESENT(flags, bit) 0
#define BITMASK_CLEAR(flags, bit)