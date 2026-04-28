#include <assert.h>
#include <errno.h>
#include <string.h>

typedef enum {
  MagickImageCoderModule,
  MagickImageFilterModule
} MagickModuleType;

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef struct _ExceptionInfo {
  int severity;
} ExceptionInfo;

enum {
  TraceEvent,
  ModuleEvent
};

enum {
  PolicyError,
  ConfigureError,
  ConfigureWarning
};

#define MaxTextExtent 4096
#define DirectoryListSeparator ':'
#define DirectorySeparator "/"

#define MAGICKCORE_INSTALLED_SUPPORT
#define MAGICKCORE_CODER_PATH ""
#define MAGICKCORE_FILTER_PATH ""
#define MAGICKCORE_WINDOWS_SUPPORT
#define MAGICKCORE_POSIX_SUPPORT
#define MAGICKCORE_CODER_RELATIVE_PATH ""
#define MAGICKCORE_FILTER_RELATIVE_PATH ""
#define MAGICKCORE_MODULES_RELATIVE_PATH ""

char *GetEnvironmentValue(const char *);
char *AcquireString(const char *);
char *DestroyString(char *);
void *RelinquishMagickMemory(void *);
void LogMagickEvent(int, const char *, const char *, ...);
const char *GetMagickModule(void);
void CopyMagickString(char *, const char *, size_t);
void ConcatenateMagickString(char *, const char *, size_t);
void FormatLocaleString(char *, size_t, const char *, ...);
MagickBooleanType IsPathAccessible(const char *);
void ThrowMagickException(ExceptionInfo *, const char *, int, const char *, const char *, ...);
void ThrowFileException(ExceptionInfo *, int, const char *, const char *);
const char *GetClientPath(void);
void ChopPathComponents(char *, int);
MagickBooleanType NTGetModulePath(const char *, char *);
unsigned char *NTRegistryKeyLookup(const char *);