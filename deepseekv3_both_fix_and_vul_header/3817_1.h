#include <stdint.h>
#include <string.h>

typedef unsigned int uint;
typedef unsigned char byte;

typedef struct gx_device_printer_s {
    int x_pixels_per_inch;
    int y_pixels_per_inch;
    int width;
    int height;
    void *memory;
} gx_device_printer;

typedef struct gp_file_s gp_file;

#define return_error(code) (code)

#define gs_error_rangecheck 1
#define gs_error_VMerror 2

extern uint gdev_prn_raster(gx_device_printer *pdev);
extern void *gs_malloc(void *mem, uint size, int type, const char *cname);
extern void gs_free(void *mem, char *ptr, uint size, int type, const char *cname);
extern int gdev_prn_copy_scan_lines(gx_device_printer *pdev, int line, byte *data, uint size);
extern void memflip8x8(const byte *in, uint in_line, byte *out, uint out_line);
extern void dot24_improve_bitmap(byte *data, int length);
extern void dot24_output_run(byte *data, int length, int x_high, gp_file *prn_stream);

extern int gp_fwrite(const void *ptr, size_t count, size_t size, gp_file *stream);
extern int gp_fputc(int c, gp_file *stream);
extern int gp_fputs(const char *s, gp_file *stream);
extern int gp_fprintf(gp_file *stream, const char *format, ...);
extern int gp_fflush(gp_file *stream);