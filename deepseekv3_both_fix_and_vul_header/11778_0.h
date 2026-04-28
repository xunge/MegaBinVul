#include <stdlib.h>

typedef struct {
    unsigned char* Buffer;
    unsigned short Len;
    unsigned short MaxLen;
    unsigned long BufferOffset;
} NTLM_MESSAGE_FIELDS;