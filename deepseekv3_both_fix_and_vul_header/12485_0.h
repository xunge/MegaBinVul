#include <stddef.h>
#include <stdint.h>

#define portBYTE_ALIGNMENT 8
#define portBYTE_ALIGNMENT_MASK (portBYTE_ALIGNMENT - 1)
typedef uintptr_t portPOINTER_SIZE_TYPE;

extern uint8_t ucHeap[];
extern size_t xNextFreeByte;
extern size_t configADJUSTED_HEAP_SIZE;

#define configUSE_MALLOC_FAILED_HOOK 0
#define configADJUSTED_HEAP_SIZE 0

void vTaskSuspendAll(void);
int xTaskResumeAll(void);
void traceMALLOC(void* pvReturn, size_t xWantedSize);