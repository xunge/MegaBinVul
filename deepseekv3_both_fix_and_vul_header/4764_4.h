#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/videodev2.h>

typedef int32_t OMX_ERRORTYPE;
typedef void* OMX_HANDLETYPE;
typedef uint32_t OMX_INDEXTYPE;
typedef void* OMX_PTR;
typedef uint32_t OMX_U32;
typedef uint8_t OMX_U8;
typedef int OMX_BOOL;

#define OMX_ErrorNone 0
#define OMX_ErrorInvalidState 1
#define OMX_ErrorUnsupportedSetting 2
#define OMX_ErrorHardware 3
#define OMX_ErrorBadPortIndex 4
#define OMX_ErrorInsufficientResources 5
#define OMX_ErrorNotImplemented 6

#define OMX_StateInvalid 0
#define OMX_CORE_INPUT_PORT_INDEX 0

#define OMX_IndexConfigVideoNalSize 0
#define OMX_IndexVendorVideoExtraData 0
#define OMX_IndexVendorVideoFrameRate 0
#define OMX_QcomIndexConfigPerfLevel 0
#define OMX_IndexConfigPriority 0
#define OMX_IndexConfigOperatingRate 0

#define DEBUG_PRINT_ERROR(...)
#define DEBUG_PRINT_LOW(...)
#define DEBUG_PRINT_HIGH(...)

#define VALIDATE_OMX_PARAM_DATA(x, y)

#define OMX_IN

#define V4L2_CID_MPEG_VIDC_VIDEO_STREAM_FORMAT 0
#define V4L2_MPEG_VIDC_VIDEO_NAL_FORMAT_STARTCODES 0
#define V4L2_MPEG_VIDC_VIDEO_NAL_FORMAT_TWO_BYTE_LENGTH 1
#define V4L2_MPEG_VIDC_VIDEO_NAL_FORMAT_FOUR_BYTE_LENGTH 2
#define V4L2_CID_MPEG_VIDC_SET_PERF_LEVEL 0
#define V4L2_CID_MPEG_VIDC_PERF_LEVEL_NOMINAL 0
#define V4L2_CID_MPEG_VIDC_PERF_LEVEL_TURBO 1
#define V4L2_CID_MPEG_VIDC_VIDEO_PRIORITY 0
#define V4L2_MPEG_VIDC_VIDEO_PRIORITY_REALTIME_ENABLE 0
#define V4L2_MPEG_VIDC_VIDEO_PRIORITY_REALTIME_DISABLE 1
#define V4L2_CID_MPEG_VIDC_VIDEO_OPERATING_RATE 0

typedef uint8_t uint8;

struct OMX_VIDEO_CONFIG_NALSIZE {
    OMX_U32 nNaluBytes;
};

struct OMX_VENDOR_EXTRADATATYPE {
    OMX_U32 nPortIndex;
    OMX_U32 nDataSize;
    OMX_U8* pData;
};

struct OMX_VENDOR_VIDEOFRAMERATE {
    OMX_U32 nPortIndex;
    OMX_U32 nFps;
    OMX_BOOL bEnabled;
};

struct OMX_QCOM_VIDEO_CONFIG_PERF_LEVEL {
    OMX_U32 ePerfLevel;
};

struct OMX_PARAM_U32TYPE {
    OMX_U32 nU32;
};

enum {
    OMX_QCOM_PerfLevelNominal,
    OMX_QCOM_PerfLevelTurbo
};

#define VC1_SP_MP_START_CODE_MASK 0
#define VC1_SP_MP_START_CODE 0
#define VC1_AP_SEQ_START_CODE 0
#define VC1_STRUCT_C_LEN 0

enum {
    VC1_SP_MP_RCV,
    VC1_AP
};

struct omx_vdec {
    int video_driver_fd;
    struct {
        char* kind;
        struct {
            int fps_numerator;
            int fps_denominator;
        } frame_rate;
        int video_driver_fd;
    } drv_ctx;
    struct {
        OMX_U32 nPortIndex;
        OMX_U32 nDataSize;
        OMX_U8* pData;
    } m_vendor_config;
    int m_vc1_profile;
    int m_state;
    int nal_length;
    bool arbitrary_bytes;
    bool client_set_fps;
    int frm_int;
    struct {
        void init_nal_length(int);
    } m_frame_parser;
    
    OMX_ERRORTYPE set_config(OMX_HANDLETYPE hComp, OMX_INDEXTYPE configIndex, OMX_PTR configData);
};

void Q16ToFraction(OMX_U32, int&, int&);