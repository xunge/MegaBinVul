#include <stdio.h>
#include <string.h>

typedef struct gx_device_printer_s gx_device_printer;
typedef struct gx_device_s gx_device;
typedef struct gp_file_s gp_file;
typedef unsigned char byte;

#define gs_error_rangecheck (-1)
#define gs_error_VMerror (-2)
#define return_error(code) (code)

struct gx_device_printer_s {
    int x_pixels_per_inch;
    int height;
    void *memory;
};

int gdev_mem_bytes_per_scan_line(gx_device *pdev);
void gdev_prn_get_bits(gx_device_printer *pdev, int lnum, byte *in, byte **in_data);
int gdev_prn_copy_scan_lines(gx_device_printer *pdev, int lnum, byte *in, int in_size);
void gdev_prn_transpose_8x8(byte *inp, int line_size, byte *out_end, int n);
void okiibm_output_run(byte *out, int size, int out_y_mult, char start_graphics, gp_file *prn_stream, int pass);
void *gs_malloc(void *memory, int size, int n, const char *msg);
void gs_free(void *memory, char *buf, int size, int n, const char *msg);

int gp_fwrite(const char *str, int size, int n, gp_file *stream);
int gp_fprintf(gp_file *stream, const char *format, ...);
int gp_fputs(const char *str, gp_file *stream);
int gp_fputc(int c, gp_file *stream);
int gp_fflush(gp_file *stream);