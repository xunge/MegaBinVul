#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_OK,
    GF_NON_COMPLIANT_BITSTREAM,
    GF_OUT_OF_MEM
} GF_Err;

typedef enum {
    GF_FALSE = 0,
    GF_TRUE = 1
} GF_Bool;

typedef struct {
    u8 key_frame;
    u32 refresh_frame_flags;
} GF_AV1FrameState;

typedef struct {
    u8 *frame_obus;
    u32 frame_obus_alloc;
    void *bs;
    u8 clli_data[4];
    u8 mdcv_data[24];
    GF_AV1FrameState frame_state;
    u8 clli_valid;
    u8 mdcv_valid;
} GF_AV1State;

typedef struct {
    void *opid;
    void *src_pck;
    void *deps;
    u32 cts;
    u32 clli_crc;
    u32 mdcv_crc;
    GF_AV1State state;
} GF_AV1DmxCtx;

typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_Filter GF_Filter;

#define GF_LOG_DEBUG 0
#define GF_LOG_MEDIA 0
#define GF_FILTER_SAP_1 0
#define GF_PROP_PID_CONTENT_LIGHT_LEVEL 0

typedef struct {
    void *data;
    u32 size;
} GF_PropertyValue;

#define PROP_DATA(data, size) (GF_PropertyValue){data, size}

void GF_LOG(int level, int category, const char *fmt, ...);
void gf_bs_get_content_no_truncate(void *bs, u8 **output, u32 *size, u32 *alloc);
GF_FilterPacket *gf_filter_pck_new_alloc(void *pid, u32 size, u8 **output);
void gf_filter_pck_merge_properties(void *src, GF_FilterPacket *dst);
void gf_filter_pck_set_cts(GF_FilterPacket *pck, u32 cts);
void gf_filter_pck_set_sap(GF_FilterPacket *pck, int sap);
void gf_filter_pck_set_dependency_flags(GF_FilterPacket *pck, u8 flags);
void gf_filter_pck_set_property(GF_FilterPacket *pck, int prop, GF_PropertyValue *data);
void gf_filter_pck_send(GF_FilterPacket *pck);
u32 gf_crc_32(const u8 *data, u32 size);
void gf_av1_reset_state(GF_AV1State *state, GF_Bool flag);
void av1dmx_update_cts(GF_AV1DmxCtx *ctx);
void av1dmx_set_mdcv(GF_AV1DmxCtx *ctx, void *arg, GF_FilterPacket *pck);