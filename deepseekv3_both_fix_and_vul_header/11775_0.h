#include <stdint.h>

typedef struct _wStream wStream;

typedef struct {
	uint16_t Len;
	uint16_t MaxLen;
	uint32_t BufferOffset;
} NTLM_MESSAGE_FIELDS;