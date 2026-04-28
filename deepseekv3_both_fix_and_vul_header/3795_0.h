#include <string.h>

typedef unsigned char byte;

typedef struct gx_device_printer_s {
    int y_pixels_per_inch;
    int x_pixels_per_inch;
} gx_device_printer;

typedef struct gp_file_s gp_file;

int gp_fputs(const char *str, gp_file *file);
int gp_fputc(int c, gp_file *file);
size_t gp_fwrite(const void *ptr, size_t size, size_t nmemb, gp_file *file);