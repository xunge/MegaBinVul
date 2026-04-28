#include <stdlib.h>
#include <string.h>

typedef struct libxl__gc libxl__gc;
typedef struct libxl_device_disk {
    const char *colo_export;
    const char *active_disk;
    const char *hidden_disk;
} libxl_device_disk;

#define LIBXL__COLO_NONE 0
#define LIBXL__COLO_PRIMARY 1
#define LIBXL__COLO_SECONDARY 2

#define GCSPRINTF(...) NULL