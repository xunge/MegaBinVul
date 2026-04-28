#include <stdlib.h>
#include <stdint.h>

#define BROADCAST_ID 0xFE
#define COMM_TX_FAIL 1
#define COMM_NOT_AVAILABLE 2
#define COMM_SUCCESS 0
#define RXPACKET_MAX_LEN 256

#define PKT_ID 2
#define PKT_LENGTH_L 3
#define PKT_LENGTH_H 4
#define PKT_INSTRUCTION 5
#define PKT_PARAMETER0 6
#define PKT_ERROR 4

#define INST_READ 2

#define DXL_LOBYTE(w) ((uint8_t)((w) & 0xFF))
#define DXL_HIBYTE(w) ((uint8_t)((w) >> 8))

class PortHandler;

class Protocol2PacketHandler {
public:
    int readTxRx(PortHandler *port, uint8_t id, uint16_t address, uint16_t length, uint8_t *data, uint8_t *error);
    int txRxPacket(PortHandler *port, uint8_t *txpacket, uint8_t *rxpacket, uint8_t *error);
};