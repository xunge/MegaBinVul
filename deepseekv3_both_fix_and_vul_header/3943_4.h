#include <stdio.h>

typedef struct _Display Display;
typedef int Status;
typedef unsigned long XID;
typedef XID Window;
typedef struct { int type; } XEvent;
typedef struct { unsigned char pad[24]; } xEvent;

struct _Display {
    Status (**wire_vec)(Display *, XEvent *, xEvent *);
};

typedef Status (*EventToWireType)(Display *, XEvent *, xEvent *);
extern Status _XUnknownNativeEvent(Display *, XEvent *, xEvent *);
extern void LockDisplay(Display *);
extern void UnlockDisplay(Display *);

#define LastExtensionEvent 128