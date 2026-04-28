#include <stddef.h>
#include <stdint.h>

#define BOOL int
#define FALSE 0
#define TRUE 1

typedef struct _NSC_CONTEXT {
    uint32_t PlaneByteCount[4];
    uint8_t ColorLossLevel;
    uint8_t ChromaSubsamplingLevel;
    uint8_t* Planes;
    size_t PlanesSize;
    struct {
        void* log;
    }* priv;
} NSC_CONTEXT;

typedef struct _wStream {
    uint8_t* buffer;
    size_t position;
    size_t length;
} wStream;

#define WINPR_ASSERT(expr) ((void)0)

static BOOL Stream_CheckAndLogRequiredLengthWLog(void* log, wStream* s, size_t required);
static void Stream_Read_UINT32(wStream* s, uint32_t value);
static void Stream_Read_UINT8(wStream* s, uint8_t value);
static void Stream_Seek(wStream* s, size_t offset);
static uint8_t* Stream_Pointer(wStream* s);