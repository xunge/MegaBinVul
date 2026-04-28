#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#define CHANNEL_RC_OK 0
#define ERROR_INVALID_DATA 1
#define WLOG_ERROR 0

typedef unsigned int UINT;
typedef uint32_t UINT32;

struct _IWTSVirtualChannelManager;
typedef struct _IWTSVirtualChannelManager IWTSVirtualChannelManager;

struct _DVCMAN_CHANNEL {
    struct _wStream* dvc_data;
    UINT32 dvc_data_length;
    struct {
        UINT (*OnDataReceived)(void*, struct _wStream*);
    } *channel_callback;
};
typedef struct _DVCMAN_CHANNEL DVCMAN_CHANNEL;

struct _wStream {
    size_t position;
    size_t capacity;
    void* buffer;
};
typedef struct _wStream wStream;

struct _drdynvcPlugin {
    void* log;
};
typedef struct _drdynvcPlugin drdynvcPlugin;

static size_t Stream_GetRemainingLength(wStream* s) { return s->capacity - s->position; }
static size_t Stream_GetPosition(wStream* s) { return s->position; }
static size_t Stream_Capacity(wStream* s) { return s->capacity; }
static void* Stream_Pointer(wStream* s) { return (char*)s->buffer + s->position; }
static void Stream_SetPosition(wStream* s, size_t position) { s->position = position; }
static void Stream_Release(wStream* s) { free(s->buffer); free(s); }
static void Stream_Write(wStream* s, const void* buf, size_t len) { memcpy((char*)s->buffer + s->position, buf, len); s->position += len; }
static void Stream_SealLength(wStream* s) { /* no-op in minimal implementation */ }
static void WLog_Print(void* log, int level, const char* format, ...) { va_list args; va_start(args, format); vprintf(format, args); va_end(args); }
static DVCMAN_CHANNEL* dvcman_find_channel_by_id(IWTSVirtualChannelManager* pChannelMgr, UINT32 ChannelId) { return NULL; }