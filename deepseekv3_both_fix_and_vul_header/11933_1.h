#include <stdint.h>
#include <stddef.h>

typedef unsigned int UINT;
typedef uint32_t UINT32;
typedef int BOOL;

#define TRUE 1
#define FALSE 0
#define NULL ((void*)0)

#define CHANNEL_FLAG_SUSPEND 0x01
#define CHANNEL_FLAG_RESUME 0x02
#define CHANNEL_FLAG_FIRST 0x04
#define CHANNEL_FLAG_LAST 0x08

#define CHANNEL_RC_OK 0
#define CHANNEL_RC_NO_MEMORY 1
#define ERROR_INTERNAL_ERROR 2
#define ERROR_INVALID_DATA 3

typedef struct wStream wStream;
typedef struct drdynvcPlugin drdynvcPlugin;
typedef struct WLog WLog;

enum {
    WLOG_ERROR
};

struct drdynvcPlugin {
    wStream* data_in;
    WLog* log;
    void* queue;
};

void WLog_Print(WLog* log, int level, const char* message);
wStream* Stream_New(void* buffer, size_t size);
void Stream_Free(wStream* stream, BOOL bFree);
BOOL Stream_EnsureRemainingCapacity(wStream* stream, int size);
void Stream_Write(wStream* stream, void* data, size_t size);
size_t Stream_Capacity(wStream* stream);
size_t Stream_GetPosition(wStream* stream);
void Stream_SealLength(wStream* stream);
void Stream_SetPosition(wStream* stream, size_t position);
BOOL MessageQueue_Post(void* queue, void* message, UINT32 flags, void* param, void* user);