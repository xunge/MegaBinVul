#include <stdint.h>
#include <stdio.h>

#define ERROR_INVALID_DATA 1
#define ERROR_INTERNAL_ERROR 2

#define CAPABILITY_REQUEST_PDU 0
#define CREATE_REQUEST_PDU 1
#define DATA_FIRST_PDU 2
#define DATA_PDU 3
#define CLOSE_REQUEST_PDU 4

#define WLOG_DEBUG 0
#define WLOG_ERROR 1

typedef unsigned int UINT;

typedef struct wStream wStream;

typedef struct drdynvcPlugin {
    void* log;
} drdynvcPlugin;

int Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT8(wStream* s, int* value);
void WLog_Print(void* log, int level, const char* format, ...);

UINT drdynvc_process_capability_request(drdynvcPlugin* drdynvc, int Sp, int cbChId, wStream* s);
UINT drdynvc_process_create_request(drdynvcPlugin* drdynvc, int Sp, int cbChId, wStream* s);
UINT drdynvc_process_data_first(drdynvcPlugin* drdynvc, int Sp, int cbChId, wStream* s);
UINT drdynvc_process_data(drdynvcPlugin* drdynvc, int Sp, int cbChId, wStream* s);
UINT drdynvc_process_close_request(drdynvcPlugin* drdynvc, int Sp, int cbChId, wStream* s);