#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;
typedef bool Bool;

#define GF_FALSE false
#define GF_TRUE true

typedef enum {
    GF_OK,
    GF_EOS,
    GF_OUT_OF_MEM,
    GF_FILTER_NO_TS,
    GF_FILTER_NO_BO
} GF_Err;

typedef enum {
    GF_LOG_WARNING,
    GF_LOG_MEDIA
} GF_LogLevel;

typedef enum {
    GF_FILTER_SAP_NONE,
    GF_FILTER_SAP_1
} GF_FilterSAPType;

typedef enum {
    GF_BITSTREAM_READ
} GF_BitStreamMode;

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_BitStream GF_BitStream;

typedef struct {
    int num;
    int den;
} GF_Fraction;

typedef struct {
    GF_Fraction fps;
    GF_Fraction duration;
    u64 cts;
    u32 timescale;
    u32 resume_from;
    u32 bytes_in_header;
    u8 hdr_store[8];
    GF_BitStream *bs;
    GF_FilterPid *ipid;
    GF_FilterPid *opid;
    GF_FilterPacket *src_pck;
    Bool notime;
    Bool in_seek;
    Bool is_playing;
    u32 start_range;
} GF_H263DmxCtx;

void GF_LOG(GF_LogLevel level, GF_LogLevel media, const char *fmt, ...);
void h263dmx_check_dur(GF_Filter *filter, GF_H263DmxCtx *ctx);
s32 h263dmx_next_start_code(u8 *start, u32 remain);
void h263_get_pic_size(GF_BitStream *bs, u32 fmt, u32 *w, u32 *h);
void h263dmx_check_pid(GF_Filter *filter, GF_H263DmxCtx *ctx, u32 w, u32 h);
void h263dmx_update_cts(GF_H263DmxCtx *ctx);