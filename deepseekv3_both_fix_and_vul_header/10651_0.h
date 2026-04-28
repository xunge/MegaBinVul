#include <stdlib.h>

typedef struct GrubDevice {
    void *disk;
} GrubDevice;

typedef struct GrubFile {
    GrubDevice *device;
} GrubFile;

typedef struct GrubFS {
    GrubFile *file;
} GrubFS;