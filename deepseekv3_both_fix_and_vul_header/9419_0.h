#include <stddef.h>
#include <errno.h>

typedef struct USBDevice {
    int state;
    int attached;
    size_t setup_index;
    size_t setup_len;
    unsigned char data_buf[256]; // Assuming a reasonable buffer size
} USBDevice;

#define USB_STATE_NOTATTACHED 0
#define EINVAL 22