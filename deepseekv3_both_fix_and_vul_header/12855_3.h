#include <stdint.h>
#include <string.h>

#define MAX_INC_LZ_MATCH 260
#define MAX_LZ_MATCH 260
#define FAST_MEMCPY
#define _forceinline inline __attribute__((always_inline))

typedef uint8_t byte;
typedef unsigned int uint;

class Unpack {
public:
    byte *Window;
    size_t UnpPtr;
    size_t MaxWinSize;
    size_t MaxWinMask;
    
    _forceinline void CopyString(uint Length, uint Distance);
};