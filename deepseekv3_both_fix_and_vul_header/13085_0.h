#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef int Bool;
#define GF_TRUE 1
#define GF_FALSE 0

#define GF_M2_STREAMID_PADDING 0xBE
#define GF_M2_STREAMID_PROGRAM_STREAM_MAP 0xBC
#define GF_M2_STREAMID_PRIVATE_2 0xBF
#define GF_M2_STREAMID_ECM 0xF0
#define GF_M2_STREAMID_EMM 0xF1
#define GF_M2_STREAMID_PROGRAM_STREAM_DIRECTORY 0xFF
#define GF_M2_STREAMID_DSMCC 0xF2
#define GF_M2_STREAMID_H222_TYPE_E 0xF8

#define GF_M2TS_AUDIO_TRUEHD 0x83
#define GF_M2TS_AUDIO_EC3 0x87

#define GF_M2TS_EVT_PES_TIMING 0
#define GF_M2TS_EVT_SL_PCK 1
#define GF_M2TS_EVT_TEMI_TIMECODE 2

#define GF_M2TS_PES_PCK_RAP 1

#define GF_LOG_DEBUG 0
#define GF_LOG_CONTAINER 0
#define GF_LOG_WARNING 1
#define GF_LOG_ERROR 2

#define LLU "%llu"

typedef struct GF_M2TS_Demuxer GF_M2TS_Demuxer;
typedef struct GF_M2TS_PES GF_M2TS_PES;
typedef struct GF_M2TS_ES GF_M2TS_ES;
typedef struct GF_M2TS_PESHeader GF_M2TS_PESHeader;
typedef struct GF_M2TS_PES_PCK GF_M2TS_PES_PCK;
typedef struct GF_M2TS_SL_PCK GF_M2TS_SL_PCK;
typedef struct GF_M2TS_TEMI_TC GF_M2TS_TEMI_TC;

struct GF_M2TS_PESHeader {
    u32 PTS;
    u32 DTS;
    u32 hdr_data_len;
    u32 pck_len;
};

struct GF_M2TS_PES_PCK {
    u32 PTS;
    u32 DTS;
    GF_M2TS_PES *stream;
    u32 flags;
};

struct GF_M2TS_SL_PCK {
    char *data;
    u32 data_len;
    GF_M2TS_ES *stream;
};

struct GF_M2TS_TEMI_TC {
    u32 pes_pts;
    u32 pid;
};

struct GF_M2TS_PES {
    u8 *pck_data;
    u32 pck_data_len;
    u32 pid;
    u32 stream_type;
    u32 PTS;
    u32 DTS;
    u32 rap;
    u32 mpeg4_es_id;
    u32 pes_len;
    u32 (*reframe)(GF_M2TS_Demuxer *ts, GF_M2TS_PES *pes, Bool same_pts, u8 *data, u32 size, GF_M2TS_PESHeader *pesh);
    u8 *prev_data;
    u32 prev_data_len;
    u32 temi_pending;
    u32 temi_tc_desc_len;
    GF_M2TS_TEMI_TC temi_tc;
    Bool is_resume;
    u32 pes_end_packet_number;
};

struct GF_M2TS_Demuxer {
    void (*notify_pes_timing)(void);
    void (*on_event)(GF_M2TS_Demuxer *ts, u32 evt_type, void *param);
    u32 pck_number;
    Bool seek_mode;
};

void gf_m2ts_pes_header(GF_M2TS_PES *pes, u8 *data, u32 size, GF_M2TS_PESHeader *pesh);
void gf_m2ts_store_temi(GF_M2TS_Demuxer *ts, GF_M2TS_PES *pes);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
void GF_LOG(int level, int category, const char *fmt, ...);