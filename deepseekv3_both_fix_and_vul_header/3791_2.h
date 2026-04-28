#include <stddef.h>
#include <stdint.h>

typedef struct gx_device_printer_s gx_device_printer;
typedef struct gx_device_lprn_s gx_device_lprn;

struct gx_device_lprn_s {
    int nBh;
    int BlockLine;
    int nBw;
    uint8_t *ImageBuf;
};

extern int gdev_mem_bytes_per_scan_line(gx_device_printer *pdev);

typedef uint8_t byte;