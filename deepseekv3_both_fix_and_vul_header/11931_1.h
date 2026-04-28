#include <stdint.h>
#include <stddef.h>

#define CHANNEL_RC_BAD_INIT_HANDLE 1
#define ERROR_INVALID_DATA 2
#define WLOG_TRACE 0

typedef unsigned int UINT;

struct _wStream;
typedef struct _wStream wStream;

typedef struct {
    UINT version;
    UINT PriorityCharge0;
    UINT PriorityCharge1;
    UINT PriorityCharge2;
    UINT PriorityCharge3;
    void* log;
    int state;
} drdynvcPlugin;

enum {
    DRDYNVC_STATE_READY
};

extern void WLog_Print(void* log, int level, const char* format, ...);
extern void Stream_Seek(wStream* s, size_t offset);
extern size_t Stream_GetRemainingLength(wStream* s);
extern void Stream_Read_UINT16(wStream* s, UINT* val);
extern UINT drdynvc_send_capability_response(drdynvcPlugin* drdynvc);