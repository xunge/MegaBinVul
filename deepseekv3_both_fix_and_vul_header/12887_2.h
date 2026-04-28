#include <stdint.h>
#include <stddef.h>

#define ERROR_INVALID_PARAMETER 1
#define ERROR_INVALID_DATA 2
#define USBD_TRANSFER_DIRECTION_OUT 0
#define TAG ""

typedef unsigned int UINT;
typedef uint32_t UINT32;
typedef int BOOL;

typedef struct _URBDRC_CHANNEL_CALLBACK URBDRC_CHANNEL_CALLBACK;
typedef struct _wStream wStream;
typedef struct _IUDEVMAN IUDEVMAN;

struct _IUDEVICE {
    UINT (*bulk_or_interrupt_transfer)(struct _IUDEVICE*, URBDRC_CHANNEL_CALLBACK*, UINT32, UINT32, UINT32, UINT32, BOOL, UINT32, void*, UINT (*)(struct _IUDEVICE*, URBDRC_CHANNEL_CALLBACK*, UINT32, UINT32, UINT32, UINT32, BOOL, UINT32, void*, UINT), UINT32);
};

typedef struct _IUDEVICE IUDEVICE;

UINT urb_bulk_transfer_cb(IUDEVICE* pdev, URBDRC_CHANNEL_CALLBACK* callback, 
                         UINT32 MessageId, UINT32 RequestId, UINT32 EndpointAddress,
                         UINT32 TransferFlags, BOOL noAck, UINT32 OutputBufferSize,
                         void* buffer, UINT status);

size_t Stream_GetRemainingLength(wStream* s);
BOOL Stream_CheckAndLogRequiredLength(const char* tag, wStream* s, size_t size);
void Stream_Read_UINT32(wStream* s, UINT32* val);
void* Stream_Pointer(wStream* s);