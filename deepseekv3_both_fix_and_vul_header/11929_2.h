#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

typedef unsigned int UINT;
typedef uint32_t UINT32;

typedef struct drdynvcPlugin {
    void* log;
    void* channel_mgr;
} drdynvcPlugin;

typedef struct wStream wStream;

size_t Stream_GetRemainingLength(wStream* s);
UINT32 drdynvc_read_variable_uint(wStream* s, int cbChId);
size_t drdynvc_cblen_to_bytes(int cbChId);
UINT dvcman_receive_channel_data(drdynvcPlugin* drdynvc, void* channel_mgr, UINT32 ChannelId, wStream* s);

#define ERROR_INVALID_DATA 1
#define WLOG_TRACE 0

void WLog_Print(void* log, int level, const char* format, ...);