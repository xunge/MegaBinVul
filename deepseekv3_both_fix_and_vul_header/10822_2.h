#include <stddef.h>
#include <stdint.h>

typedef uint32_t cl_uint;
typedef void* cl_program;
typedef unsigned int cl_program_info;
#define CL_PROGRAM_BINARY_SIZES 0
#define CL_PROGRAM_BINARIES 1
#define CL_SUCCESS 0
#define ResourceLimitError 1

typedef struct _MagickCLDevice {
    cl_program program;
} *MagickCLDevice;

typedef struct _ExceptionInfo ExceptionInfo;

struct _OpenCL_library {
    cl_uint (*clGetProgramInfo)(cl_program, cl_program_info, size_t, void*, size_t*);
};
extern struct _OpenCL_library *openCL_library;

extern void *AcquireMagickMemory(size_t);
extern void *RelinquishMagickMemory(void*);
extern void ThrowMagickException(ExceptionInfo*, const char*, int, const char*, const char*, ...);
extern int BlobToFile(const char*, const void*, size_t, ExceptionInfo*);
extern const char *GetMagickModule(void);