#include <stdlib.h>
#include <string.h>

typedef unsigned long Atom;

typedef struct _DeviceIntRec {
    struct _PtrFeedbackClassRec *ptrfeed;
    struct _ValuatorClassRec *valuator;
    struct _ButtonClassRec *button;
    struct _ProximityClassRec *proximity;
    struct _TouchClassRec *touch;
    struct _GestureClassRec *gesture;
    struct _ClassesRec *unused_classes;
    int id;
} DeviceIntRec;

typedef struct _ClassesRec {
    struct _PtrFeedbackClassRec *ptrfeed;
    struct _ValuatorClassRec *valuator;
    struct _ButtonClassRec *button;
    struct _ProximityClassRec *proximity;
    struct _TouchClassRec *touch;
    struct _GestureClassRec *gesture;
} ClassesRec;

typedef struct _PtrFeedbackClassRec {
    void (*CtrlProc)(void);
    void *ctrl;
    struct _PtrFeedbackClassRec *next;
} PtrFeedbackClassRec;

typedef struct _ValuatorClassRec {
    int numAxes;
    struct _AxisInfo *axes;
    int sourceid;
} ValuatorClassRec;

typedef struct _AxisInfo {
    // Axis info fields
} AxisInfo;

typedef struct _ButtonClassRec {
    struct _XkbAction *xkb_acts;
    Atom *labels;
    int numButtons;
    int sourceid;
} ButtonClassRec;

typedef struct _XkbAction {
    // Xkb action fields
} XkbAction;

typedef struct _ProximityClassRec {
    int sourceid;
    // Other proximity fields
} ProximityClassRec;

typedef struct _TouchClassRec {
    int num_touches;
    struct _TouchPointInfoRec *touches;
    int max_touches;
    int mode;
    int buttonsDown;
    int state;
    int motionMask;
    int sourceid;
} TouchClassRec;

typedef struct _TouchPointInfoRec {
    // Touch point info fields
} TouchPointInfoRec;

typedef struct _GestureClassRec {
    int max_touches;
    int sourceid;
    // Other gesture fields
} GestureClassRec;

typedef DeviceIntRec *DeviceIntPtr;
typedef ClassesRec *ClassesPtr;
typedef PtrFeedbackClassRec *PtrFeedbackPtr;
typedef ValuatorClassRec *ValuatorClassPtr;
typedef ButtonClassRec *ButtonClassPtr;
typedef ProximityClassRec *ProximityClassPtr;
typedef TouchClassRec *TouchClassPtr;
typedef TouchPointInfoRec *TouchPointInfoPtr;
typedef GestureClassRec *GestureClassPtr;

extern void ErrorF(const char *f, ...);
extern void FatalError(const char *f, ...);
extern ValuatorClassPtr AllocValuatorClass(ValuatorClassPtr v, int numAxes);
extern void TouchInitTouchPoint(TouchClassPtr touch, ValuatorClassPtr valuator, int index);
extern int InitGestureClassDeviceStruct(DeviceIntPtr dev, int max_touches);