#include <stdint.h>
#include <stddef.h>

#define NTLM_SIGNATURE_SIZE 8
typedef uint8_t NTLM_SIGNATURE[NTLM_SIGNATURE_SIZE];

typedef struct _NTLM_MESSAGE_HEADER {
    NTLM_SIGNATURE Signature;
    uint32_t MessageType;
} NTLM_MESSAGE_HEADER;

typedef struct _wStream {
    /* stream implementation details */
} wStream;

void Stream_Write(wStream* s, const void* data, size_t size);
void Stream_Write_UINT32(wStream* s, uint32_t value);