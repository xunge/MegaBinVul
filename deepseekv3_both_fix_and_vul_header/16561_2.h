#include <stddef.h>
#include <errno.h>

#define IMAGE_SIZE_INVAL ((ulong)(-1))
#define FIT_DESC_PROP "description"
#define FIT_TIMESTAMP_PROP "timestamp"
#define FIT_IMAGES_PATH "/images"
#define IMAGE_ENABLE_TIMESTAMP 1
#define CONFIG_IS_ENABLED(x) 1
#define FIT_FULL_CHECK 1

typedef unsigned long ulong;

int fdt_check_header(const void *fdt);
int fdt_check_full(const void *fdt, int size);
int fdt_totalsize(const void *fdt);
const void *fdt_getprop(const void *fdt, int nodeoffset, const char *name, int *lenp);
int fdt_path_offset(const void *fdt, const char *path);
void log_debug(const char *fmt, ...);