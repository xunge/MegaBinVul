#include <stdint.h>
#include <stddef.h>

#define ERROR_INVALID_PARAMETER 1
#define ERROR_INVALID_DATA 2
#define USBD_TRANSFER_DIRECTION_OUT 0
#define TAG ""

typedef unsigned int UINT;
typedef uint32_t UINT32;
typedef uint8_t BYTE;
typedef int BOOL;

struct _URBDRC_CHANNEL_CALLBACK;
typedef struct _URBDRC_CHANNEL_CALLBACK URBDRC_CHANNEL_CALLBACK;

typedef struct _IUDEVICE {
    UINT (*isoch_transfer)(struct _IUDEVICE*, URBDRC_CHANNEL_CALLBACK*, UINT32, UINT32, UINT32, UINT32, UINT32, UINT32, BOOL, BYTE*, UINT32, UINT32, BYTE*, UINT (*)(void*), UINT32);
} IUDEVICE;

typedef struct _IUDEVMAN IUDEVMAN;

typedef struct _wStream {
    BYTE* buffer;
    size_t position;
    size_t length;
    
    BYTE* (*Pointer)(struct _wStream*);
    void (*Seek)(struct _wStream*, size_t);
    size_t (*GetRemainingLength)(struct _wStream*);
    BOOL (*CheckAndLogRequiredLength)(struct _wStream*, const char*, size_t);
    void (*Read_UINT32)(struct _wStream*, UINT32*);
} wStream;

static UINT urb_isoch_transfer_cb(void* context) {
    return 0;
}