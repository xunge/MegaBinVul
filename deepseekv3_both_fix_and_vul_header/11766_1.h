#include <stdint.h>

#define INLINE inline
#define BOOL int
#define TRUE 1
#define FALSE 0
#define UINT32 uint32_t

typedef struct _ZGFX_CONTEXT {
    uint32_t BitsCurrent;
    uint32_t cBitsCurrent;
    uint32_t cBitsRemaining;
    uint32_t bits;
    const uint8_t* pbInputCurrent;
    const uint8_t* pbInputEnd;
} ZGFX_CONTEXT;