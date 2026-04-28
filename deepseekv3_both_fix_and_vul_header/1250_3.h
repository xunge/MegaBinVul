#include <stdio.h>
#include <string.h>

#define L_MARGIN 0.5
#define T_MARGIN 0.5
#define B_MARGIN 0.5
#define R_MARGIN 0.5

typedef struct gx_device_s {
    int x_pixels_per_inch;
    int y_pixels_per_inch;
    int width;
    int height;
} gx_device;

typedef struct gx_device_printer_s {
    void *memory;
    int x_pixels_per_inch;
    int y_pixels_per_inch;
    int width;
    int height;
} gx_device_printer;

typedef struct gp_file_s gp_file;
typedef unsigned char byte;

enum {
    gs_error_VMerror = -1
};

extern int gdev_mem_bytes_per_scan_line(gx_device *);
extern void *gs_malloc(void *, unsigned int, unsigned int, const char *);
extern void gs_free(void *, char *, unsigned int, unsigned int, const char *);
extern int return_error(int);
extern void gdev_prn_get_bits(gx_device_printer *, int, byte *, byte **);
extern int gdev_prn_copy_scan_lines(gx_device_printer *, int, byte *, int);
extern int gp_fwrite(const void *, size_t, size_t, gp_file *);
extern int gp_fprintf(gp_file *, const char *, ...);
extern int gp_fflush(gp_file *);