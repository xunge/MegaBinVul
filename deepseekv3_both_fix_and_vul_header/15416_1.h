#include <stdlib.h>
#include <arpa/inet.h>

#define PACKET_TYPE_MOUSE_MOVE 1
#define MOUSE_MOVE_MAGIC 0x1A2B3C4D
#define LBQ_SUCCESS 0

typedef struct NV_MOUSE_MOVE_PACKET {
    struct {
        int packetType;
    } header;
    int magic;
    short deltaX;
    short deltaY;
} NV_MOUSE_MOVE_PACKET;

typedef struct PACKET_HOLDER {
    size_t packetLength;
    union {
        NV_MOUSE_MOVE_PACKET mouseMove;
    } packet;
    void* entry;
} PACKET_HOLDER, *PPACKET_HOLDER;

extern int initialized;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern PACKET_HOLDER packetQueue;

int LbqOfferQueueItem(PACKET_HOLDER* queue, PPACKET_HOLDER holder, void** entry);