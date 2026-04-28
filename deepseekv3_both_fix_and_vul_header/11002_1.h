#include <stdlib.h>

struct kvaser_usb_net_priv {
    int channel;
    struct {
        unsigned int ctrlmode;
    } can;
    void *dev;
};

struct kvaser_cmd_ctrl_mode {
    unsigned char tid;
    unsigned char channel;
    unsigned char ctrl_mode;
};

struct kvaser_cmd {
    int id;
    int len;
    union {
        struct kvaser_cmd_ctrl_mode ctrl_mode;
    } u;
};

#define CMD_SET_CTRL_MODE 0
#define CMD_HEADER_LEN 0
#define KVASER_CTRL_MODE_SILENT 0
#define KVASER_CTRL_MODE_NORMAL 0
#define CAN_CTRLMODE_LISTENONLY 0x01
#define GFP_KERNEL 0
#define ENOMEM (-1)

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);
int kvaser_usb_send_cmd(void *dev, struct kvaser_cmd *cmd, int len);