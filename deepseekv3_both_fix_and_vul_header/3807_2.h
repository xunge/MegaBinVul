#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct gx_device_printer_s {
    void *memory;
    const char *dname;
    int height;
} gx_device_printer;

typedef struct gx_device_tiff_s {
    void *tif;
    int BigEndian;
    int UseBigTIFF;
} gx_device_tiff;

typedef struct gp_file_s gp_file;
typedef unsigned char byte;

#define TIFFTAG_BITSPERSAMPLE 258
#define gs_error_invalidfileaccess 1
#define gs_error_VMerror 2
#define return_error(code) (code)

typedef uint32_t uint32;
typedef uint16_t uint16;

extern int gdev_prn_file_is_new(gx_device_printer *pdev);
extern void *tiff_from_filep(gx_device_printer *pdev, const char *dname, gp_file *file, int BigEndian, int UseBigTIFF);
extern int gdev_tiff_begin_page(gx_device_tiff *tfdev, gp_file *file);
extern void tiff_set_rgb_fields(gx_device_tiff *tfdev);
extern int gdev_prn_raster(gx_device_printer *pdev);
extern void *gs_alloc_bytes(void *memory, int size, const char *name);
extern void gs_free_object(void *memory, void *data, const char *name);
extern int gdev_prn_copy_scan_lines(gx_device_printer *pdev, int y, byte *data, int size);
extern int TIFFSetField(void *tif, int tag, int value);
extern int TIFFCheckpointDirectory(void *tif);
extern int TIFFWriteScanline(void *tif, void *buf, uint32 row, uint16 sample);
extern int TIFFWriteDirectory(void *tif);