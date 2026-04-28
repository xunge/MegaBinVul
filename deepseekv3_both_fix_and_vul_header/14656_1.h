#include <assert.h>
#include <stddef.h>
#include <sys/types.h>

#define MagickExport
#define MagickSignature 0x12345678
#define MaxExceptions 100

typedef enum
{
  WarningException,
  ErrorException,
  FatalErrorException,
  ResourceLimitError
} ExceptionType;

typedef struct _ExceptionInfo
{
  unsigned long signature;
  void *exceptions;
  void *semaphore;
  ExceptionType severity;
  const char *reason;
  const char *description;
} ExceptionInfo;

typedef struct _LinkedListInfo LinkedListInfo;

void LockSemaphoreInfo(void *semaphore);
void UnlockSemaphoreInfo(void *semaphore);
void ResetLinkedListIterator(LinkedListInfo *);
void *GetNextValueInLinkedList(LinkedListInfo *);
void MagickFatalError(ExceptionType, const char *, const char *);
void MagickError(ExceptionType, const char *, const char *);
void MagickWarning(ExceptionType, const char *, const char *);
void ClearMagickException(ExceptionInfo *);