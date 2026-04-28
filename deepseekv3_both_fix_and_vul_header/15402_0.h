#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _DeviceIntRec *DeviceIntPtr;
typedef uint32_t Time;
typedef uint32_t Atom;

struct _DeviceIntRec {
    struct _ButtonClassRec *button;
    struct _ValuatorClassRec *valuator;
    struct _KeyClassRec *key;
    int id;
    struct _DeviceIntRec *next;
    void *xkb_acts;
};

struct _InputInfo {
    DeviceIntPtr devices;
};

struct _ButtonClassRec {
    int numButtons;
    Atom *labels;
    void *xkb_acts;
};

struct _ValuatorClassRec {
    int numAxes;
    struct {
        double min_value;
        double max_value;
        double resolution;
        int mode;
        Atom label;
    } *axes;
};

struct _KeyClassRec {
    struct _XkbInfoRec *xkbInfo;
};

struct _XkbInfoRec {
    struct _XkbDescRec *desc;
};

struct _XkbDescRec {
    int min_key_code;
    int max_key_code;
};

typedef struct {
    int header;
    int type;
    Time time;
    int deviceid;
    int flags;
    struct {
        int num_buttons;
        Atom names[256];
    } buttons;
    int num_valuators;
    struct {
        double min;
        double max;
        double resolution;
        int mode;
        Atom name;
    } valuators[256];
    struct {
        int min_keycode;
        int max_keycode;
    } keys;
} DeviceChangedEvent;

typedef struct {
    int dummy;
} XkbAction;

extern struct _InputInfo inputInfo;

#define MASTER_POINTER 0
#define MASTER_ATTACHED 1
#define ET_Internal 0
#define ET_DeviceChanged 0
#define DEVCHANGE_POINTER_EVENT 0
#define DEVCHANGE_DEVICE_CHANGE 0

#define max(a,b) ((a) > (b) ? (a) : (b))

static int IsMaster(DeviceIntPtr dev);
static DeviceIntPtr GetMaster(DeviceIntPtr dev, int type);
static Time GetTimeInMillis(void);
static void XISendDeviceChangedEvent(DeviceIntPtr dev, DeviceChangedEvent *event);
static void *xnfreallocarray(void *ptr, size_t nmemb, size_t size);