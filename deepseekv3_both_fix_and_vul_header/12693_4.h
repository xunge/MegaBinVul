#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

#define USB_DIR_IN 0x80
#define USB_RET_ASYNC -1
#define EP2I(ep) ((ep) & 0x0f)
#define WARNING(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define DPRINTF(fmt, ...) printf(fmt, ##__VA_ARGS__)

struct usb_redir_bulk_packet_header {
    uint8_t endpoint;
    uint16_t length;
    uint16_t stream_id;
    uint16_t length_high;
};

typedef struct USBEndpoint {
    int max_packet_size;
    int bulk_receiving_enabled;
    void *pending_async_packet;
} USBEndpoint;

typedef struct USBRedirDevice {
    USBEndpoint endpoint[16];
    void *parser;
} USBRedirDevice;

typedef struct USBPacket {
    uint64_t id;
    uint32_t stream;
    int status;
} USBPacket;

size_t usb_packet_size(USBPacket *p);
int usbredir_already_in_flight(USBRedirDevice *dev, uint64_t id);
void usbredir_handle_buffered_bulk_in_data(USBRedirDevice *dev, USBPacket *p, uint8_t ep);
void usbredir_stop_bulk_receiving(USBRedirDevice *dev, uint8_t ep);
int usbredirparser_peer_has_cap(void *parser, int cap);
void usbredirparser_send_bulk_packet(void *parser, uint64_t id, struct usb_redir_bulk_packet_header *header, void *data, size_t len);
void usbredirparser_do_write(void *parser);
void usb_packet_copy(USBPacket *p, void *data, size_t len);
void usbredir_log_data(USBRedirDevice *dev, const char *desc, void *data, size_t len);

#define usb_redir_cap_32bits_bulk_length 0
#define g_autofree
#define g_malloc malloc