#include <stdio.h>
#include <errno.h>

typedef enum {
  MagickFalse,
  MagickTrue
} MagickBooleanType;

typedef enum {
  ResourceLimitError,
  FileOpenError
} ExceptionType;

typedef struct _ExceptionInfo {
  int severity;
  char *reason;
  char *description;
  void *exceptions;
} ExceptionInfo;

void ThrowFileException(ExceptionInfo *, ExceptionType, const char *, const char *);
MagickBooleanType ExpandFilenames(int *, char ***);
FILE *fopen_utf8(const char *, const char *);
int remove_utf8(const char *);
const char *GetExceptionMessage(int);