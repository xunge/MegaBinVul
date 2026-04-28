#include <stddef.h>

typedef struct _VipsMask VipsMask;
typedef struct _VipsMaskClass VipsMaskClass;
typedef struct _VipsPoint VipsPoint;
typedef struct _VipsObject VipsObject;

struct _VipsObject {
    void *klass;
};

struct _VipsPoint {
    int width;
    int height;
};

struct _VipsMask {
    unsigned int optical : 1;
    unsigned int nodc : 1;
    unsigned int reject : 1;
};

struct _VipsMaskClass {
    float (*point)(VipsMask *mask, double dx, double dy);
};

#define VIPS_MASK(point) ((VipsMask *)(point))
#define VIPS_MASK_GET_CLASS(point) ((VipsMaskClass *)(((VipsObject *)(point))->klass))