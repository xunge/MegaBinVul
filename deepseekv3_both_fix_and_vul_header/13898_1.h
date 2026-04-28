#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t IP;
    size_t codeSize;
    int error;
    int step_ins;
    uint8_t *code;
} TT_ExecContext;

#define TT_Err_Invalid_Reference 1
#define FALSE 0
#define BOUNDS(addr, size) ((addr) < 0 || (addr) >= (size))

extern TT_ExecContext CUR;
typedef int32_t Int;

#define INS_ARG Int args[]