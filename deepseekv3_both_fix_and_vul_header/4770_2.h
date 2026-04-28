#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
#define OMX_IN
#define OMX_U32 uint32_t
#define OMX_StateLoaded 0
#define OMX_ErrorNone 0

#define DEBUG_PRINT_HIGH(...) printf(__VA_ARGS__)
#define DEBUG_PRINT_ERROR(...) printf(__VA_ARGS__)
#define DEBUG_PRINT_LOW(...) printf(__VA_ARGS__)
#define DEBUG_PRINT_INFO(...) printf(__VA_ARGS__)

#define BITMASK_PRESENT(mask, idx) (0)
#define BITMASK_CLEAR(mask, idx)

#ifdef _ANDROID_ICS_
#define meta_mode_enable 0
#endif

struct BufferHeader {
    void* pBuffer;
};

struct omx_venc {
    OMX_U32 m_state;
    BufferHeader* m_out_mem_ptr;
    BufferHeader* m_inp_mem_ptr;
    struct {
        OMX_U32 nBufferCountActual;
    } m_sOutPortDef, m_sInPortDef;
    unsigned long m_out_bm_count;
    unsigned long m_inp_bm_count;
    struct {
        int m_size;
        int m_read;
        int m_write;
    } m_ftb_q, m_cmd_q, m_etb_q;
#ifdef _ANDROID_
    struct {
        void clear() {}
    } m_heap_ptr;
#endif
    struct {
        void venc_close() {}
    } *handle;

    void free_output_buffer(BufferHeader*) {}
    void free_input_buffer(BufferHeader*) {}
    int release_output_done() { return 0; }
    int release_input_done() { return 0; }
    OMX_ERRORTYPE component_deinit(OMX_IN OMX_HANDLETYPE hComp);
};