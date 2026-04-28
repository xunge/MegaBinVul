#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024

typedef struct gx_device_printer_s {
    void *memory;
    int height;
} gx_device_printer;

typedef struct gx_device_s gx_device;
typedef struct gp_file_s gp_file;
typedef unsigned char byte;
typedef unsigned long ulong;

int gp_fputs(const char *str, gp_file *stream);
int gp_fprintf(gp_file *stream, const char *format, ...);
int gp_fputc(int c, gp_file *stream);
size_t gp_fwrite(const void *ptr, size_t size, size_t count, gp_file *stream);

extern int gdev_mem_bytes_per_scan_line(gx_device *);
extern void gdev_prn_copy_scan_lines(gx_device_printer *, int, byte *, int);
extern void emprintf2(void *, const char *, int, int);
extern int return_error(int);
#define gs_error_rangecheck 1