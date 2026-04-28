#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef void* H264SwDecInst;

typedef enum {
    H264SWDEC_OK,
    H264SWDEC_INITFAIL,
    H264SWDEC_PARAM_ERR,
    H264SWDEC_MEMFAIL
} H264SwDecRet;

typedef enum {
    HANTRO_OK,
    INITIALIZED
} Status;

typedef struct {
    Status decStat;
    u32 picNumber;
    void* storage;
    char str[256];
} decContainer_t;

#define DEC_API_TRC(msg)