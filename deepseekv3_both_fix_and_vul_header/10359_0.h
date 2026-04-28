#include <stdlib.h>

typedef struct _KernelInfo KernelInfo;
struct _KernelInfo {
    KernelInfo *next;
};

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

#define DisableMSCWarning(n)
#define RestoreMSCWarning

static KernelInfo *CloneKernelInfo(const KernelInfo *);
static void RotateKernelInfo(KernelInfo *, double);
static MagickBooleanType SameKernelInfo(const KernelInfo *, const KernelInfo *);
static KernelInfo *LastKernelInfo(KernelInfo *);
static KernelInfo *DestroyKernelInfo(KernelInfo *);