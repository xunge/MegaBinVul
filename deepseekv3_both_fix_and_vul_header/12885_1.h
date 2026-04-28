#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define STREAM_ID_PROXY 0x1
#define USBD_STATUS_SUCCESS 0
#define ERROR_INVALID_PARAMETER 1
#define ERROR_INVALID_DATA 2
#define ERROR_OUTOFMEMORY 3
#define ERROR_INVALID_OPERATION 4
#define TRUE 1

#define IOCTL_INTERNAL_USB_SUBMIT_URB 0x00220003
#define IOCTL_INTERNAL_USB_RESET_PORT 0x00220007
#define IOCTL_INTERNAL_USB_GET_PORT_STATUS 0x00220013
#define IOCTL_INTERNAL_USB_CYCLE_PORT 0x0022001F
#define IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION 0x00220027

typedef unsigned int UINT;
typedef uint32_t UINT32;

typedef struct _wStream {
    size_t length;
    size_t capacity;
    size_t position;
    uint8_t* buffer;
} wStream;

typedef struct _IUDEVICE {
    UINT32 (*get_ReqCompletion)(struct _IUDEVICE* pdev);
    int (*query_device_port_status)(struct _IUDEVICE* pdev, UINT32* usbd_status, UINT32* OutputBufferSize, uint8_t* out);
    int (*isExist)(struct _IUDEVICE* pdev);
} IUDEVICE;

typedef struct _IUDEVMAN {
    // Placeholder for IUDEVMAN methods
} IUDEVMAN;

typedef struct _URBDRC_PLUGIN {
    void* log;
} URBDRC_PLUGIN;

typedef struct _URBDRC_CHANNEL_CALLBACK {
    URBDRC_PLUGIN* plugin;
    void* channel;
} URBDRC_CHANNEL_CALLBACK;

typedef enum {
    WLOG_DEBUG,
    WLOG_ERROR
} WLogLevel;

size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT32(wStream* s, UINT32* val);
int Stream_SafeSeek(wStream* s, size_t offset);
uint8_t* Stream_Pointer(wStream* s);
void Stream_Free(wStream* s, int free_buffer);
void Stream_Write_UINT32(wStream* s, UINT32 val);
void WLog_Print(void* log, WLogLevel level, const char* fmt, ...);

wStream* urb_create_iocompletion(UINT32 InterfaceId, UINT32 MessageId, UINT32 RequestId, UINT32 OutputBufferSize);
UINT stream_write_and_free(void* plugin, void* channel, wStream* out);
void usb_process_get_port_status(IUDEVICE* pdev, wStream* out);