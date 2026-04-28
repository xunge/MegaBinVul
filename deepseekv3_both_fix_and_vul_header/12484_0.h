#include <stddef.h>
#include <stdint.h>

typedef long BaseType_t;
#define pdFALSE 0
#define pdTRUE 1

typedef struct BlockLink_t {
    struct BlockLink_t *pxNextFreeBlock;
    size_t xBlockSize;
} BlockLink_t;

extern BlockLink_t xStart, xEnd;
extern size_t xFreeBytesRemaining;
extern size_t configADJUSTED_HEAP_SIZE;
extern size_t heapSTRUCT_SIZE;
extern size_t heapMINIMUM_BLOCK_SIZE;
extern size_t portBYTE_ALIGNMENT;
extern size_t portBYTE_ALIGNMENT_MASK;
#define configUSE_MALLOC_FAILED_HOOK 1

void vTaskSuspendAll(void);
BaseType_t xTaskResumeAll(void);
void prvHeapInit(void);
void prvInsertBlockIntoFreeList(BlockLink_t *pxBlockToInsert);
void traceMALLOC(void *pvReturn, size_t xWantedSize);