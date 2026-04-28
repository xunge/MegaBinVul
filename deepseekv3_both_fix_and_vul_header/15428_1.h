#include <stdlib.h>

extern int AppVersionQuad[0];
extern int ServerMajorVersion;
extern void* client;
extern void* enetMutex;

typedef struct NVCTL_TCP_PACKET_HEADER {
    // Define structure members as needed
} NVCTL_TCP_PACKET_HEADER, *PNVCTL_TCP_PACKET_HEADER;

typedef struct ENetEvent {
    int type;
    void* packet;
} ENetEvent;

#define ENET_EVENT_TYPE_RECEIVE 0
#define CONTROL_STREAM_TIMEOUT_SEC 0

void PltLockMutex(void* mutex);
void PltUnlockMutex(void* mutex);
int sendMessageEnet(short ptype, short paylen, const void* payload);
int sendMessageTcp(short ptype, short paylen, const void* payload);
PNVCTL_TCP_PACKET_HEADER readNvctlPacketTcp();
int serviceEnetHost(void* host, ENetEvent* event, unsigned int timeout);
void enet_packet_destroy(void* packet);