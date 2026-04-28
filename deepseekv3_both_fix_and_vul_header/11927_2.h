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

extern size_t Stream_GetRemainingLength(wStream* s);
extern UINT drdynvc_cblen_to_bytes(int cbLen);
extern UINT32 drdynvc_read_variable_uint(wStream* s, int cbLen);
extern void WLog_Print(void* log, int level, const char* format, ...);
extern UINT dvcman_receive_channel_data_first(drdynvcPlugin* drdynvc, void* channel_mgr, UINT32 ChannelId, UINT32 Length);
extern UINT dvcman_receive_channel_data(drdynvcPlugin* drdynvc, void* channel_mgr, UINT32 ChannelId, wStream* s);

#define ERROR_INVALID_DATA 1
#define WLOG_DEBUG 0