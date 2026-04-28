#include <stdint.h>
#include <assert.h>
#include <stdio.h>

typedef enum {
    TPKT_PACKET_COMPLETE,
    TPKT_ERROR,
    TPKT_WAITING
} TpktState;

typedef struct {
    uint8_t* buffer;
    int maxSize;
    int size;
} Buffer;

typedef struct {
    Buffer* readBuffer;
    int packetSize;
} CotpConnection;

extern int DEBUG_COTP;
extern int readFromSocket(CotpConnection* self, uint8_t* buffer, int size);