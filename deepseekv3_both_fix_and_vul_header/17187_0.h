#include <stdlib.h>
#include <string.h>

typedef struct libxl__gc libxl__gc;
typedef struct libxl__json_object libxl__json_object;
typedef struct libxl_device_disk {
    const char *vdev;
    int format;
    const char *pdev_path;
} libxl_device_disk;

#define LIBXL_DISK_FORMAT_EMPTY 0

int libxl__device_disk_dev_number(const char *vdev, void *a, void *b);
void QMP_PARAMETERS_SPRINTF(libxl__json_object **args, const char *key, const char *fmt, int value);
void qmp_parameters_add_string(libxl__gc *gc, libxl__json_object **args, const char *key, const char *value);
int qmp_run_command(libxl__gc *gc, int domid, const char *command, libxl__json_object *args, void *a, void *b);