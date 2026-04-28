#include <stddef.h>
#include <sys/types.h>

typedef size_t (*GetMagickResourceLimitType)(int);
extern GetMagickResourceLimitType GetMagickResourceLimit;

typedef void *(*AcquireAlignedMemoryType)(size_t, size_t);
extern AcquireAlignedMemoryType AcquireAlignedMemory;

typedef void (*ThrowFatalExceptionType)(int, const char*);
extern ThrowFatalExceptionType ThrowFatalException;

typedef void (*ResetMagickMemoryType)(void*, int, size_t);
extern ResetMagickMemoryType ResetMagickMemory;

typedef struct _RandomInfo RandomInfo;
typedef RandomInfo* (*AcquireRandomInfoType)(void);
extern AcquireRandomInfoType AcquireRandomInfo;

#define ThreadResource 0
#define ResourceLimitFatalError 0