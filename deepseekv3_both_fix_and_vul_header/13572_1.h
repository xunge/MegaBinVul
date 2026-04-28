#include <stddef.h>

#define ACK_COMPLETE 0
#define ACK_PENDING 1
#define ACK_BUSY_X 2
#define ACK_BUSY_A 3
#define ACK_BUSY_B 4
#define ACK_DATA_ERROR 5
#define ACK_TYPE_ERROR 6

#define RCODE_COMPLETE 0
#define RCODE_BUSY 1
#define RCODE_DATA_ERROR 2
#define RCODE_TYPE_ERROR 3

struct fw_packet {
    int timestamp;
};

struct fw_card;

struct outbound_phy_packet_event {
    struct fw_packet p;
    struct {
        int rcode;
        int length;
        int data[1];
    } phy_packet;
    void *client;
    void *event;
};

struct client;

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); \
})

static inline void client_put(struct client *c) {}
static inline void queue_event(void *client, void *event, void *packet, 
                             size_t size, void *null1, int null2) {}