#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int Bool;
typedef int GF_Err;
typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Fraction { u64 num, den; } GF_Fraction;

#define GF_OK 0
#define GF_EOS 1
#define GF_NON_COMPLIANT_BITSTREAM 2
#define GF_TRUE 1
#define GF_FALSE 0
#define GF_FILTER_NO_TS 0xFFFFFFFFFFFFFFFFULL
#define GF_FILTER_NO_BO 0xFFFFFFFFFFFFFFFFULL
#define GF_FILTER_SAP_1 1
#define GF_PROP_PID_SAMPLE_RATE 0
#define PROP_UINT(x) (x)

typedef struct {
    u32 sample_rate;
    u32 block_size;
} FLACHeader;

typedef struct {
    GF_FilterPid *ipid;
    GF_FilterPid *opid;
    u8 *flac_buffer;
    u32 flac_buffer_size;
    u32 flac_buffer_alloc;
    u32 sample_rate;
    u32 nb_channels;
    u32 bits_per_sample;
    u32 block_size;
    GF_Fraction duration;
    u32 timescale;
    u64 cts;
    u64 byte_offset;
    u32 resume_from;
    Bool in_error;
    Bool is_playing;
    Bool initialized;
    Bool in_seek;
    u64 start_range;
    GF_BitStream *bs;
    GF_FilterPacket *src_pck;
} GF_FLACDmxCtx;

static GF_Err flac_dmx_check_dur(GF_Filter *filter, GF_FLACDmxCtx *ctx) { return GF_OK; }
static GF_Err flac_parse_header(GF_FLACDmxCtx *ctx, u8 *data, u32 size, FLACHeader *hdr) { return GF_OK; }
static void flac_dmx_check_pid(GF_Filter *filter, GF_FLACDmxCtx *ctx, u8 *data, u32 size) {}
static void flac_dmx_update_cts(GF_FLACDmxCtx *ctx, u32 nb_samp) {}
static u32 gf_bs_read_u32(GF_BitStream *bs) { return 0; }
static u16 gf_bs_read_u16(GF_BitStream *bs) { return 0; }
static u32 gf_bs_read_u24(GF_BitStream *bs) { return 0; }
static u64 gf_bs_read_long_int(GF_BitStream *bs, u32 bits) { return 0; }
static int gf_bs_read_int(GF_BitStream *bs, int bits) { return 0; }
static void gf_bs_skip_bytes(GF_BitStream *bs, u32 size) {}
static u32 gf_bs_get_position(GF_BitStream *bs) { return 0; }
static u32 gf_bs_available(GF_BitStream *bs) { return 0; }
static void gf_bs_reassign_buffer(GF_BitStream *bs, u8 *data, u32 size) {}
static void *gf_realloc(void *ptr, size_t size) { return realloc(ptr, size); }
static void gf_filter_pid_drop_packet(GF_FilterPid *pid) {}
static void gf_filter_pck_unref(GF_FilterPacket *pck) {}
static void gf_filter_pck_send(GF_FilterPacket *pck) {}
static GF_FilterPacket *gf_filter_pck_new_alloc(GF_FilterPid *pid, u32 size, u8 **data) { return NULL; }
static void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts) {}
static void gf_filter_pck_set_duration(GF_FilterPacket *pck, u64 dur) {}
static void gf_filter_pck_set_sap(GF_FilterPacket *pck, u32 sap) {}
static void gf_filter_pck_set_framing(GF_FilterPacket *pck, Bool start, Bool end) {}
static void gf_filter_pck_set_byte_offset(GF_FilterPacket *pck, u64 offset) {}
static void gf_filter_pid_set_eos(GF_FilterPid *pid) {}
static void gf_filter_pid_set_property(GF_FilterPid *pid, u32 prop, void *value) {}
static u64 gf_filter_pck_get_cts(GF_FilterPacket *pck) { return 0; }
static u64 gf_filter_pck_get_byte_offset(GF_FilterPacket *pck) { return 0; }
static void *gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size) { return NULL; }
static Bool gf_filter_pid_is_eos(GF_FilterPid *pid) { return GF_FALSE; }
static GF_FilterPacket *gf_filter_pid_get_packet(GF_FilterPid *pid) { return NULL; }
static GF_FLACDmxCtx *gf_filter_get_udta(GF_Filter *filter) { return NULL; }
#define GF_4CC(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))
#define GF_LOG_ERROR 0
#define GF_LOG_WARNING 1
#define GF_LOG_PARSER 0
static void GF_LOG(int level, int category, const char *fmt, ...) {}