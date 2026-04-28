#include <stdio.h>
#include <string.h>

#define MagickPathExtent 4096
#define DirectorySeparator "/"
#define CL_PROGRAM_BUILD_LOG 0x1183

typedef void* cl_program;
typedef void* cl_device_id;
typedef unsigned int cl_program_build_info;

struct _MagickCLDevice {
    cl_program program;
    cl_device_id deviceID;
};

typedef struct _MagickCLDevice *MagickCLDevice;
typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _OpenCL_library {
    int (*clGetProgramBuildInfo)(cl_program, cl_device_id, cl_program_build_info, size_t, void*, size_t*);
} OpenCL_library;

extern OpenCL_library *openCL_library;
extern const char *GetOpenCLCacheDirectory(void);
extern int remove_utf8(const char *);
extern int BlobToFile(const char *, const void *, size_t, ExceptionInfo *);
extern char *AcquireMagickMemory(size_t);
extern char *RelinquishMagickMemory(char *);
extern int FormatLocaleString(char *, size_t, const char *, ...);