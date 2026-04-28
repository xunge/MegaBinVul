#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long Window;
typedef struct _XDisplay Display;
typedef unsigned long Atom;

#define PropModeReplace 0
#define XA_STRING ((Atom) 31)
#define XA_WM_COMMAND ((Atom) 30)

#define safestrlen(s) ((s) ? strlen(s) : 0)
#define Xmalloc malloc
#define Xfree free