#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define ERROR_INVALID_DATA 1
#define CHANNEL_RC_NO_MEMORY 2
#define CLOSE_REQUEST_PDU 0x00
#define WLOG_DEBUG 0
#define WLOG_ERROR 1

typedef unsigned int UINT;
typedef uint32_t UINT32;

struct wStream;
typedef struct wStream wStream;

struct drdynvcPlugin {
    void* log;
    void* channel_mgr;
};
typedef struct drdynvcPlugin drdynvcPlugin;

size_t Stream_GetRemainingLength(struct wStream* s);
struct wStream* Stream_New(void* ptr, size_t size);
void Stream_Write_UINT8(struct wStream* s, uint8_t value);

UINT drdynvc_cblen_to_bytes(int cbChId);
UINT32 drdynvc_read_variable_uint(struct wStream* s, int cbChId);
void drdynvc_write_variable_uint(struct wStream* s, UINT32 ChannelId);
UINT drdynvc_send(struct drdynvcPlugin* drdynvc, struct wStream* data_out);
UINT dvcman_close_channel(void* channel_mgr, UINT32 ChannelId);

void WLog_Print(void* log, int level, const char* format, ...);
const char* WTSErrorToString(UINT error);