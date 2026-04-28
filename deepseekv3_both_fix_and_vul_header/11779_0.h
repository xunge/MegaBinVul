#include <string.h>

#define NTLM_SIGNATURE "NTLMSSP\0"

typedef struct _wStream wStream;

typedef struct {
    unsigned char Signature[8];
    unsigned int MessageType;
} NTLM_MESSAGE_HEADER;