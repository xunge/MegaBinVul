#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned char Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef enum {
    GF_OK,
    GF_EOS,
    GF_OUT_OF_MEM,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef enum {
    GF_LOG_WARNING,
    GF_LOG_ERROR,
    GF_LOG_MEDIA
} GF_LogLevel;

typedef enum {
    GF_AUDIO_FMT_U8,
    GF_AUDIO_FMT_S16,
    GF_AUDIO_FMT_S24,
    GF_AUDIO_FMT_S32,
    GF_AUDIO_FMT_FLT
} GF_AudioFormat;

typedef enum {
    GF_FILTER_SAP_1
} GF_FilterSAPType;

typedef enum {
    GF_BITSTREAM_READ
} GF_BitStreamMode;

typedef enum {
    GF_FEVT_STOP,
    GF_FEVT_SOURCE_SEEK
} GF_FilterEventType;

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_BitStream GF_BitStream;

typedef struct {
    u64 start_offset;
} GF_FilterSeek;

typedef struct GF_FilterEvent {
    GF_FilterEventType type;
    GF_FilterPid *pid;
    union {
        GF_FilterSeek seek;
    };
} GF_FilterEvent;

typedef struct GF_PCMReframeCtx {
    Bool done;
    Bool is_playing;
    Bool reverse_play;
    u32 probe_wave;
    u8 *probe_data;
    u32 probe_data_size;
    u32 wav_hdr_size;
    GF_FilterPid *ipid;
    GF_FilterPid *opid;
    GF_FilterPacket *out_pck;
    u8 *out_data;
    u32 nb_bytes_in_frame;
    u32 frame_size;
    u32 framelen;
    u32 Bps;
    u32 ch;
    u32 sr;
    GF_AudioFormat safmt;
    u64 cts;
    u64 filepos;
} GF_PCMReframeCtx;

#define GF_4CC(a,b,c,d) (((a)<<24)|((b)<<16)|((c)<<8)|(d))
#define GF_FEVT_INIT(evt, evt_type, evt_pid) do { \
    (evt).type = evt_type; \
    (evt).pid = evt_pid; \
} while(0)

void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_free(void *ptr);

void GF_LOG(GF_LogLevel level, GF_LogLevel domain, const char *fmt, ...);

GF_BitStream *gf_bs_new(const void *buffer, u32 size, GF_BitStreamMode mode);
void gf_bs_del(GF_BitStream *bs);
u32 gf_bs_read_u32(GF_BitStream *bs);
u32 gf_bs_read_u32_le(GF_BitStream *bs);
u16 gf_bs_read_u16_le(GF_BitStream *bs);
void gf_bs_skip_bytes(GF_BitStream *bs, u32 nbBytes);
Bool gf_bs_is_overflow(GF_BitStream *bs);
u32 gf_bs_available(GF_BitStream *bs);
u64 gf_bs_get_position(GF_BitStream *bs);

GF_PCMReframeCtx *gf_filter_get_udta(GF_Filter *filter);
GF_FilterPacket *gf_filter_pid_get_packet(GF_FilterPid *pid);
Bool gf_filter_pid_is_eos(GF_FilterPid *pid);
void gf_filter_pid_set_eos(GF_FilterPid *pid);
void gf_filter_pid_drop_packet(GF_FilterPid *pid);
void gf_filter_pid_set_discard(GF_FilterPid *pid, Bool discard);
void gf_filter_pid_send_event(GF_FilterPid *pid, GF_FilterEvent *evt);

GF_FilterPacket *gf_filter_pck_new_alloc(GF_FilterPid *pid, u32 size, u8 **data);
void gf_filter_pck_truncate(GF_FilterPacket *pck, u32 size);
void gf_filter_pck_set_duration(GF_FilterPacket *pck, u32 duration);
void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts);
void gf_filter_pck_set_sap(GF_FilterPacket *pck, GF_FilterSAPType sap);
void gf_filter_pck_set_byte_offset(GF_FilterPacket *pck, u64 offset);
void *gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size);
u64 gf_filter_pck_get_byte_offset(GF_FilterPacket *pck);

void pcmreframe_flush_packet(GF_PCMReframeCtx *ctx);
void pcmreframe_configure_pid(GF_Filter *filter, GF_FilterPid *pid, Bool reconfigure);