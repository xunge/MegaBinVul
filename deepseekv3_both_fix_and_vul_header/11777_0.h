#include <inttypes.h>
#include <stdio.h>

typedef struct
{
	uint16_t Len;
	uint16_t MaxLen;
	uint32_t BufferOffset;
	uint8_t* Buffer;
} NTLM_MESSAGE_FIELDS;

#define TAG "NTLM"
#define WLOG_DEBUG 0

void WLog_DBG(const char* tag, const char* format, ...);
void winpr_HexDump(const char* tag, int level, const void* data, size_t length);