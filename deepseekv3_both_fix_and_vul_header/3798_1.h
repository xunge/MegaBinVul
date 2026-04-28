#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct gx_device_printer_s {
    int y_pixels_per_inch;
    int width;
    int x_pixels_per_inch;
    int height;
    void *memory;
} gx_device_printer;

typedef struct gx_device_s gx_device;
typedef struct gp_file_s gp_file;
typedef unsigned char byte;

#define DD 0x80
#define gs_error_rangecheck (-15)
#define return_error(code) (code)

int gdev_prn_copy_scan_lines(gx_device_printer *pdev, int line, byte *data, int size);
void gdev_prn_transpose_8x8(const byte *in, int in_step, byte *out, int out_step);
int gx_device_has_color(gx_device *dev);
int gdev_mem_bytes_per_scan_line(gx_device *dev);
void *gs_malloc(void *mem, size_t size, size_t num, const char *name);
void gs_free(void *mem, void *ptr, size_t size, size_t num, const char *name);
void epsc_output_run(byte *data, int length, int y_mult, char start_graphics, gp_file *prn_stream, int pass);
int gp_fwrite(const void *ptr, size_t size, size_t count, gp_file *stream);
int gp_fputs(const char *str, gp_file *stream);
int gp_fprintf(gp_file *stream, const char *format, ...);
int gp_fputc(int c, gp_file *stream);