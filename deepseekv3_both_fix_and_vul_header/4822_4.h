#include <stdint.h>
#include <stdlib.h>

typedef struct AddressSpace AddressSpace;
typedef struct DeviceState DeviceState;
typedef struct Error Error;

#define OHCI_MAX_PORTS 15
#define USB_HZ 12000000
#define USB_SPEED_MASK_LOW 0x01
#define USB_SPEED_MASK_FULL 0x02
#define QEMU_CLOCK_VIRTUAL 1

typedef uint64_t dma_addr_t;

struct USBPort {
    struct USBPort *port;
};

struct USBBus {
    char dummy;
};

struct USBPacket {
    char dummy;
};

struct MemoryRegion {
    char dummy;
};

typedef struct OHCIState {
    AddressSpace *as;
    int num_ports;
    struct USBBus bus;
    struct {
        struct USBPort port;
    } rhport[OHCI_MAX_PORTS];
    struct MemoryRegion mem;
    dma_addr_t localmem_base;
    const char *name;
    struct USBPacket usb_packet;
    int async_td;
    void *eof_timer;
} OHCIState;

static struct {
    int dummy;
} ohci_mem_ops;

static struct {
    int dummy;
} ohci_bus_ops;

static struct {
    int dummy;
} ohci_port_ops;

static uint64_t usb_frame_time;
static uint64_t usb_bit_time;

static uint64_t get_ticks_per_sec(void) { return 0; }
static uint64_t muldiv64(uint64_t a, uint64_t b, uint64_t c) { return 0; }
static void trace_usb_ohci_init_time(uint64_t frame_time, uint64_t bit_time) {}
static void usb_register_companion(const char *masterbus, struct USBPort **ports, int num_ports, uint32_t firstport, void *opaque, const void *port_ops, int speedmask, Error **errp) {}
static void usb_bus_new(struct USBBus *bus, size_t bus_size, const void *bus_ops, DeviceState *dev) {}
static void usb_register_port(struct USBBus *bus, struct USBPort *port, void *opaque, int index, const void *port_ops, int speedmask) {}
static void memory_region_init_io(struct MemoryRegion *mr, void *obj, const void *ops, void *opaque, const char *name, size_t size) {}
static const char *object_get_typename(void *obj) { return NULL; }
static void usb_packet_init(struct USBPacket *pkt) {}
static void *timer_new_ns(int clock_type, void (*cb)(void *), void *opaque) { return NULL; }
static void ohci_frame_boundary(void *opaque) {}
static void error_propagate(Error **dst_err, Error *local_err) {}
#define OBJECT(dev) ((void*)(dev))
#define USBPort struct USBPort