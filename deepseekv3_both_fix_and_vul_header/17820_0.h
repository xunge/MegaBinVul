#include <stddef.h>
#include <stdint.h>

#define INLINE inline
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef uint16_t UINT16;
typedef size_t SIZE_T;

typedef struct _NTLM_AV_PAIR
{
    UINT16 AvId;
    UINT16 AvLen;
} NTLM_AV_PAIR;

static INLINE void Data_Read_UINT16(const void* p, UINT16* val)
{
    const uint8_t* ptr = (const uint8_t*)p;
    *val = (ptr[0] << 8) | ptr[1];
}