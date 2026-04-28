#include <stdint.h>

#define MPU_RBAR_ADDR_Msk 0xFFFFFFFF
#define MPU_RASR_SIZE_Msk 0xFFFFFFFF
#define MPU_RASR_SIZE_Pos 0

typedef uint32_t u32_t;

typedef struct {
    volatile uint32_t RNR;
    volatile uint32_t RBAR;
    volatile uint32_t RASR;
} MPU_Type;

#define MPU ((MPU_Type *)0xE000ED9C)

static inline unsigned int irq_lock(void);
static inline void irq_unlock(unsigned int key);