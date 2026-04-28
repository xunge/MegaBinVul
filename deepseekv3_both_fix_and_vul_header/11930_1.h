#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#define CHANNEL_RC_BAD_CHANNEL_HANDLE 0
#define CHANNEL_RC_NO_MEMORY 0
#define CHANNEL_RC_OK 0
#define ERROR_INVALID_DATA 0
#define DRDYNVC_STATE_CAPABILITIES 0
#define DRDYNVC_STATE_READY 0
#define WLOG_ERROR 0
#define WLOG_DEBUG 0

typedef unsigned int UINT;
typedef uint32_t UINT32;

struct drdynvcPlugin {
    int state;
    unsigned int version;
    void* log;
    void* channel_mgr;
};

typedef struct drdynvcPlugin drdynvcPlugin;
typedef struct wStream wStream;

UINT drdynvc_send_capability_response(drdynvcPlugin* drdynvc);
UINT drdynvc_send(drdynvcPlugin* drdynvc, wStream* data_out);
UINT32 drdynvc_read_variable_uint(wStream* s, int cbChId);
UINT dvcman_create_channel(drdynvcPlugin* drdynvc, void* channel_mgr, UINT32 ChannelId, char* name);
UINT dvcman_open_channel(drdynvcPlugin* drdynvc, void* channel_mgr, UINT32 ChannelId);
UINT dvcman_close_channel(void* channel_mgr, UINT32 ChannelId);
size_t drdynvc_cblen_to_bytes(int cbChId);

void WLog_Print(void* log, int level, const char* format, ...);
size_t Stream_GetRemainingLength(wStream* s);
size_t Stream_GetPosition(wStream* s);
char* Stream_Pointer(wStream* s);
void Stream_SetPosition(wStream* s, size_t position);
void Stream_Write_UINT8(wStream* s, uint8_t value);
void Stream_Write_UINT32(wStream* s, uint32_t value);
void Stream_Copy(wStream* src, wStream* dst, size_t length);
wStream* Stream_New(void* buffer, size_t size);
const char* WTSErrorToString(UINT error);