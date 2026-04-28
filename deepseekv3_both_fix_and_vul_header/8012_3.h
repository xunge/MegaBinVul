#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <limits.h>
#include <cstdio>
#include <unistd.h>

#define OMX_FALSE 0
#define OMX_TRUE 1
#define OMX_COMPONENT_GENERATE_FTB 0
#define OMX_StateInvalid 0
#define CAPTURE_PORT 0
#define OUTPUT_PORT 1
#define MAX_NUM_INPUT_OUTPUT_BUFFERS 32
#define BUFFER_LOG_LOC ""
#define PROPERTY_VALUE_MAX 92
#define _ANDROID_
#define _ANDROID_ICS_

typedef int32_t OMX_S32;
typedef uint32_t OMX_U32;
typedef int64_t OMX_S64;
typedef uint64_t OMX_U64;
typedef uint8_t OMX_U8;
typedef int8_t OMX_S8;
typedef void* OMX_PTR;
typedef void* OMX_HANDLETYPE;
typedef int64_t OMX_TICKS;

#define DEBUG_PRINT_HIGH(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define DEBUG_PRINT_LOW(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define property_get(name, value, default_value) strncpy(value, default_value, PROPERTY_VALUE_MAX)
#define strlcpy(dest, src, size) strncpy(dest, src, size)

typedef enum {
    VC1_SP_MP_RCV,
    VC1_AP,
    VC1_SIMPLE,
    VC1_ADVANCE
} vc1_profile_type;

typedef enum {
    CODEC_TYPE_MPEG2,
    CODEC_TYPE_H264,
    CODEC_TYPE_H263,
    CODEC_TYPE_VC1,
    CODEC_TYPE_MPEG4,
    CODEC_TYPE_DIVX,
    CODEC_TYPE_VP8,
    CODEC_TYPE_VP9,
    CODEC_TYPE_HEVC
} codec_type;

struct drv_ctx_t {
    bool timestamp_adjust;
    int video_driver_fd;
    struct {
        OMX_U32 size;
        OMX_U8* data;
    } extradata_info;
};

struct nativebuffer {
    int fd;
    size_t size;
    void* data;
};

struct OMX_QCOM_FRAME_PACK_ARRANGEMENT {
    OMX_U32 cancel_flag;
};

struct OMX_BUFFERHEADERTYPE {
    OMX_U32 nSize;
    OMX_U8* pBuffer;
    OMX_U32 nAllocLen;
    OMX_U32 nFilledLen;
    OMX_U32 nOffset;
    OMX_PTR pAppPrivate;
    OMX_PTR pPlatformPrivate;
    OMX_PTR pInputPortPrivate;
    OMX_PTR pOutputPortPrivate;
    OMX_HANDLETYPE hMarkTargetComponent;
    OMX_PTR pMarkData;
    OMX_U32 nTickCount;
    OMX_TICKS nTimeStamp;
    OMX_U32 nFlags;
    OMX_U32 nOutputPortIndex;
    OMX_U32 nInputPortIndex;
};

struct vdec_time {
    void start() {}
};

struct vdec_debug {
    OMX_U32 in_buffer_log;
    OMX_U32 out_buffer_log;
    char log_loc[PROPERTY_VALUE_MAX];
};

struct vdec_client_buffers {
    void set_vdec_client(void* client) {}
};

struct vdec_timestamp_reorder {
    void set_timestamp_reorder_mode(bool mode) {}
    void enable_debug_print(bool enable) {}
};

class omx_vdec {
public:
    omx_vdec();
private:
    bool m_error_propogated;
    OMX_U32 m_state;
    void* m_app_data;
    void* m_inp_mem_ptr;
    void* m_out_mem_ptr;
    bool input_flush_progress;
    bool output_flush_progress;
    bool input_use_buffer;
    bool output_use_buffer;
    bool ouput_egl_buffers;
    OMX_U32 m_use_output_pmem;
    OMX_U32 m_out_mem_region_smi;
    OMX_U32 m_out_pvt_entry_pmem;
    int pending_input_buffers;
    int pending_output_buffers;
    int m_out_bm_count;
    int m_inp_bm_count;
    OMX_U32 m_inp_bPopulated;
    OMX_U32 m_out_bPopulated;
    int m_flags;
#ifdef _ANDROID_
    void* m_heap_ptr;
#endif
    OMX_U32 m_inp_bEnabled;
    OMX_U32 m_out_bEnabled;
    int m_in_alloc_cnt;
    void* m_platform_list;
    void* m_platform_entry;
    void* m_pmem_info;
    void* h264_parser;
    bool arbitrary_bytes;
    void* psource_frame;
    void* pdest_frame;
    void* m_inp_heap_ptr;
    void* m_phdr_pmem_ptr;
    int m_heap_inp_bm_count;
    codec_type codec_type_parse;
    bool first_frame_meta;
    int frame_count;
    int nal_count;
    int nal_length;
    bool look_ahead_nal;
    int first_frame;
    void* first_buffer;
    int first_frame_size;
    void* m_device_file_ptr;
    vc1_profile_type m_vc1_profile;
    int64_t h264_last_au_ts;
    int h264_last_au_flags;
    int m_disp_hor_size;
    int m_disp_vert_size;
    int64_t prev_ts;
    bool rst_prev_ts;
    int frm_int;
    bool in_reconfig;
    void* m_display_id;
    int client_extradata;
    int m_reject_avc_1080p_mp;
#ifdef _ANDROID_
    OMX_U32 m_enable_android_native_buffers;
    OMX_U32 m_use_android_native_buffers;
    void* iDivXDrmDecrypt;
#endif
    void* m_desc_buffer_ptr;
    bool secure_mode;
    void* m_other_extradata;
    int m_profile;
    bool client_set_fps;
    int64_t m_last_rendered_TS;
    int m_queued_codec_config_count;
    bool secure_scaling_to_non_secure_opb;
    vdec_debug m_debug;
    struct {
        int unused;
    } m_cmp;
    struct {
        int unused;
    } m_cb;
    drv_ctx_t drv_ctx;
    OMX_BUFFERHEADERTYPE h264_scratch;
    char m_hwdevice_name[128];
    OMX_U32 m_demux_offsets[8192];
    struct {
        int unused;
    } m_custom_buffersize;
    int m_demux_entries;
    pthread_t msg_thread_id;
    pthread_t async_thread_id;
    bool msg_thread_created;
    bool async_thread_created;
#ifdef _ANDROID_ICS_
    nativebuffer native_buffer[MAX_NUM_INPUT_OUTPUT_BUFFERS];
#endif
    OMX_QCOM_FRAME_PACK_ARRANGEMENT m_frame_pack_arrangement;
    struct {
        void* pData;
    } m_vendor_config;
    pthread_mutex_t m_lock;
    pthread_mutex_t c_lock;
    pthread_mutex_t buf_lock;
    sem_t m_cmd_lock;
    sem_t m_safe_flush;
    bool streaming[2];
    int m_fill_output_msg;
    vdec_client_buffers client_buffers;
    bool dynamic_buf_mode;
    void* out_dynamic_list;
    bool is_down_scalar_enabled;
    bool m_smoothstreaming_mode;
    int m_smoothstreaming_width;
    int m_smoothstreaming_height;
    bool is_q6_platform;
#ifdef _ANDROID_
    int debug_level;
    int perf_flag;
    vdec_time dec_time;
    int proc_frms;
    int latency;
    int prev_n_filled_len;
    int m_debug_timestamp;
    vdec_timestamp_reorder time_stamp_dts;
    int m_debug_concealedmb;
    int m_debug_extradata;
    int m_disable_dynamic_buf_mode;
#endif
};