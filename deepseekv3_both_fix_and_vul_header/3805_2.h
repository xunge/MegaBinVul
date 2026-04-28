#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define MD_SIDE_MARGIN 0
#define MD_BOTTOM_MARGIN 0
#define MD_TOP_MARGIN 0

typedef struct gs_memory_s gs_memory;

typedef struct gx_device_s {
    float HWResolution[2];
    gs_memory *memory;
} gx_device;

#define emprintf(mem, fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define return_error(err) return err

enum {
    gs_error_rangecheck = -1
};

extern int gx_device_set_margins(gx_device *pdev, const float *margins, bool adjust);
extern int gdev_prn_open(gx_device *pdev);