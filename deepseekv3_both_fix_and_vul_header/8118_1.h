#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX_NUM_REF_PICS 16
#define MAX_NUM_REF_IDX_L0_ACTIVE 16
#define NO_LONG_TERM_FRAME_INDICES -1
#define MEMORY_ALLOCATION_ERROR 1
#define HANTRO_OK 0

typedef uint32_t u32;
typedef uint8_t u8;

typedef struct {
    u8* pAllocatedData;
    u8* data;
} dpbPicture_t;

typedef struct {
    u8* data;
} dpbOutPicture_t;

typedef struct {
    dpbPicture_t** list;
    dpbPicture_t* buffer;
    dpbOutPicture_t* outBuf;
    u32 maxLongTermFrameIdx;
    u32 maxRefFrames;
    u32 dpbSize;
    u32 maxFrameNum;
    u32 noReordering;
    u32 fullness;
    u32 numRefFrames;
    u32 prevRefFrameNum;
    u32 numOut;
    u32 outIndex;
} dpbStorage_t;

#define ASSERT(cond) ((void)0)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ALLOCATE(ptr, num, type) ((ptr) = (type*)malloc((num) * sizeof(type)))
#define ALIGN(ptr, align) ((u8*)(((uintptr_t)(ptr) + (align) - 1) & ~((align) - 1)))
#define H264SwDecMemset memset