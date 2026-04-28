#include <stdint.h>
#include <stddef.h>

typedef struct {
    // 这里应该包含l2cap_channel_t的实际成员
    // 由于原代码未提供，我们只声明一个空结构体
} l2cap_channel_t;

extern l2cap_channel_t l2cap_channels[];
extern uint16_t l2cap_channel_count;
#define L2CAP_FLOW_CHANNEL 0