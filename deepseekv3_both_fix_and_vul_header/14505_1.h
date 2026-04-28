#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned int u32;
typedef signed int s32;
typedef char Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef struct GF_NALUFFParam {
    u32 id;
    u32 crc;
    u32 size;
    char *data;
} GF_NALUFFParam;

typedef struct GF_List GF_List;

typedef struct GF_NALUDmxCtx {
    u32 codecid;
    GF_List *vps;
    GF_List *sps;
    GF_List *pps;
    GF_List *pps_svc;
    GF_List *sps_ext;
    GF_List *vvc_dci;
    GF_List *vvc_aps_pre;
    Bool ps_modified;
} GF_NALUDmxCtx;

#define GF_CODECID_HEVC 1
#define GF_CODECID_VVC 2
#define GF_CODECID_AVC 3

#define GF_HEVC_NALU_VID_PARAM 1
#define GF_HEVC_NALU_SEQ_PARAM 2
#define GF_HEVC_NALU_PIC_PARAM 3

#define GF_VVC_NALU_VID_PARAM 1
#define GF_VVC_NALU_SEQ_PARAM 2
#define GF_VVC_NALU_PIC_PARAM 3
#define GF_VVC_NALU_DEC_PARAM 4
#define GF_VVC_NALU_APS_PREFIX 5

#define GF_AVC_NALU_SVC_SUBSEQ_PARAM 1
#define GF_AVC_NALU_SEQ_PARAM 2
#define GF_AVC_NALU_PIC_PARAM 3
#define GF_AVC_NALU_SEQ_PARAM_EXT 4

GF_List *gf_list_new();
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void gf_list_add(GF_List *list, void *item);
void *gf_realloc(void *ptr, size_t size);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
u32 gf_crc_32(const char *data, u32 size);

#define GF_SAFEALLOC(ptr, type) ((ptr) = (type *)malloc(sizeof(type)))