#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MagickPrivate
#define MaxTextExtent 4096
#define DirectorySeparator "/"
#undef MAGICKCORE_WINDOWS_SUPPORT

typedef enum { MagickFalse, MagickTrue } MagickBooleanType;

typedef struct _SemaphoreInfo SemaphoreInfo;
extern SemaphoreInfo *openclCachedFilesDirectoryLock;
extern char *openclCachedFilesDirectory;

char* GetEnvironmentValue(const char *);
void ActivateSemaphoreInfo(SemaphoreInfo **);
void LockSemaphoreInfo(SemaphoreInfo *);
void UnlockSemaphoreInfo(SemaphoreInfo *);
MagickBooleanType GetPathAttributes(const char *, struct stat *);
char* FormatLocaleString(char *, size_t, const char *, ...);
void* AcquireMagickMemory(size_t);
char* CopyMagickString(char *, const char *, size_t);
char* DestroyString(char *);