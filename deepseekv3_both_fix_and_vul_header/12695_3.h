#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>

#define KiB 1024
#define MiB (1024 * KiB)

typedef struct USBPacket USBPacket;
typedef struct USBCombinedPacket USBCombinedPacket;

struct USBPacket {
    int status;
    int state;
    int short_not_ok;
    int int_req;
    struct {
        struct iovec *iov;
        unsigned int size;
    } iov;
    USBCombinedPacket *combined;
    struct {
        USBPacket *tqe_next;
        USBPacket **tqe_prev;
    } queue;
    struct {
        USBPacket *tqe_next;
        USBPacket **tqe_prev;
    } combined_entry;
};

struct USBCombinedPacket {
    USBPacket *first;
    struct {
        USBPacket *tqh_first;
        USBPacket **tqh_last;
    } packets;
    struct {
        struct iovec *iov;
        unsigned int size;
    } iov;
};

typedef struct USBPortOps {
    void (*complete)(void *port, USBPacket *p);
} USBPortOps;

typedef struct USBPort {
    USBPortOps *ops;
} USBPort;

typedef struct USBDevice {
    USBPort *port;
} USBDevice;

typedef struct USBEndpoint {
    int pipeline;
    int pid;
    int halted;
    int max_packet_size;
    USBDevice *dev;
    struct {
        USBPacket *tqh_first;
        USBPacket **tqh_last;
    } queue;
} USBEndpoint;

enum {
    USB_TOKEN_IN,
    USB_RET_REMOVE_FROM_QUEUE,
    USB_RET_ASYNC,
    USB_PACKET_ASYNC,
    USB_PACKET_QUEUED
};

#define QTAILQ_FOREACH_SAFE(var, head, field, next_var) \
    for ((var) = (head)->tqh_first; (var) && ((next_var) = (var)->field.tqe_next, 1); (var) = (next_var))

#define QTAILQ_FOREACH(var, head, field) \
    for ((var) = (head)->tqh_first; (var); (var) = (var)->field.tqe_next)

#define QTAILQ_INIT(head) do { \
    (head)->tqh_first = NULL; \
    (head)->tqh_last = &(head)->tqh_first; \
} while (0)

#define g_new0(type, n) ((type *)calloc(n, sizeof(type)))

static inline void qemu_iovec_init(struct { struct iovec *iov; unsigned int size; } *iov, int n) {
    iov->iov = calloc(n, sizeof(struct iovec));
    iov->size = 0;
}

void usb_packet_check_state(USBPacket *p, int state);
void usb_combined_packet_add(USBCombinedPacket *combined, USBPacket *p);
void usb_packet_set_state(USBPacket *p, int state);
void usb_device_handle_data(USBDevice *dev, USBPacket *p);