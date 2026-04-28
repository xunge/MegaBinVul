#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_OK,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef enum {
    GF_FALSE = 0,
    GF_TRUE = 1
} GF_Bool;

typedef struct {
    u8 key_frame;
    u8 refresh_frame_flags;
} GF_AV1FrameState;

typedef struct {
    void *bs;
    u8 *frame_obus;
    u32 frame_obus_alloc;
    GF_AV1FrameState frame_state;
} GF_AV1State;

typedef struct {
    void *opid;
    void *src_pck;
    u32 cts;
    u8 deps;
    GF_AV1State state;
} GF_AV1DmxCtx;

typedef struct {
    int dummy;
} GF_Filter;

typedef struct {
    int dummy;
} GF_FilterPacket;

#define GF_LOG_DEBUG 0
#define GF_LOG_CONTAINER 0
#define GF_FILTER_SAP_1 0

void gf_bs_get_content_no_truncate(void *bs, u8 **output, u32 *size, u32 *alloc);
GF_FilterPacket *gf_filter_pck_new_alloc(void *opid, u32 size, u8 **output);
void gf_filter_pck_merge_properties(void *src_pck, GF_FilterPacket *pck);
void gf_filter_pck_set_cts(GF_FilterPacket *pck, u32 cts);
void gf_filter_pck_set_sap(GF_FilterPacket *pck, int sap);
void gf_filter_pck_set_dependency_flags(GF_FilterPacket *pck, u8 flags);
void gf_filter_pck_send(GF_FilterPacket *pck);
void av1dmx_update_cts(GF_AV1DmxCtx *ctx);
void gf_av1_reset_state(GF_AV1State *state, GF_Bool flag);
void GF_LOG(int level, int category, const char *fmt, ...);