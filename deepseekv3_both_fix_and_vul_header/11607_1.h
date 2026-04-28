#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct tSMP_CB {
    uint8_t rcvd_cmd_len;
    uint8_t status;
    uint8_t peer_keypress_notification;
    uint8_t cb_evt;
} tSMP_CB;

typedef struct tSMP_INT_DATA tSMP_INT_DATA;

#define SMP_INVALID_PARAMETERS 0
#define SMP_AUTH_CMPL_EVT 0
#define SMP_PEER_KEYPR_NOT_EVT 0
#define BTM_SP_KEY_OUT_OF_RANGE 0

#define SMP_TRACE_DEBUG(...)

bool smp_command_has_invalid_parameters(tSMP_CB* p_cb);
void smp_sm_event(tSMP_CB* p_cb, int event, uint8_t* reason);
void android_errorWriteLog(uint32_t tag, const char* msg);

#define STREAM_TO_UINT8(ptr, stream) { \
    (ptr) = *(uint8_t*)(stream); \
    (stream) += sizeof(uint8_t); \
}