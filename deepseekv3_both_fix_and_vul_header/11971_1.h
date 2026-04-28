#include <stdint.h>
#include <algorithm>

#define EATT_MAX_TX_MTU 0

struct EattChannel {
    uint16_t tx_mtu_;
};

static EattChannel eatt_channel_instance;
#define this (&eatt_channel_instance)