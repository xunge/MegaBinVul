#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef signed int s32;

#define GF_FALSE 0
#define GF_TRUE 1

#define GF_CODECID_HEVC 1
#define GF_CODECID_VVC 2
#define GF_CODECID_AVC 3

#define GF_HEVC_NALU_VID_PARAM 32
#define GF_HEVC_NALU_SEQ_PARAM 33
#define GF_HEVC_NALU_PIC_PARAM 34

#define GF_VVC_NALU_VID_PARAM 35
#define GF_VVC_NALU_SEQ_PARAM 36
#define GF_VVC_NALU_PIC_PARAM 37
#define GF_VVC_NALU_DEC_PARAM 38
#define GF_VVC_NALU_OPI 39
#define GF_VVC_NALU_APS_PREFIX 40

#define GF_AVC_NALU_SEQ_PARAM 7
#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 15
#define GF_AVC_NALU_PIC_PARAM 8
#define GF_AVC_NALU_SEQ_PARAM_EXT 13

#define GF_SAFEALLOC(ptr, type) ptr = (type *)calloc(1, sizeof(type))

typedef struct GF_List GF_List;
typedef struct GF_NALUFFParam GF_NALUFFParam;
typedef struct GF_NALUDmxCtx GF_NALUDmxCtx;

struct GF_List {
    void **array;
    u32 count;
};

struct GF_NALUFFParam {
    char *data;
    u32 size;
    s32 id;
    u32 crc;
};

struct GF_NALUDmxCtx {
    u32 codecid;
    GF_List *vps;
    GF_List *sps;
    GF_List *pps;
    GF_List *pps_svc;
    GF_List *sps_ext;
    GF_List *vvc_dci;
    GF_List *vvc_opi;
    GF_List *vvc_aps_pre;
    u32 valid_ps_flags;
    Bool ps_modified;
    u32 opid;
    Bool first_pck_in_au;
    u32 nb_slices_in_au;
};

GF_List *gf_list_new();
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void gf_list_add(GF_List *list, void *item);
void *gf_realloc(void *ptr, size_t size);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
u32 gf_crc_32(const char *data, u32 size);
void naludmx_end_access_unit(GF_NALUDmxCtx *ctx);