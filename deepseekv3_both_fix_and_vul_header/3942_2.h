#include <stdio.h>

typedef void (*CopyEventCookieType)();

typedef struct _XDisplay {
    void *generic_event_copy_vec[128];
} Display;

extern int FirstExtensionRequest;
extern int LastExtensionRequest;
extern void _XUnknownCopyEventCookie();

#define LockDisplay(dpy)
#define UnlockDisplay(dpy)