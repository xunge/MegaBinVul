#include <stddef.h>
#include <stdlib.h>

extern int get_image_size(const char *filename_path);
extern int load_image(const char *filename, void *addr);
extern void error_report(const char *fmt, ...);
extern void *g_malloc0(size_t size);
extern void g_free(void *ptr);
extern int fdt_open_into(const void *fdt, void *buf, int bufsize);
extern int fdt_check_header(const void *fdt);