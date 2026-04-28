#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024

typedef unsigned char byte;
typedef unsigned long ulong;

typedef struct gx_device_s {
    void *memory;
    int height;
} gx_device;

typedef struct gx_device_printer_s {
    gx_device *memory;
    int height;
} gx_device_printer;

typedef FILE gp_file;

#define gs_error_rangecheck 1

static inline int gp_fputs(const char *str, gp_file *f) {
    return fputs(str, f);
}

static inline int gp_fprintf(gp_file *f, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = vfprintf(f, fmt, args);
    va_end(args);
    return ret;
}

static inline int gp_fputc(int c, gp_file *f) {
    return fputc(c, f);
}

static inline size_t gp_fwrite(const void *ptr, size_t size, size_t nmemb, gp_file *f) {
    return fwrite(ptr, size, nmemb, f);
}

static inline int gdev_mem_bytes_per_scan_line(gx_device *dev) {
    return 0;
}

static inline void gdev_prn_copy_scan_lines(gx_device_printer *pdev, int lnum, byte *data, int size) {
}

static inline void emprintf2(void *memory, const char *fmt, int a, int b) {
    fprintf(stderr, fmt, a, b);
}

static inline int return_error(int err) {
    return err;
}