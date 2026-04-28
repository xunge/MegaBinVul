#include <stdio.h>
#include <stdbool.h>

typedef struct _VipsImage {
    void *progress_signal;
    int dhint;
    void *out;
} VipsImage;

typedef struct _VipsForeignLoad {
    bool error;
    VipsImage *real;
    VipsImage *out;
} VipsForeignLoad;

typedef struct _VipsForeignLoadClass {
    int (*load)(VipsForeignLoad *);
} VipsForeignLoadClass;

typedef struct _VipsOperation {} VipsOperation;
typedef struct _VipsRegion {} VipsRegion;

#define VIPS_FOREIGN_LOAD(b) ((VipsForeignLoad *)(b))
#define VIPS_FOREIGN_LOAD_GET_CLASS(load) ((VipsForeignLoadClass *)(load))
#define VIPS_OPERATION(load) ((VipsOperation *)(load))
#define G_OBJECT(obj) ((void *)(obj))
#define TRUE true
#define FALSE false

static void g_object_set_qdata(void *obj, void *key, void *data) {}

extern VipsImage *vips_foreign_load_temp(VipsForeignLoad *load);
extern int vips_image_pio_input(VipsImage *image);
extern int vips_foreign_load_iscompat(VipsImage *real, VipsImage *out);
extern void vips_operation_invalidate(VipsOperation *operation);
extern void vips_image_pipelinev(VipsImage *out, int dhint, VipsImage *real, void *null);
extern VipsRegion *vips_region_new(VipsImage *image);
extern void *vips__foreign_load_operation;