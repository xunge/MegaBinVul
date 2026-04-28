#include <stdio.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned long ulong;

#define LINE_SIZE 0
#define X_DPI 0
#define Y_DPI 0

typedef struct gx_device_s gx_device;
typedef struct gx_device_printer_s gx_device_printer;
typedef struct gp_file_s gp_file;

int gdev_mem_bytes_per_scan_line(gx_device *dev);
void gdev_prn_copy_scan_lines(gx_device_printer *pdev, int lnum, byte *data, int line_size);
int compress1_row(byte *row, byte *end_row, byte *temp);
void *gs_malloc(void *mem, size_t size, int type, const char *cname);
void gs_free(void *mem, char *data, size_t size, int type, const char *cname);
int gp_fprintf(gp_file *file, const char *format, ...);
int gp_fputs(const char *str, gp_file *file);
int gp_fwrite(const void *ptr, size_t size, size_t count, gp_file *file);
int return_error(int error);
#define gs_error_VMerror 0

struct gx_device_printer_s {
    void *memory;
    int height;
};