#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define ALOGE(...)
#define ALOGV(...)

extern const char* kCacheDirectoryName;
extern const char* kInstructionSet;
extern int dexOptMkdir(const char* path, mode_t mode);