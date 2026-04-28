#include <stdint.h>
#include <stdlib.h>
#include <sys/queue.h>

#define USB_DIR_IN 0x80
#define USB_SPEED_HIGH 2
#define USB_RET_SUCCESS 0
#define USB_RET_IOERROR -1
#define usb_redir_babble 0
#define EP2I(ep) ((ep) & 0x0f)
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define DPRINTF(fmt, ...) 
#define DPRINTF2(fmt, ...) 
#define ERROR(fmt, ...) 

struct usb_redir_start_iso_stream_header {
    uint8_t endpoint;
    uint8_t pkts_per_urb;
    uint8_t no_urbs;
};

struct usb_redir_iso_packet_header {
    uint8_t endpoint;
    uint32_t length;
};

struct buf_packet {
    int status;
    int len;
    uint8_t *data;
    TAILQ_ENTRY(buf_packet) next;
};

TAILQ_HEAD(buf_packet_head, buf_packet);

struct USBEndpoint {
    int iso_started;
    int iso_error;
    int interval;
    int bufpq_target_size;
    int bufpq_prefilled;
    int bufpq_dropping_packets;
    int bufpq_size;
    struct buf_packet_head bufpq;
};

struct USBDevice {
    int speed;
};

struct IOV {
    size_t size;
};

typedef struct USBPacket {
    struct IOV iov;
    int status;
    void (*copy)(struct USBPacket *, void *, size_t);
} USBPacket;

typedef struct USBRedirDevice {
    struct USBDevice dev;
    struct USBEndpoint endpoint[32];
    void *parser;
} USBRedirDevice;

#define QTAILQ_FIRST(head) TAILQ_FIRST(head)
#define g_autofree
#define g_malloc malloc

void usbredirparser_send_start_iso_stream(void *parser, int id, struct usb_redir_start_iso_stream_header *hdr);
void usbredirparser_do_write(void *parser);
void usbredirparser_send_iso_packet(void *parser, int id, struct usb_redir_iso_packet_header *hdr, uint8_t *data, int len);
void usbredir_handle_status(USBRedirDevice *dev, USBPacket *p, int status);
void usb_packet_copy(USBPacket *p, void *data, size_t len);
void bufp_free(USBRedirDevice *dev, struct buf_packet *isop, uint8_t ep);