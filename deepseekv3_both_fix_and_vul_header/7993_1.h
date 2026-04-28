#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define ASSERT(expr) ((void)0)
#define DEBUG(x) ((void)0)
#define FREE(ptr) free(ptr)
#define ALLOCATE(ptr, num, type) ptr = (type*)malloc((num) * sizeof(type))
#define H264SwDecMemset(dest, val, size) memset(dest, val, size)

#define MAX_NUM_PIC_PARAM_SETS 256
#define HANTRO_OK 0
#define HANTRO_NOK 1
#define HANTRO_TRUE 1
#define HANTRO_FALSE 0
#define MEMORY_ALLOCATION_ERROR 2

typedef uint32_t u32;

typedef struct {
    u32 seqParameterSetId;
    u32 picWidthInMbs;
    u32 picHeightInMbs;
    u32 picOrderCntType;
    u32 vuiParametersPresentFlag;
    u32 maxDpbSize;
    u32 numRefFrames;
    u32 maxFrameNum;
    struct {
        u32 bitstreamRestrictionFlag;
        u32 numReorderFrames;
    } *vuiParameters;
} sps_t;

typedef struct {
    u32 seqParameterSetId;
} pps_t;

typedef struct {
    u32 width;
    u32 height;
} image_t;

typedef struct {
    void* data;
} mbStorage_t;

typedef struct {
    void* data;
} dpb_t;

typedef struct {
    pps_t* pps[MAX_NUM_PIC_PARAM_SETS];
    sps_t* sps[MAX_NUM_PIC_PARAM_SETS];
    u32 activePpsId;
    pps_t* activePps;
    u32 activeSpsId;
    sps_t* activeSps;
    u32 picSizeInMbs;
    image_t* currImage;
    u32 pendingActivation;
    mbStorage_t* mb;
    u32* sliceGroupMap;
    u32 noReordering;
    dpb_t* dpb;
} storage_t;

u32 CheckPps(pps_t* pps, sps_t* sps);
u32 h264bsdInitMbNeighbours(mbStorage_t* mb, u32 width, u32 size);
u32 h264bsdResetDpb(dpb_t* dpb, u32 size, u32 maxDpbSize, u32 numRefFrames, u32 maxFrameNum, u32 flag);