#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef enum {
    GF_OK,
    GF_EOS,
    GF_OUT_OF_MEM
} GF_Err;

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int Bool;

#define GF_TRUE 1
#define GF_FALSE 0
#define GF_FILTER_NO_TS 0
#define GF_FILTER_NO_BO 0
#define AC3_FRAME_SIZE 1536
#define GF_BITSTREAM_READ 0
#define GF_LOG_WARNING 1
#define GF_LOG_MEDIA 1
#define GF_FILTER_SAP_1 1

typedef struct {
    int num;
} GF_Fraction;

typedef struct {
    u32 framesize;
    u32 sample_rate;
} AC3Header;

typedef struct {
    u32 ac3_buffer_size;
    u32 ac3_buffer_alloc;
    u8 *ac3_buffer;
    u32 resume_from;
    u64 cts;
    u32 timescale;
    u32 sample_rate;
    u64 byte_offset;
    u32 start_range;
    u32 dts_inc;
    Bool in_seek;
    Bool is_playing;
    GF_Fraction duration;
    void *ipid;
    void *opid;
    void *bs;
    void *src_pck;
    AC3Header hdr;
    Bool (*ac3_parser_bs)(void *bs, AC3Header *hdr, Bool);
} GF_AC3DmxCtx;

typedef struct {
} GF_Filter;
typedef struct {
} GF_FilterPacket;
typedef struct {
} GF_FilterPid;

void GF_LOG(int level, int category, const char *format, ...);
void *gf_filter_get_udta(GF_Filter *filter);
void *gf_filter_pid_get_packet(void *pid);
int gf_filter_pid_is_eos(void *pid);
void gf_filter_pid_drop_packet(void *pid);
void *gf_filter_pck_new_alloc(void *pid, u32 size, u8 **output);
void gf_filter_pck_merge_properties(void *src, void *dst);
void gf_filter_pck_set_dts(void *pck, u64 dts);
void gf_filter_pck_set_cts(void *pck, u64 cts);
void gf_filter_pck_set_duration(void *pck, u32 duration);
void gf_filter_pck_set_sap(void *pck, int sap);
void gf_filter_pck_set_framing(void *pck, int framing, int is_frame);
void gf_filter_pck_send(void *pck);
void gf_filter_pid_set_eos(void *pid);
void gf_filter_pck_unref(void *pck);
void gf_filter_pck_ref_props(void **pck);
u64 gf_filter_pck_get_byte_offset(void *pck);
u64 gf_filter_pck_get_cts(void *pck);
const u8 *gf_filter_pck_get_data(void *pck, u32 *size);
void *gf_bs_new(const u8 *data, u32 size, int mode);
void gf_bs_reassign_buffer(void *bs, const u8 *data, u32 size);
u32 gf_bs_get_position(void *bs);
void *gf_realloc(void *ptr, size_t size);
u32 gf_timestamp_rescale(u32 duration, u32 src_timescale, u32 dst_timescale);
void gf_filter_pck_set_byte_offset(void *pck, u64 offset);

void ac3dmx_check_dur(GF_Filter *filter, GF_AC3DmxCtx *ctx);
void ac3dmx_check_pid(GF_Filter *filter, GF_AC3DmxCtx *ctx);
void ac3dmx_update_cts(GF_AC3DmxCtx *ctx);