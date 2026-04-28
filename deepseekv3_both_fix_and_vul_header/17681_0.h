#include <stdint.h>
#include <stdlib.h>

typedef struct _wStream wStream;

typedef struct {
    uint8_t RespType;
    uint8_t HiRespType;
    uint16_t Reserved1;
    uint32_t Reserved2;
    uint8_t Timestamp[8];
    uint8_t ClientChallenge[8];
    uint32_t Reserved3;
    uint32_t cbAvPairs;
    void* AvPairs;
} NTLMv2_CLIENT_CHALLENGE;

typedef struct {
    uint16_t AvId;
    uint16_t AvLen;
} NTLM_AV_PAIR;