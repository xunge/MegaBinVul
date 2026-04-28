#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define EIO 5

extern int psr_put(uint16_t pskey, uint8_t *array, uint16_t length);