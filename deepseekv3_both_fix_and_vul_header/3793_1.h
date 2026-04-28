#include <stdio.h>
#include <string.h>

typedef unsigned char byte;

typedef struct gx_device_s {
    void *memory;
    char *fname;
    int height;
} gx_device;

typedef struct gx_device_printer_s {
    void *memory;
    char *fname;
    int height;
} gx_device_printer;

typedef struct gp_file_s gp_file;

#define gs_error_VMerror (-1)

extern int gdev_mem_bytes_per_scan_line(gx_device *);
extern int gdev_prn_copy_scan_lines(gx_device_printer *, int, byte *, int);
extern void *gs_malloc(void *, size_t, size_t, const char *);
extern void gs_free(void *, void *, size_t, size_t, const char *);
extern int gp_fprintf(gp_file *, const char *, ...);
extern int return_error(int);