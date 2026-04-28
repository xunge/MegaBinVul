#include <stdio.h>

typedef int (*WireToEventCookieType)();

struct _Display {
    WireToEventCookieType generic_event_vec[128];
};
typedef struct _Display Display;

#define FirstExtensionRequest 128
#define LastExtensionRequest 255
extern int _XUnknownWireEventCookie;

void LockDisplay(Display *dpy);
void UnlockDisplay(Display *dpy);