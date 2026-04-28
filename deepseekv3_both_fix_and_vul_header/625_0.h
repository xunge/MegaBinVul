#include <stdlib.h>
#include <stdint.h>

#define COMM_TX_FAIL  -1001
#define COMM_SUCCESS  0
#define RXPACKET_MAX_LEN  256
#define PKT_ID  4
#define PKT_ERROR  8
#define PKT_PARAMETER0  9

class PortHandler;
class Protocol2PacketHandler {
public:
    int rxPacket(PortHandler *port, uint8_t *rxpacket);
    int readRx(PortHandler *port, uint8_t id, uint16_t length, uint8_t *data, uint8_t *error);
};