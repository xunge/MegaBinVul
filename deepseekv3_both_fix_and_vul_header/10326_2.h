#include <stddef.h>
#include <sys/types.h>

typedef struct {
    float x, y, z;
} DDSVector3;

typedef struct {
    float x, y, z, w;
} DDSVector4;

static void VectorInit(DDSVector4 v, float val) {
    v.x = val;
    v.y = val;
    v.z = val;
    v.w = val;
}

static float MaxF(float a, float b) {
    return a > b ? a : b;
}

static void VectorCopy43(DDSVector4 src, DDSVector3 *dst) {
    dst->x = src.x;
    dst->y = src.y;
    dst->z = src.z;
}