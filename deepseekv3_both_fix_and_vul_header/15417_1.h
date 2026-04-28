#include <stdlib.h>
#include <arpa/inet.h>

#define MAGIC_A 0x12345678
#define PACKET_TYPE_SCROLL 0x02
#define LBQ_SUCCESS 0

typedef struct NV_SCROLL_PACKET {
    struct {
        unsigned int packetType;
    } header;
    unsigned int magicA;
    unsigned int zero1;
    unsigned int zero2;
    unsigned short scrollAmt1;
    unsigned short scrollAmt2;
    unsigned int zero3;
} NV_SCROLL_PACKET;

typedef struct PACKET_HOLDER {
    unsigned int packetLength;
    union {
        NV_SCROLL_PACKET scroll;
    } packet;
    void* entry;
} PACKET_HOLDER, *PPACKET_HOLDER;

extern int initialized;
extern int ServerMajorVersion;
extern int AppVersionQuad[4];
extern struct {
    int dummy;
} packetQueue;
int LbqOfferQueueItem(void*, PPACKET_HOLDER, void**);