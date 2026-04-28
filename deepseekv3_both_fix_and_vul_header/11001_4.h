#include <stdlib.h>
#include <stdint.h>

typedef uint8_t u8;

struct kvaser_cmd_simple {
    u8 channel;
};

struct kvaser_cmd {
    u8 len;
    u8 id;
    union {
        struct kvaser_cmd_simple simple;
    } u;
};

struct kvaser_usb_net_priv {
    u8 channel;
};

#define CMD_HEADER_LEN 4
#define GFP_ATOMIC 0
#define ENOMEM 12

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);

extern int kvaser_usb_send_cmd_async(struct kvaser_usb_net_priv *priv,
                                   struct kvaser_cmd *cmd,
                                   u8 len);