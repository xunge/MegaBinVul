#include <stddef.h>

typedef unsigned int cl_uint;
typedef unsigned long cl_ulong;
typedef void *cl_platform_id;
typedef void *cl_device_id;
typedef void *cl_context;
typedef int cl_int;
typedef unsigned long cl_device_type;
typedef unsigned long cl_platform_info;
typedef unsigned long cl_device_info;
typedef unsigned long cl_context_properties;

#define CL_SUCCESS 0
#define CL_DEVICE_TYPE_CPU 2
#define CL_DEVICE_TYPE_GPU 4
#define CL_CONTEXT_PLATFORM 0x1084
#define CL_PLATFORM_NAME 0x0902
#define CL_PLATFORM_VENDOR 0x0903
#define CL_DEVICE_NAME 0x102B
#define CL_DRIVER_VERSION 0x102D
#define CL_DEVICE_MAX_CLOCK_FREQUENCY 0x100C
#define CL_DEVICE_MAX_COMPUTE_UNITS 0x1002
#define CL_DEVICE_TYPE 0x1000
#define CL_DEVICE_LOCAL_MEM_SIZE 0x1023

typedef struct _MagickCLDevice *MagickCLDevice;
typedef struct _MagickCLEnv *MagickCLEnv;

typedef struct _MagickCLDevice {
    cl_context context;
    cl_device_id deviceID;
    char *platform_name;
    char *vendor_name;
    char *name;
    char *version;
    cl_uint max_clock_frequency;
    cl_uint max_compute_units;
    cl_device_type type;
    cl_ulong local_memory_size;
} _MagickCLDevice;

typedef struct _MagickCLEnv {
    size_t number_devices;
    size_t number_contexts;
    MagickCLDevice *devices;
    cl_context *contexts;
    struct _MagickCLLibrary *library;
} _MagickCLEnv;

typedef struct _MagickCLLibrary {
    cl_int (*clGetPlatformIDs)(cl_uint, cl_platform_id *, cl_uint *);
    cl_int (*clGetDeviceIDs)(cl_platform_id, cl_device_type, cl_uint, cl_device_id *, cl_uint *);
    cl_context (*clCreateContext)(const cl_context_properties *, cl_uint, const cl_device_id *, void *, void *, cl_int *);
    cl_int (*clGetPlatformInfo)(cl_platform_id, cl_platform_info, size_t, void *, size_t *);
    cl_int (*clGetDeviceInfo)(cl_device_id, cl_device_info, size_t, void *, size_t *);
} MagickCLLibrary;

extern MagickCLLibrary *openCL_library;

extern cl_uint GetOpenCLDeviceCount(MagickCLEnv, cl_platform_id);
extern void RelinquishMagickCLDevices(MagickCLEnv);
extern void *AcquireMagickMemory(size_t);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void *RelinquishMagickMemory(void *);
extern void ResetMagickMemory(void *, int, size_t);
extern MagickCLDevice AcquireMagickCLDevice(void);