#include <linux/types.h>
#include <linux/tty.h>
#include <linux/errno.h>

#define EBADF 9
#define EBUSY 16
#define EUNATCH 49

#define HCIUARTSETPROTO 0
#define HCIUARTGETPROTO 1
#define HCIUARTGETDEVICE 2
#define HCIUARTSETFLAGS 3
#define HCIUARTGETFLAGS 4

#define HCI_UART_PROTO_SET 0
#define HCI_UART_PROTO_READY 1
#define HCI_UART_REGISTERED 2

#define BT_DBG(fmt, ...)

struct hci_uart {
    unsigned long flags;
    struct hci_dev *hdev;
    struct hci_uart_proto *proto;
    int hdev_flags;
};

struct hci_uart_proto {
    int id;
};

struct hci_dev {
    int id;
};

struct tty_struct {
    struct hci_uart *disc_data;
};

extern int n_tty_ioctl_helper(struct tty_struct *tty, unsigned int cmd, unsigned long arg);
extern int hci_uart_set_proto(struct hci_uart *hu, unsigned long arg);
extern int hci_uart_set_flags(struct hci_uart *hu, unsigned long arg);