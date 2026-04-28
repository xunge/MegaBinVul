#include <stdio.h>
#include <stdlib.h>

typedef struct _XDisplay {
    void **error_vec;
} Display;

typedef int (*WireToErrorType)(Display *, void *);

extern int _XDefaultWireError;
extern int LastExtensionError;
extern void LockDisplay(Display *);
extern void UnlockDisplay(Display *);
extern void *Xmalloc(size_t);