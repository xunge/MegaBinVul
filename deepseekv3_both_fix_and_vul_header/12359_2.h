#include <stddef.h>
#include <stdint.h>

#define RXE_MEM_TYPE_DMA 0
#define RXE_MEM_TYPE_MR 1
#define RXE_MEM_TYPE_FMR 2
#define EFAULT 14

typedef uint64_t u64;

struct rxe_mem {
    int type;
    u64 iova;
    size_t length;
};