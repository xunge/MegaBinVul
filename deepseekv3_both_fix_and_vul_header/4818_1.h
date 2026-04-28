#include <stdint.h>
#include <stdlib.h>

typedef struct PCIDevice PCIDevice;
typedef struct OHCIState OHCIState;
typedef struct OHCIPCIState OHCIPCIState;
typedef struct USBPacket USBPacket;
typedef struct USBBus USBBus;
typedef struct USBPort USBPort;

struct USBPacket {
    int dummy;
};

struct USBBus {
    int dummy;
};

struct USBPort {
    int dummy;
};

struct OHCIState {
    char *name;
    int async_td;
    USBPacket usb_packet;
    USBPort *ports;
    USBBus bus;
    void *eof_timer;
};

struct OHCIPCIState {
    OHCIState state;
    int masterbus;
};

#define PCI_OHCI(dev) ((OHCIPCIState *)(dev))

void trace_usb_ohci_exit(const char *name);
void ohci_bus_stop(OHCIState *s);
void usb_cancel_packet(USBPacket *p);
void ohci_stop_endpoints(OHCIState *s);
void usb_bus_release(USBBus *bus);
void timer_del(void *timer);
void timer_free(void *timer);