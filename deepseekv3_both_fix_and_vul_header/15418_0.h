#include <stdlib.h>
#include <arpa/inet.h>

typedef struct NV_CONTROLLER_HEADER {
    unsigned int packetType;
} NV_CONTROLLER_HEADER;

typedef struct NV_CONTROLLER_PACKET {
    NV_CONTROLLER_HEADER header;
    unsigned char headerA;
    unsigned char headerB;
    short buttonFlags;
    unsigned char leftTrigger;
    unsigned char rightTrigger;
    short leftStickX;
    short leftStickY;
    short rightStickX;
    short rightStickY;
    unsigned char tailA;
    unsigned char tailB;
} NV_CONTROLLER_PACKET;

typedef struct NV_MULTI_CONTROLLER_PACKET {
    NV_CONTROLLER_HEADER header;
    unsigned char headerA;
    unsigned char headerB;
    short controllerNumber;
    unsigned char midA;
    unsigned char midB;
    short buttonFlags;
    unsigned char leftTrigger;
    unsigned char rightTrigger;
    short leftStickX;
    short leftStickY;
    short rightStickX;
    short rightStickY;
    unsigned char tailA;
    unsigned char tailB;
} NV_MULTI_CONTROLLER_PACKET;

typedef struct PACKET_HOLDER {
    int packetLength;
    union {
        NV_CONTROLLER_PACKET controller;
        NV_MULTI_CONTROLLER_PACKET multiController;
    } packet;
    void* entry;
} PACKET_HOLDER, *PPACKET_HOLDER;

#define PACKET_TYPE_CONTROLLER 0x1000
#define PACKET_TYPE_MULTI_CONTROLLER 0x1001
#define C_HEADER_A 0x0A
#define C_HEADER_B 0x0B
#define C_TAIL_A 0x0A
#define C_TAIL_B 0x0B
#define MC_HEADER_A 0x0C
#define MC_HEADER_B 0x0D
#define MC_ACTIVE_CONTROLLER_FLAGS 0x0E
#define MC_MID_B 0x0F
#define MC_TAIL_A 0x0C
#define MC_TAIL_B 0x0D
#define LBQ_SUCCESS 0

extern int initialized;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern struct LbqQueue packetQueue;
extern int LbqOfferQueueItem(struct LbqQueue* queue, void* item, void** entry);