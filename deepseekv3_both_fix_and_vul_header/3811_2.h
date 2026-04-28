#include <stdbool.h>
#include <stddef.h>

typedef struct gx_image_enum_common_s gx_image_enum_common_t;
typedef struct gx_device_xps_s gx_device_xps;
typedef struct rc_header_s rc_header;
typedef struct gs_memory_s gs_memory_t;
typedef struct gsicc_link_s gsicc_link_t;
typedef struct tiff TIFF;

typedef struct xps_image_enum_s {
    TIFF *tif;
    gx_device_xps *dev;
    rc_header *pcs;
    gs_memory_t *memory;
    void *buffer;
    void *devc_buffer;
    gsicc_link_t *icc_link;
} xps_image_enum_t;

enum {
    xps_solidbrush
};

extern int TIFFWriteDirectory(TIFF*);
extern void TIFFCleanup(TIFF*);
extern int xps_add_tiff_image(xps_image_enum_t *pie);
extern void xps_setstrokebrush(gx_device_xps *dev, int brush_type);
extern void xps_setfillbrush(gx_device_xps *dev, int brush_type);
extern int xps_add_image_relationship(xps_image_enum_t *pie);
extern void rc_decrement(rc_header *pcs, const char *cname);
extern void gs_free_object(gs_memory_t *mem, void *ptr, const char *cname);
extern void gsicc_release_link(gsicc_link_t *icc_link);