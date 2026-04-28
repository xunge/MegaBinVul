#include <stdlib.h>
#include <string.h>

typedef struct _PtrFeedbackClassRec PtrFeedbackClassRec;
typedef struct _ValuatorClassRec ValuatorClassRec;
typedef struct _AxisInfo AxisInfo;
typedef struct _ButtonClassRec ButtonClassRec;
typedef struct _XkbAction XkbAction;
typedef struct _ProximityClassRec ProximityClassRec;
typedef struct _TouchClassRec TouchClassRec;
typedef struct _TouchPointInfoRec TouchPointInfoRec;
typedef struct _GestureClassRec GestureClassRec;
typedef struct _ClassesRec ClassesRec;
typedef struct _DeviceIntRec DeviceIntRec;

typedef PtrFeedbackClassRec *PtrFeedbackPtr;
typedef ValuatorClassRec *ValuatorClassPtr;
typedef ButtonClassRec *ButtonClassPtr;
typedef ProximityClassRec *ProximityClassPtr;
typedef TouchClassRec *TouchClassPtr;
typedef TouchPointInfoRec *TouchPointInfoPtr;
typedef ClassesRec *ClassesPtr;
typedef DeviceIntRec *DeviceIntPtr;
typedef unsigned long Atom;

struct _PtrFeedbackClassRec {
    void (*CtrlProc)();
    void *ctrl;
    PtrFeedbackPtr next;
};

struct _ValuatorClassRec {
    int numAxes;
    AxisInfo *axes;
    int sourceid;
};

struct _AxisInfo {
    int min_value;
    int max_value;
    int resolution;
};

struct _ButtonClassRec {
    Atom *labels;
    int numButtons;
    XkbAction *xkb_acts;
    int sourceid;
};

struct _XkbAction {
    unsigned char type;
    unsigned char data[7];
};

struct _ProximityClassRec {
    int sourceid;
    int proximity_state;
};

struct _TouchClassRec {
    int num_touches;
    int max_touches;
    int mode;
    int buttonsDown;
    int state;
    int motionMask;
    TouchPointInfoPtr touches;
    int sourceid;
};

struct _TouchPointInfoRec {
    int touchid;
    int status;
    int x;
    int y;
};

struct _GestureClassRec {
    int max_touches;
    int sourceid;
};

struct _ClassesRec {
    PtrFeedbackPtr ptrfeed;
    ValuatorClassPtr valuator;
    ButtonClassPtr button;
    ProximityClassPtr proximity;
    TouchClassPtr touch;
    void *gesture;
};

struct _DeviceIntRec {
    PtrFeedbackPtr ptrfeed;
    ValuatorClassPtr valuator;
    ButtonClassPtr button;
    ProximityClassPtr proximity;
    TouchClassPtr touch;
    GestureClassRec *gesture;
    ClassesPtr unused_classes;
    int id;
};

extern void ErrorF(const char *fmt, ...);
extern void FatalError(const char *fmt, ...);
extern ValuatorClassPtr AllocValuatorClass(ValuatorClassPtr, int);
extern void TouchInitTouchPoint(TouchClassPtr, ValuatorClassPtr, int);
extern int InitGestureClassDeviceStruct(DeviceIntPtr, int);