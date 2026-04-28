#include <stdint.h>
#include <stddef.h>

typedef struct
{
    uint8_t* data;
    size_t size;
} wStream;

typedef struct
{
    uint8_t Response[16];
    void* Challenge;
} NTLMv2_RESPONSE;

void Stream_Read(wStream* s, void* data, size_t size);
int ntlm_read_ntlm_v2_client_challenge(wStream* s, void** challenge);