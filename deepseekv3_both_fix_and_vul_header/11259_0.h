#include <stdint.h>

#define PKT_IS_PSEUDOPKT(p) 0

typedef struct Flow_ Flow;
typedef struct Packet_ {
    Flow *flow;
} Packet;

typedef struct TcpSession_ {
    uint8_t state;
    uint8_t pstate;
} TcpSession;

enum {
    TCP_ESTABLISHED,
    TCP_FIN_WAIT1,
    TCP_FIN_WAIT2,
    TCP_CLOSING,
    TCP_CLOSE_WAIT,
    TCP_LAST_ACK,
    TCP_TIME_WAIT,
    TCP_CLOSED
};

enum {
    FLOW_STATE_ESTABLISHED,
    FLOW_STATE_CLOSED
};

void FlowUpdateState(Flow *flow, int state);