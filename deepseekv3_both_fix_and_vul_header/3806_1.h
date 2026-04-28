#include <stddef.h>

struct gx_device_s {
    float HWResolution[2];
    struct gs_memory_s *memory;
};

typedef struct gx_device_s gx_device;
typedef struct gs_memory_s gs_memory;

#define emprintf(mem, ...) 
#define return_error(err) (err)
#define gs_error_rangecheck (-1)

extern int gdev_prn_open(gx_device *pdev);