#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef enum {
    GF_OK = 0,
    GF_EOS,
    GF_OUT_OF_MEM,
    GF_FALSE = 0,
    GF_TRUE = 1
} GF_Err;

typedef struct GF_Filter GF_Filter;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_LATMDmxCtx GF_LATMDmxCtx;
typedef enum {
    GF_FILTER_SAP_NONE,
    GF_FILTER_SAP_1
} GF_FilterSAPType;

#define GF_FILTER_NO_TS 0
#define LATM_DMX_MAX_SIZE 4096
#define GF_BITSTREAM_READ 0

enum GF_CODECID {
    GF_CODECID_USAC
};

struct GF_LATMDmxCtx {
    GF_Err in_error;
    struct {
        int num;
    } duration;
    GF_FilterPid *opid;
    int is_playing;
    GF_FilterPid *ipid;
    u32 latm_buffer_size;
    GF_FilterPacket *src_pck;
    u32 latm_buffer_alloc;
    u8 *latm_buffer;
    u64 timescale;
    u64 cts;
    u32 resume_from;
    GF_BitStream *bs;
    int in_seek;
    u64 start_range;
    u32 sr_idx;
    u64 dts_inc;
    struct {
        u32 base_object_type;
    } acfg;
    int prev_sap;
};

extern const u32 GF_M4ASampleRates[];
extern GF_LATMDmxCtx* gf_filter_get_udta(GF_Filter *filter);
extern GF_FilterPacket *gf_filter_pid_get_packet(GF_FilterPid *pid);
extern int gf_filter_pid_is_eos(GF_FilterPid *pid);
extern void gf_filter_pid_set_eos(GF_FilterPid *pid);
extern void gf_filter_pck_unref(GF_FilterPacket *pck);
extern u8 *gf_filter_pck_get_data(GF_FilterPacket *pck, u32 *size);
extern u64 gf_filter_pck_get_cts(GF_FilterPacket *pck);
extern GF_FilterPacket *gf_filter_pck_new_alloc(GF_FilterPid *pid, u32 size, u8 **data);
extern void gf_filter_pck_merge_properties(GF_FilterPacket *src, GF_FilterPacket *dst);
extern void gf_filter_pck_set_cts(GF_FilterPacket *pck, u64 cts);
extern void gf_filter_pck_set_duration(GF_FilterPacket *pck, u64 duration);
extern void gf_filter_pck_set_framing(GF_FilterPacket *pck, int start, int end);
extern void gf_filter_pck_set_sap(GF_FilterPacket *pck, GF_FilterSAPType sap);
extern void gf_filter_pck_send(GF_FilterPacket *pck);
extern void gf_filter_pck_ref_props(GF_FilterPacket **pck);
extern void gf_filter_pid_drop_packet(GF_FilterPid *pid);
extern GF_BitStream *gf_bs_new(const void *buffer, u32 size, u32 mode);
extern void gf_bs_reassign_buffer(GF_BitStream *bs, const void *buffer, u32 size);
extern u64 gf_bs_get_position(GF_BitStream *bs);
extern void gf_bs_seek(GF_BitStream *bs, u64 offset);
extern void *gf_realloc(void *ptr, u32 size);
extern GF_Err latm_dmx_check_dur(GF_Filter *filter, GF_LATMDmxCtx *ctx);
extern int latm_dmx_sync_frame_bs(GF_BitStream *bs, void *acfg, u32 *latm_frame_size, u8 *latm_buffer, void *null);
extern void latm_dmx_check_pid(GF_Filter *filter, GF_LATMDmxCtx *ctx);
extern void latm_dmx_update_cts(GF_LATMDmxCtx *ctx);