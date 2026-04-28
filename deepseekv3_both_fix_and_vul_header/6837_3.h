#include <stddef.h>
#include <stdint.h>

typedef void* cl_command_queue;
typedef void* cl_mem;
typedef unsigned int cl_uint;
typedef int cl_int;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned int number_channels;
} Image;

typedef void* MagickCLEnv;
typedef void* MagickCLDevice;

typedef struct _ResizeFilter {
    double coefficients[7];
} ResizeFilter;

typedef struct _ExceptionInfo {
    int severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef uint64_t MagickSizeType;
typedef unsigned int CLQuantum;

typedef enum {
    MagickFalse,
    MagickTrue
} MagickBooleanType;

#define CL_MEM_COPY_HOST_PTR (1 << 0)
#define CL_MEM_READ_ONLY (1 << 1) 
#define CL_MEM_READ_WRITE (1 << 2)

#define ResourceLimitWarning 300

static MagickCLDevice RequestOpenCLDevice(MagickCLEnv);
static cl_command_queue AcquireOpenCLCommandQueue(MagickCLDevice);
static Image* CloneImage(const Image*, size_t, size_t, MagickBooleanType, ExceptionInfo*);
static cl_mem GetAuthenticOpenCLBuffer(const Image*, MagickCLDevice, ExceptionInfo*);
static const double* GetResizeFilterCoefficient(const ResizeFilter*);
static cl_mem CreateOpenCLBuffer(MagickCLDevice, cl_uint, size_t, const void*);
static void OpenCLThrowMagickException(MagickCLDevice, ExceptionInfo*, const char*, int, const char*, const char*);
static const char* GetMagickModule(void);
static MagickBooleanType resizeHorizontalFilter(MagickCLDevice, cl_command_queue, const Image*, Image*, cl_mem, cl_uint, cl_uint, cl_uint, cl_mem, cl_uint, cl_uint, const ResizeFilter*, cl_mem, float, ExceptionInfo*);
static MagickBooleanType resizeVerticalFilter(MagickCLDevice, cl_command_queue, const Image*, Image*, cl_mem, cl_uint, cl_uint, cl_uint, cl_mem, cl_uint, cl_uint, const ResizeFilter*, cl_mem, float, ExceptionInfo*);
static void ReleaseOpenCLMemObject(cl_mem);
static void ReleaseOpenCLCommandQueue(MagickCLDevice, cl_command_queue);
static void ReleaseOpenCLDevice(MagickCLDevice);
static Image* DestroyImage(Image*);