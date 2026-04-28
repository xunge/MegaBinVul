#include <stddef.h>
#include <stdint.h>

typedef void* cl_command_queue;
typedef void* cl_mem;
typedef unsigned int cl_uint;
typedef int cl_int;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef enum {
    CL_MEM_READ_WRITE = 0x1,
    CL_MEM_READ_ONLY = 0x2,
    CL_MEM_COPY_HOST_PTR = 0x4
} cl_mem_flags;

typedef enum {
    ResourceLimitWarning
} ExceptionType;

typedef struct _Image {
    size_t columns;
    size_t rows;
    unsigned int number_channels;
} Image;

typedef struct _MagickCLEnv {
    // Placeholder structure
} MagickCLEnv;

typedef struct _ResizeFilter {
    // Placeholder structure
} ResizeFilter;

typedef struct _ExceptionInfo {
    // Placeholder structure
} ExceptionInfo;

typedef cl_mem MagickCLDevice;
typedef size_t MagickSizeType;
typedef float CLQuantum;