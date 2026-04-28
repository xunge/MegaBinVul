#include <stdint.h>
#include <string.h>

#define BOOL int
#define TRUE 1
#define FALSE 0
typedef uint8_t BYTE;
typedef uint32_t UINT32;

void FillMemory(void* dest, size_t len, int fill);