#include <stdlib.h>
#include <assert.h>

typedef struct {
    const char *colo_export;
    const char *active_disk;
    const char *hidden_disk;
    int readwrite;
} libxl_device_disk;

typedef struct libxl__gc libxl__gc;

#define GCSPRINTF(...) NULL

enum {
    LIBXL__COLO_NONE,
    LIBXL__COLO_PRIMARY,
    LIBXL__COLO_SECONDARY
};