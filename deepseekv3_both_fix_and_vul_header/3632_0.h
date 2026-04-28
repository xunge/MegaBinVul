#include <stdint.h>

#define READ_CP64(reg) (0)
#define WRITE_CP32(val, reg) 
#define WRITE_CP64(val, reg) 
#define isb() 

#define GV2M_WRITE (1 << 0)
#define ATS12NSOPW 0
#define ATS12NSOPR 0

typedef uint64_t vaddr_t;