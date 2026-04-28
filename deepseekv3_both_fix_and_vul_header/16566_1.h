#include <stdint.h>
#include <string.h>

#define ulong unsigned long
#define ENOEXEC 8
#define EINVAL 22
#define ENOMSG 42
#define ENODATA 61
#define ENOENT 2

#define CONFIG_IS_ENABLED(opt) 0
#define FIT_FULL_CHECK ""
#define IMAGE_SIZE_INVAL 0
#define FIT_DESC_PROP "description"
#define FIT_TIMESTAMP_PROP "timestamp"
#define FIT_IMAGES_PATH "/images"
#define IMAGE_ENABLE_TIMESTAMP 0

int fdt_check_header(const void *fdt);
int fdt_check_full(const void *fdt, size_t size);
const void *fdt_getprop(const void *fdt, int nodeoffset, const char *name, int *lenp);
int fdt_path_offset(const void *fdt, const char *path);
size_t fdt_totalsize(const void *fdt);
void log_debug(const char *fmt, ...);