#include <stdint.h>

typedef uint32_t u32_t;

typedef struct {
    u32_t (*WORD)[2];
} SYSMPU_t;

extern SYSMPU_t *SYSMPU;