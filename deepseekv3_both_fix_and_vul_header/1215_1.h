#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define TEE_MALLOC_FILL_ZERO 0
#define TEE_USER_MEM_HINT_NO_FILL_ZERO 1
#define CFG_TEE_CORE_USER_MEM_DEBUG 0

extern void* __HeapLimit;
extern void* __HeapBase;

void EMSG(const char* fmt, ...);