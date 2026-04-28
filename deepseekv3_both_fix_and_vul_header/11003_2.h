#include <stdlib.h>
#include <stddef.h>

struct kvaser_cmd_flush_queue {
    unsigned char channel;
    unsigned char flags;
};

struct kvaser_cmd {
    int id;
    size_t len;
    union {
        struct kvaser_cmd_flush_queue flush_queue;
    } u;
};

struct kvaser_usb_net_priv {
    int channel;
    void *dev;
};

#define CMD_FLUSH_QUEUE 0
#define CMD_HEADER_LEN 0
#define GFP_KERNEL 0
#define ENOMEM 1

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
int kvaser_usb_send_cmd(void *dev, struct kvaser_cmd *cmd, size_t len);