#include <stdint.h>
#include <stdlib.h>

typedef struct PCIDevice {
    void *msix_table;
    void *msix_pba;
    void *msix_entry_used;
    void *msix_table_mmio;
    void *msix_pba_mmio;
} PCIDevice;

typedef struct USBBus {
    // Minimal fields needed for compilation
} USBBus;

typedef struct XHCIPort {
    int mem;
} XHCIPort;

typedef struct XHCIState {
    int numslots;
    int numports;
    void *mfwrap_timer;
    int mem;
    int mem_cap;
    int mem_oper;
    int mem_runtime;
    int mem_doorbell;
    XHCIPort *ports;
    USBBus bus;
} XHCIState;

#define XHCI(dev) ((XHCIState *)(dev))

static inline void trace_usb_xhci_exit(void) {}
static inline void xhci_disable_slot(XHCIState *xhci, int slot) {}
static inline void timer_del(void *timer) {}
static inline void timer_free(void *timer) {}
static inline void memory_region_del_subregion(int *mem, int *subregion) {}
static inline void usb_bus_release(USBBus *bus) {}