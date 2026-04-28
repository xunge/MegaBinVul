#include <stdint.h>
#include <stddef.h>

typedef void * QueueHandle_t;
typedef unsigned long UBaseType_t;

typedef struct QueueDefinition
{
    uint8_t ucStaticallyAllocated;
} Queue_t;

#define pdFALSE 0
#define configSUPPORT_STATIC_ALLOCATION 1
#define configASSERT(x) 
#define traceQUEUE_CREATE_FAILED(x) 
#define mtCOVERAGE_TEST_MARKER() 

extern void * pvPortMalloc( size_t xSize );
extern void prvInitialiseNewQueue( const UBaseType_t uxQueueLength,
                                  const UBaseType_t uxItemSize,
                                  uint8_t * pucQueueStorage,
                                  const uint8_t ucQueueType,
                                  Queue_t * pxNewQueue );