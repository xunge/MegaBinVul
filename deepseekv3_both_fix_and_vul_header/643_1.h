#include <stddef.h>
#include <errno.h>

#define HCI_UART_PROTO_READY 0

struct hci_uart {
    const struct hci_uart_proto *proto;
    unsigned long flags;
};

struct hci_uart_proto {
    // Add necessary fields here
};

static inline void set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}

static inline void clear_bit(int nr, volatile unsigned long *addr) {
    *addr &= ~(1UL << nr);
}

static const struct hci_uart_proto *hci_uart_get_proto(int id) {
    return NULL;
}

static int hci_uart_register_dev(struct hci_uart *hu) {
    return 0;
}

#define EPROTONOSUPPORT ENOPROTOOPT