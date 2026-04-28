#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <arpa/inet.h>

#define MAX_INPUT_PACKET_SIZE 1024
#define PACKET_TYPE_MULTI_CONTROLLER 1
#define PACKET_TYPE_MOUSE_MOVE 2
#define LBQ_SUCCESS 0
#define SOCK_RET int

typedef struct {
    uint32_t packetType;
} PACKET_HEADER;

typedef struct {
    PACKET_HEADER header;
    uint32_t buttonFlags;
    uint8_t controllerNumber;
    uint8_t leftTrigger;
    uint8_t rightTrigger;
    int16_t leftStickX;
    int16_t leftStickY;
    int16_t rightStickX;
    int16_t rightStickY;
} NV_MULTI_CONTROLLER_PACKET, *PNV_MULTI_CONTROLLER_PACKET;

typedef struct {
    PACKET_HEADER header;
    uint16_t deltaX;
    uint16_t deltaY;
} MOUSE_MOVE_PACKET;

typedef union {
    PACKET_HEADER header;
    NV_MULTI_CONTROLLER_PACKET multiController;
    MOUSE_MOVE_PACKET mouseMove;
} PACKET;

typedef struct {
    PACKET packet;
    int packetLength;
} PACKET_HOLDER, *PPACKET_HOLDER;

extern int inputSock;
extern int AppVersionQuad[4];
extern int ServerMajorVersion;
extern unsigned char currentAesIv[16];
extern struct {
    void (*connectionTerminated)(int);
} ListenerCallbacks;
extern int (*sendInputPacketOnControlStream)(unsigned char*, int);
extern int (*LastSocketError)(void);
extern int (*encryptData)(const unsigned char*, int, unsigned char*, int*);
extern int (*checkDirs)(uint8_t, uint8_t, int*);
extern int (*LbqWaitForQueueElement)(void*, void**);
extern int (*LbqPeekQueueElement)(void*, void**);
extern int (*LbqPollQueueElement)(void*, void**);
extern void* packetQueue;
extern void inputSendThread;
extern int (*PltIsThreadInterrupted)(void*);
extern void (*Limelog)(const char*, ...);