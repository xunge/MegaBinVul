#include <stddef.h>

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

struct _MagickCLDevice {
    double score;
};

struct _MagickCLEnv {
    void *library;
    struct _MagickCLDevice **devices;
    size_t number_devices;
    unsigned long benchmark_thread_id;
    MagickBooleanType initialized;
    MagickBooleanType enabled;
    double cpu_score;
};

typedef struct _MagickCLEnv *MagickCLEnv;
typedef struct _MagickCLDevice *MagickCLDevice;

extern MagickCLEnv AcquireMagickCLEnv(void);
extern void *AcquireMagickMemory(size_t);
extern unsigned long GetMagickThreadId(void);
extern void RunDeviceBenckmark(MagickCLEnv, MagickCLEnv, MagickCLDevice);
extern MagickBooleanType IsSameOpenCLDevice(MagickCLDevice, MagickCLDevice);
extern MagickCLEnv RelinquishMagickCLEnv(MagickCLEnv);
extern double RunOpenCLBenchmark(MagickBooleanType);
extern void CacheOpenCLBenchmarks(MagickCLEnv);

extern void *openCL_library;
extern MagickCLEnv default_CLEnv;
extern const double MAGICKCORE_OPENCL_UNDEFINED_SCORE;