#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char BYTE;
typedef uint32_t UINT32;
typedef int BOOL;

#define WLOG_ERROR 0
#define WLOG_WARN 1

typedef struct _IUDEVICE IUDEVICE;
typedef struct _URBDRC_CHANNEL_CALLBACK URBDRC_CHANNEL_CALLBACK;
typedef struct _UDEVICE UDEVICE;
typedef struct _URBDRC_PLUGIN URBDRC_PLUGIN;
typedef struct _ASYNC_TRANSFER_USER_DATA ASYNC_TRANSFER_USER_DATA;
typedef struct libusb_transfer libusb_transfer;

typedef void (*t_isoch_transfer_cb)(IUDEVICE*, URBDRC_CHANNEL_CALLBACK*, UINT32, UINT32, UINT32, const BYTE*, UINT32);

struct _UDEVICE {
    URBDRC_PLUGIN* urbdrc;
    void* libusb_handle;
    void* request_queue;
};

struct _URBDRC_PLUGIN {
    void* log;
};

struct _ASYNC_TRANSFER_USER_DATA {
    UINT32 ErrorCount;
    UINT32 StartFrame;
    void* data;
};

void WLog_Print(void* log, int level, const char* fmt, ...);
void Stream_Seek(void* stream, size_t offset);
void* Stream_Pointer(void* stream);
void func_iso_callback(libusb_transfer* transfer);

ASYNC_TRANSFER_USER_DATA* async_transfer_user_data_new(IUDEVICE*, UINT32, UINT32, UINT32, const BYTE*, size_t, BOOL, t_isoch_transfer_cb, URBDRC_CHANNEL_CALLBACK*);
void async_transfer_user_data_free(ASYNC_TRANSFER_USER_DATA*);
int ArrayList_Add(void*, libusb_transfer*);
void request_free(libusb_transfer*);
void set_stream_id_for_buffer(libusb_transfer*, uint32_t);
void libusb_fill_iso_transfer(libusb_transfer*, void*, UINT32, void*, UINT32, UINT32, void (*)(libusb_transfer*), void*, UINT32);
void libusb_set_iso_packet_lengths(libusb_transfer*, UINT32);
int libusb_submit_transfer(libusb_transfer*);
libusb_transfer* libusb_alloc_transfer(int);