#include <stdint.h>
#include <stdbool.h>

typedef struct {
    volatile uint32_t OPTR;
    volatile uint32_t SR;
    volatile uint32_t CR;
    volatile uint32_t OPTKEYR;
} FLASH_TypeDef;

#define FLASH ((FLASH_TypeDef *) 0x40022000)
#define FLASH_CR_OBL_LAUNCH (1 << 18)

extern int solo_is_locked(void);
extern void __disable_irq(void);
extern void __enable_irq(void);
extern void flash_unlock(void);
extern void flash_lock(void);