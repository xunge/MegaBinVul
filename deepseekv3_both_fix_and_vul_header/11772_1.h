#include <stdint.h>
#include <stdlib.h>

typedef unsigned char BYTE;
typedef BYTE* PBYTE;

typedef struct _NTLM_MESSAGE_FIELDS {
    uint32_t Len;
    uint32_t BufferOffset;
    PBYTE Buffer;
} NTLM_MESSAGE_FIELDS;

typedef struct _wStream {
    size_t length;
    size_t position;
    BYTE* buffer;
} wStream;

typedef uint64_t UINT64;

size_t Stream_Length(wStream* s);
void Stream_SetPosition(wStream* s, size_t position);
void Stream_Read(wStream* s, void* buffer, size_t size);