#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef unsigned int cl_uint;
typedef int cl_int;

typedef struct _MagickCLEnv {
    struct {
        cl_int (*clGetProgramInfo)(void*, unsigned int, size_t, void*, size_t*);
    } *library;
    void **programs;
} *MagickCLEnv;

typedef unsigned int MagickOpenCLProgram;
typedef struct _ExceptionInfo ExceptionInfo;

enum {
    CL_SUCCESS = 0,
    CL_OUT_OF_HOST_MEMORY = -6
};

#define CL_PROGRAM_NUM_DEVICES 0x1163
#define CL_PROGRAM_BINARY_SIZES 0x1165
#define CL_PROGRAM_BINARIES 0x1166

#define O_BINARY 0
#define S_MODE 0644

extern char *getBinaryCLProgramName(MagickCLEnv, MagickOpenCLProgram, unsigned int);
extern void *AcquireMagickMemory(size_t);
extern void *RelinquishMagickMemory(void*);
extern void *AcquireQuantumMemory(size_t, size_t);
extern void ThrowMagickException(ExceptionInfo*, const char*, const char*, const char*, const char*, ...);
extern const char *GetMagickModule(void);
extern const char *DelegateWarning;
extern int open_utf8(const char*, int, mode_t);
extern int close(int);
extern ssize_t write(int, const void*, size_t);
extern size_t MagickMax(size_t, size_t);