#include <stdint.h>
#include <stddef.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define CONTROL_STREAM_TIMEOUT_SEC 5
#define ENET_PEER_TIMEOUT_LIMIT 32
#define ENET_PEER_TIMEOUT_MINIMUM 5000
#define ENET_EVENT_TYPE_CONNECT 1
#define IDX_START_A 0
#define IDX_START_B 1
#define INVALID_SOCKET (-1)

typedef struct ENetMutex {
    int dummy;
} ENetMutex;

typedef struct ENetAddress {
    struct sockaddr_storage address;
} ENetAddress;

typedef struct ENetEvent {
    int type;
} ENetEvent;

typedef struct ENetHost {
    int dummy;
} ENetHost;

typedef struct ENetPeer {
    int dummy;
} ENetPeer;

typedef struct PltThread {
    int dummy;
} PltThread;

extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern ENetMutex enetMutex;
extern ENetHost* client;
extern ENetPeer* peer;
extern int ctlSock;
extern struct sockaddr_storage RemoteAddr;
extern socklen_t RemoteAddrLen;
extern uint32_t packetTypes[2];
extern uint32_t payloadLengths[2];
extern void* preconstructedPayloads[2];
extern PltThread lossStatsThread;
extern PltThread invalidateRefFramesThread;

int PltCreateMutex(ENetMutex* mutex);
int PltCreateThread(void (*func)(void*), void* arg, PltThread* thread);
int connectTcpSocket(struct sockaddr_storage* addr, socklen_t addrLen, int port, int timeout);
int enableNoDelay(int sock);
int sendMessageAndDiscardReply(uint32_t packetType, uint32_t payloadLength, void* payload);
int LastSocketFail();
int LastSocketError();
void Limelog(const char* format, ...);
void lossStatsThreadFunc(void* arg);
void invalidateRefFramesFunc(void* arg);
void enet_address_set_address(ENetAddress* address, struct sockaddr* addr, socklen_t addrLen);
void enet_address_set_port(ENetAddress* address, uint16_t port);
ENetHost* enet_host_create(int family, const ENetAddress* address, size_t peerCount, size_t channelLimit, uint32_t incomingBandwidth, uint32_t outgoingBandwidth);
ENetPeer* enet_host_connect(ENetHost* host, const ENetAddress* address, size_t channelCount, uint32_t data);
void enet_host_destroy(ENetHost* host);
int serviceEnetHost(ENetHost* host, ENetEvent* event, uint32_t timeout);
void enet_peer_reset(ENetPeer* peer);
void enet_host_flush(ENetHost* host);
void enet_peer_timeout(ENetPeer* peer, uint32_t timeoutLimit, uint32_t timeoutMinimum, uint32_t timeoutMax);