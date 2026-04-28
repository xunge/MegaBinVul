#include <stddef.h>
#include <stdint.h>

typedef struct BlockLink_t {
    struct BlockLink_t *pxNextFreeBlock;
    size_t xBlockSize;
} BlockLink_t;

extern BlockLink_t xStart;
extern BlockLink_t *pxEnd;
extern size_t xFreeBytesRemaining;
extern size_t xMinimumEverFreeBytesRemaining;
extern size_t xNumberOfSuccessfulAllocations;
extern size_t xHeapStructSize;
extern size_t xBlockAllocatedBit;
extern size_t portBYTE_ALIGNMENT;
extern size_t portBYTE_ALIGNMENT_MASK;
extern size_t heapMINIMUM_BLOCK_SIZE;

extern void vTaskSuspendAll(void);
extern int xTaskResumeAll(void);
extern void configASSERT(void *);
extern void traceMALLOC(void *, size_t);
extern void mtCOVERAGE_TEST_MARKER(void);
extern void prvInsertBlockIntoFreeList(BlockLink_t *);