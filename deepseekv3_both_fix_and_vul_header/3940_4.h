#include <stdio.h>

typedef struct _Display Display;
typedef struct _XEvent XEvent;
typedef struct _xEvent xEvent;

typedef int (*WireToEventType)(Display*, XEvent*, xEvent*);

struct _Display {
    WireToEventType *event_vec;
};

extern WireToEventType _XUnknownWireEvent;
extern int LastExtensionEvent;

void LockDisplay(Display*);
void UnlockDisplay(Display*);