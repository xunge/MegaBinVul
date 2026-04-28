#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OMX_IN
#define OMX_HANDLETYPE void*
typedef int OMX_ERRORTYPE;
#define OMX_ErrorNone 0
#define OMX_StateLoaded 0
#define _ANDROID_
#define _ANDROID_ICS_
#define MAX_NUM_INPUT_OUTPUT_BUFFERS 32
#define OUTPUT_EXTRADATA_LOG

typedef struct {
    void* pBuffer;
} OMX_BUFFERHEADERTYPE;

typedef struct {
    int actualcount;
} buf_count_t;

typedef struct {
    buf_count_t op_buf;
    buf_count_t ip_buf;
    int video_driver_fd;
} drv_ctx_t;

typedef struct {
    void* mutils;
} frame_parser_t;

typedef struct {
    FILE* infile;
    FILE* outfile;
} debug_t;

typedef struct {
    int m_size;
    int m_read;
    int m_write;
} msg_queue_t;

typedef struct {
    void (*free_output_buffer)(OMX_BUFFERHEADERTYPE*);
    void (*free_input_buffer)(int, OMX_BUFFERHEADERTYPE*);
} client_buffers_t;

typedef struct {
    void (*reset_ts_list)(void);
} timestamp_list_t;

typedef struct {
    char data[256];
} nativebuffer;

typedef struct {
    void* pData;
} vendor_config_t;

struct DivXDrmDecrypt {};
struct H264Parser {};
struct UtilsParser {};

struct omx_vdec {
    drv_ctx_t drv_ctx;
    frame_parser_t m_frame_parser;
    debug_t m_debug;
    msg_queue_t m_ftb_q, m_cmd_q, m_etb_q;
    client_buffers_t client_buffers;
    timestamp_list_t m_timestamp_list;
    nativebuffer native_buffer[MAX_NUM_INPUT_OUTPUT_BUFFERS];
    vendor_config_t m_vendor_config;
    
    OMX_BUFFERHEADERTYPE* m_out_mem_ptr;
    OMX_BUFFERHEADERTYPE* m_inp_mem_ptr;
    OMX_BUFFERHEADERTYPE* m_inp_heap_ptr;
    OMX_BUFFERHEADERTYPE h264_scratch;
    H264Parser* h264_parser;
    void* m_platform_list;
    DivXDrmDecrypt* iDivXDrmDecrypt;
    int m_state;
    int m_debug_timestamp;
    unsigned int m_out_bm_count;
    unsigned int m_inp_bm_count;
    FILE* outputExtradataFile;

    OMX_ERRORTYPE component_deinit(OMX_IN OMX_HANDLETYPE hComp);
    void free_output_buffer(OMX_BUFFERHEADERTYPE* buffer);
    void free_input_buffer(int index, OMX_BUFFERHEADERTYPE* buffer);
};

#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_HIGH(...)
#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_INFO(...)
#define BITMASK_PRESENT(ptr, bit) (0)
#define BITMASK_CLEAR(ptr, bit)
#define release_output_done() (0)
#define release_input_done() (0)
#define free_input_buffer_header()
#define free_output_buffer_header()