#include <string.h>
#include <stdint.h>

#define NTLM_SIGNATURE "NTLMSSP\0"

typedef struct _NTLM_MESSAGE_HEADER {
    char Signature[8];
    uint32_t MessageType;
} NTLM_MESSAGE_HEADER;

#define CopyMemory(dest, src, size) memcpy((dest), (src), (size))
#define UINT32 uint32_t