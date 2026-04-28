#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

typedef enum {
    GF_OK = 0,
    GF_EOS,
    GF_OUT_OF_MEM,
    GF_BAD_PARAM,
    GF_NOT_SUPPORTED,
    GF_IO_ERR,
    GF_BUFFER_TOO_SMALL,
    GF_CORRUPTED_DATA,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_MEDIA,
    GF_LOG_DEBUG
} GF_LogLevel;

typedef enum {
    GF_FILTER_SAP_NONE = 0,
    GF_FILTER_SAP_1 = 1
} GF_FilterSAPType;

typedef enum {
    GF_BITSTREAM_READ = 0
} GF_BitStreamMode;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef int Bool;
#define GF_TRUE 1
#define GF_FALSE 0

#define GF_FILTER_NO_TS UINT64_MAX
#define GF_FILTER_NO_BO UINT64_MAX

#define M2V_SEQ_START_CODE 0xB3
#define M2V_EXT_START_CODE 0xB5
#define M2V_PIC_START_CODE 0x00
#define M4V_VOS_START_CODE 0xB0
#define M4V_VOL_START_CODE 0xB5
#define M4V_VOP_START_CODE 0xB6
#define M4V_GOV_START_CODE 0xB3
#define M4V_VO_START_CODE 0xB1
#define M4V_VISOBJ_START_CODE 0xB2

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_M4VParser GF_M4VParser;

typedef struct {
    u32 num, den;
} GF_Fraction;

typedef struct {
    u8 VideoPL;
} GF_MPEG4VisualDSI;

typedef struct {
    GF_Fraction duration;
    GF_FilterPid *ipid;
    GF_FilterPid *opid;
    GF_FilterPacket *src_pck;
    u64 cts;
    u64 dts;
    u64 prev_dts;
    GF_Fraction cur_fps;
    u32 timescale;
    u8 *hdr_store;
    u32 hdr_store_size;
    u32 hdr_store_alloc;
    u32 resume_from;
    GF_BitStream *bs;
    GF_M4VParser *vparser;
    Bool is_mpg12;
    Bool recompute_cts;
    Bool input_is_au_start;
    Bool input_is_au_end;
    Bool frame_started;
    Bool is_playing;
    Bool in_seek;
    Bool forced_packed;
    Bool is_packed;
    Bool vfr;
    Bool is_vfr;
    u32 b_frames;
    u32 max_b;
    u32 nb_i;
    u32 nb_p;
    u32 nb_b;
    u32 nb_frames;
    u64 last_ref_cts;
    u64 start_range;
    GF_MPEG4VisualDSI dsi;
    u32 bytes_in_header;
} GF_MPGVidDmxCtx;

static void GF_LOG(GF_LogLevel level, GF_LogLevel media, const char* fmt, ...) {}
static const char* gf_error_to_string(GF_Err e) { return ""; }