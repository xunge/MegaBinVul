#include <stdint.h>

#define GF_EXPORT

typedef uint8_t u8;
typedef int32_t s32;

typedef struct {
    uint8_t current;
    uint32_t nbBits;
} GF_BitStream;

extern uint8_t BS_ReadByte(GF_BitStream *bs);
extern uint8_t bit_mask[];