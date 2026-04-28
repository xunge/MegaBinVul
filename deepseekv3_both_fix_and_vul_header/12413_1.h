#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int GF_Err;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    int num;
} GF_Fraction;

typedef struct {
    u32 base_object_type;
} GF_ACfg;

typedef struct {
    GF_Err in_error;
    GF_Fraction duration;
    void *opid;
    void *ipid;
    int is_playing;
    u32 latm_buffer_size;
    u32 latm_buffer_alloc;
    u8 *latm_buffer;
    void *bs;
    u32 resume_from;
    u32 timescale;
    u64 cts;
    u32 dts_inc;
    int in_seek;
    double start_range;
    u32 sr_idx;
    void *src_pck;
    GF_ACfg acfg;
    int prev_sap;
} GF_LATMDmxCtx;

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef enum {
    GF_FILTER_SAP_NONE,
    GF_FILTER_SAP_1
} GF_FilterSAPType;

#define GF_FILTER_NO_TS 0
#define GF_EOS 1
#define GF_OK 0
#define GF_FALSE 0
#define GF_TRUE 1
#define GF_CODECID_USAC 1
#define GF_BITSTREAM_READ 0

extern const u32 GF_M4ASampleRates[];

extern GF_Err latm_dmx_check_dur(GF_Filter *filter, GF_LATMDmxCtx *ctx);
extern GF_Err latm_dmx_sync_frame_bs(void *bs, GF_ACfg *acfg, u32 *latm_frame_size, u8 *latm_buffer, void *unused);
extern void latm_dmx_check_pid(GF_Filter *filter, GF_LATMDmxCtx *ctx);
extern void latm_dmx_update_cts(GF_LATMDmxCtx *ctx);

extern void *gf_bs_new(const void *buffer, u32 size, u32 mode);
extern void gf_bs_reassign_buffer(void *bs, const void *buffer, u32 size);
extern u64 gf_bs_get_position(void *bs);
extern void gf_bs_seek(void *bs, u64 offset);
extern void *gf_realloc(void *ptr, u32 size);

extern GF_LATMDmxCtx *gf_filter_get_udta(GF_Filter *filter);
extern GF_FilterPacket *gf_filter_pid_get_packet(void *pid);
extern int gf_filter_pid_is_eos(void *pid);
extern void gf_filter_pid_set_eos(void *pid);
extern void gf_filter_pck_unref(GF_FilterPacket *pck);
extern const void *gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size);
extern u64 gf_filter_pck_get_cts(GF_FilterPacket *pck);
extern GF_FilterPacket *gf_filter_pck_new_alloc(void *pid, u32 size, u8 **data);
extern void gf_filter_pck_merge_properties(GF_FilterPacket *src, GF_FilterPacket *dst);
extern void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts);
extern void gf_filter_pck_set_duration(GF_FilterPacket *pck, u32 duration);
extern void gf_filter_pck_set_framing(GF_FilterPacket *pck, int start, int end);
extern void gf_filter_pck_set_sap(GF_FilterPacket *pck, GF_FilterSAPType sap);
extern void gf_filter_pck_send(GF_FilterPacket *pck);
extern void gf_filter_pid_drop_packet(void *pid);
extern void gf_filter_pck_ref_props(GF_FilterPacket **pck);