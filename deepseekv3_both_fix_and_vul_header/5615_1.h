#include <stdint.h>
#include <stddef.h>

typedef struct IDEDMA {
    // empty struct definition to make it complete
} IDEDMA;

typedef struct SGList {
    uint32_t size;
} SGList;

typedef struct IDEState {
    SGList sg;
    uint32_t io_buffer_offset;
    uint32_t io_buffer_size;
} IDEState;

typedef struct AHCIPort {
    IDEState *ifs;
    int port_no;
} AHCIPort;

typedef struct AHCIDevice {
    AHCIPort port;
    IDEDMA dma;
} AHCIDevice;

#define DO_UPCAST(type, field, obj) ((type *) ((char *) (obj) - offsetof(type, field)))
#define DPRINTF(port_no, fmt, ...)