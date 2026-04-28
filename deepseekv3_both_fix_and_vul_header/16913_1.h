#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct gx_device_printer_s gx_device_printer;
typedef struct gx_device_s gx_device;
typedef struct gp_file_s gp_file;
typedef unsigned char byte;

#define DD 0x80
#define gs_error_rangecheck (-15)
#define return_error(code) (code)

struct gx_device_printer_s {
    int y_pixels_per_inch;
    int width;
    int height;
    int x_pixels_per_inch;
    void *memory;
};

int gx_device_has_color(gx_device_printer *pdev);
int gdev_mem_bytes_per_scan_line(gx_device *dev);
int gdev_prn_copy_scan_lines(gx_device_printer *pdev, int lnum, byte *data, int size);
void gdev_prn_transpose_8x8(byte *inp, int line_size, byte *outp, int y_mult);
void epsc_output_run(byte *out_blk, int size, int y_mult, char start_graphics, gp_file *prn_stream, int pass);
void *gs_malloc(void *mem, int size, int count, const char *cname);
void gs_free(void *mem, char *data, int size, int count, const char *cname);

int gp_fwrite(const void *ptr, size_t size, size_t count, gp_file *stream);
int gp_fputs(const char *str, gp_file *stream);
int gp_fprintf(gp_file *stream, const char *format, ...);
int gp_fputc(int c, gp_file *stream);