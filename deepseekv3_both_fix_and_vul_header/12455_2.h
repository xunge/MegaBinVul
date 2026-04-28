#include <stddef.h>
#include <stdint.h>

typedef void * StreamBufferHandle_t;
typedef long BaseType_t;

typedef struct StreamBuffer_t {
    size_t xLength;
    size_t xTriggerLevelBytes;
    volatile size_t xTail;
    volatile size_t xHead;
    uint8_t ucFlags;
    uint8_t *pucBuffer;
} StreamBuffer_t;

#define pdTRUE 1
#define sbFLAGS_IS_MESSAGE_BUFFER 1
#define sbBYTES_TO_STORE_MESSAGE_LENGTH 0
#define configASSERT(x) ((void)0)
#define traceSTREAM_BUFFER_CREATE(x, y) ((void)0)
#define traceSTREAM_BUFFER_CREATE_FAILED(x) ((void)0)

extern void *pvPortMalloc(size_t);
extern void prvInitialiseNewStreamBuffer(StreamBuffer_t *, uint8_t *, size_t, size_t, uint8_t);