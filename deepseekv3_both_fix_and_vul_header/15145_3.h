#include <stdint.h>

#define RTL_W16(reg, val) (*(volatile uint16_t *)((uintptr_t)ioaddr + (reg)) = (val))
#define RxMaxSize 0x00

#define __iomem