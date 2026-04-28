#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

#define MagickCoreSignature 0
#define MaxExceptions 0

typedef enum {
    WarningException,
    ErrorException,
    FatalErrorException,
    ResourceLimitError
} ExceptionSeverity;

typedef struct _ExceptionInfo {
    unsigned long signature;
    void *exceptions;
    void *semaphore;
    ExceptionSeverity severity;
    char *reason;
    char *description;
} ExceptionInfo;

typedef struct _LinkedListInfo LinkedListInfo;
typedef struct _SemaphoreInfo SemaphoreInfo;

#define MagickExport

void LockSemaphoreInfo(SemaphoreInfo *);
void UnlockSemaphoreInfo(SemaphoreInfo *);
void ResetLinkedListIterator(LinkedListInfo *);
void *GetNextValueInLinkedList(LinkedListInfo *);
void MagickWarning(ExceptionSeverity, const char *, const char *);
void MagickError(ExceptionSeverity, const char *, const char *);
void MagickFatalError(ExceptionSeverity, const char *, const char *);
void ClearMagickException(ExceptionInfo *);