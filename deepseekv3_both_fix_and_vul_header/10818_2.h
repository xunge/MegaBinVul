#include <stdlib.h>
#include <string.h>

#define MagickExport

typedef enum {
    StringRegistryType,
    ImageRegistryType,
    ImageInfoRegistryType
} RegistryType;

typedef unsigned int MagickBooleanType;
#define MagickFalse 0
#define MagickTrue 1

typedef struct _ExceptionInfo ExceptionInfo;

typedef struct _Image {
    unsigned long signature;
    /* other members omitted */
} Image;

typedef struct _ImageInfo {
    unsigned long signature;
    /* other members omitted */
} ImageInfo;

typedef struct _RegistryInfo {
    RegistryType type;
    void *value;
    unsigned long signature;
    /* other members omitted */
} RegistryInfo;

typedef struct _SplayTreeInfo SplayTreeInfo;
typedef struct _SemaphoreInfo SemaphoreInfo;

#define MagickSignature 0x1234
#define ResourceLimitFatalError 1
#define RegistryError 2
#define TraceEvent 3

extern SplayTreeInfo *registry;
extern SemaphoreInfo *registry_semaphore;

MagickBooleanType IsEventLogging(void);
void *AcquireMagickMemory(size_t);
void *ResetMagickMemory(void *, int, size_t);
void *ConstantString(const char *);
void *CloneImageList(const Image *, ExceptionInfo *);
void *CloneImageInfo(const ImageInfo *);
void *NewSplayTree(int (*)(const void *, const void *), void *(*)(void *), void (*)(void *));
int CompareSplayTreeString(const void *, const void *);
void *RelinquishMagickMemory(void *);
void DestroyRegistryNode(void *);
MagickBooleanType AddValueToSplayTree(SplayTreeInfo *, const void *, void *);
void ActivateSemaphoreInfo(SemaphoreInfo **);
void LockSemaphoreInfo(SemaphoreInfo *);
void UnlockSemaphoreInfo(SemaphoreInfo *);
void ThrowFatalException(int, const char *);
void LogMagickEvent(int, const char *, const char *, ...);
void *ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
const char *GetMagickModule(void);