#include <stdlib.h>

typedef struct KernelInfo KernelInfo;

struct KernelInfo {
    KernelInfo *next;
};

static KernelInfo* CloneKernelInfo(KernelInfo *kernel);
static void RotateKernelInfo(KernelInfo *kernel, int degrees);
static KernelInfo* LastKernelInfo(KernelInfo *kernel);