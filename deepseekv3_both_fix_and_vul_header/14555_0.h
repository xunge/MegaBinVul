#include <stdint.h>

typedef uint32_t IOEventFlags;
typedef uint32_t JsVar;
typedef uint32_t Pin;

#define PIN_UNDEFINED 0
#define EV_NONE 0
#define DEVICE_IS_SPI(x) (0)
#define DEVICE_OPTIONS_NAME "_options"

typedef struct {
    Pin pinSCK;
    Pin pinMISO;
    Pin pinMOSI;
} JshSPIInfo;

enum {
    JSHPINSTATE_GPIO_IN,
    JSHPINSTATE_GPIO_OUT
};

JsVar *jsvObjectSetChildAndUnLock(JsVar *parent, const char *name, JsVar *child);
JsVar *jsvObjectGetChild(JsVar *obj, const char *name, int createIfNotFound);
int jsvIsObject(JsVar *v);
void jshPinSetState(Pin pin, int state);
void jshSPISetup(IOEventFlags device, JshSPIInfo *inf);
int jsspiPopulateSPIInfo(JshSPIInfo *inf, JsVar *options);
IOEventFlags jsiGetDeviceFromClass(JsVar *parent);
JsVar *jsvSetNamedChild(JsVar *parent, JsVar *child, const char *name);
void jsvObjectRemoveChild(JsVar *parent, const char *name);
void jsvUnLock(JsVar *var);