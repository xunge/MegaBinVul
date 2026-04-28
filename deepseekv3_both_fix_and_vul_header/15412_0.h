#include <stdlib.h>
#include <arpa/inet.h>

#define PACKET_TYPE_MOUSE_BUTTON 1
#define LBQ_SUCCESS 0

typedef struct NV_MOUSE_BUTTON_PACKET {
    struct {
        unsigned int packetType;
    } header;
    char action;
    unsigned int button;
} NV_MOUSE_BUTTON_PACKET;

typedef struct PACKET_HOLDER {
    size_t packetLength;
    union {
        NV_MOUSE_BUTTON_PACKET mouseButton;
    } packet;
    void* entry;
} PACKET_HOLDER, *PPACKET_HOLDER;

extern int initialized;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern struct queue packetQueue;
extern int LbqOfferQueueItem(struct queue* q, PPACKET_HOLDER holder, void** entry);