#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct USBNetState USBNetState;
typedef struct USBPacket USBPacket;

struct rndis_packet_msg_type {
    uint32_t MessageType;
    uint32_t MessageLength;
    uint32_t DataOffset;
    uint32_t DataLength;
};

struct USBNetState {
    uint8_t out_buf[2048];
    int out_ptr;
    void *nic;
};

struct USBPacket {
    struct {
        void *iov;
        size_t niov;
        size_t size;
    } iov;
};

#define RNDIS_PACKET_MSG 1

static inline uint32_t le32_to_cpu(uint32_t v) {
    return v;
}

static inline int is_rndis(USBNetState *s) {
    return 1;
}

void usb_packet_copy(USBPacket *p, void *data, size_t len);
void qemu_send_packet(void *queue, void *buf, int size);
void *qemu_get_queue(void *nic);
void iov_hexdump(void *iov, size_t niov, FILE *fp, const char *prefix, size_t size);