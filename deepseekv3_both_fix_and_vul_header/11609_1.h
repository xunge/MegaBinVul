#include <stdint.h>
#include <cstring>
#include <cstddef>

#define SMP_TRACE_DEBUG(fmt, ...)
#define BT_OCTET16_LEN 16
#define SMP_INVALID_PARAMETERS 0
#define SMP_AUTH_CMPL_EVT 0
#define STREAM_TO_ARRAY(dst, src, len) memcpy(dst, src, len)

typedef struct {
    uint8_t* p_data;
    int status;
} tSMP_INT_DATA;

typedef struct {
    uint8_t tk[BT_OCTET16_LEN];
} tSMP_CB;

bool smp_command_has_invalid_parameters(tSMP_CB* p_cb);
void smp_sm_event(tSMP_CB* p_cb, int event, tSMP_INT_DATA* p_data);
void smp_key_distribution_by_transport(tSMP_CB* p_cb, void* null);
void android_errorWriteLog(uint32_t tag, const char* msg);