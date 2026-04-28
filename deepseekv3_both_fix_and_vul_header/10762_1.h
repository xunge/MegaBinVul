#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>

#define MagickExport
#define MaxTextExtent 4096

extern double StringToDouble(const char *, char **);
extern int LocaleNCompare(const char *, const char *, size_t);
extern char *CopyMagickString(char *, const char *, size_t);
extern const char *DirectorySeparator;