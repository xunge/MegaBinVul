#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

struct usb_redir_interrupt_packet_header {
    uint8_t endpoint;
    uint16_t length;
};

typedef struct {
    void *parser;
} USBRedirDevice;

typedef struct {
    struct {
        size_t size;
    } iov;
    uint64_t id;
} USBPacket;

#define DPRINTF(fmt, ...)
#define g_autofree
#define g_malloc(size) malloc(size)

void usb_packet_copy(USBPacket *p, void *buf, size_t size);
void usbredir_log_data(USBRedirDevice *dev, const char *msg, void *buf, size_t size);
void usbredirparser_send_interrupt_packet(void *parser, uint64_t id, 
                                        struct usb_redir_interrupt_packet_header *packet,
                                        void *buf, size_t size);
void usbredirparser_do_write(void *parser);