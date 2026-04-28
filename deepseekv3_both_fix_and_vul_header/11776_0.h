#include <stdint.h>

typedef struct _wStream wStream;

typedef struct {
    uint32_t Len;
    uint32_t BufferOffset;
    uint8_t* Buffer;
} NTLM_MESSAGE_FIELDS;