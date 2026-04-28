#include <stdint.h>
#include <stddef.h>

typedef int IOEventFlags;
typedef int JshPinState;
typedef int JshPin;

#define PIN_UNDEFINED 0
#define EV_NONE 0
#define JSHPINSTATE_GPIO_OUT_OPENDRAIN_PULLUP 0
#define I2C_SLAVE
#define SAVE_ON_FLASH
#define DEVICE_OPTIONS_NAME "options"
#define DEVICE_IS_I2C(x) (0)

typedef struct {
    int slaveAddr;
    JshPin pinSCL;
    JshPin pinSDA;
} JshI2CInfo;

typedef struct JsVar JsVar;

enum {
    ARRAYBUFFERVIEW_UINT8,
    JSET_ERROR
};

extern JsVar *jsvNewTypedArray(int type, size_t size);
extern void jshPinSetValue(JshPin pin, int value);
extern void jshPinSetState(JshPin pin, JshPinState state);
extern void jshI2CSetup(IOEventFlags device, JshI2CInfo *inf);
extern int jsi2cPopulateI2CInfo(JshI2CInfo *inf, JsVar *options);
extern IOEventFlags jsiGetDeviceFromClass(JsVar *parent);
extern void jsExceptionHere(int type, const char *message);
extern void jsvObjectSetChildAndUnLock(JsVar *parent, const char *name, JsVar *child);
extern void jsvUnLock(JsVar *var);
extern JsVar *jsvSetNamedChild(JsVar *parent, JsVar *child, const char *name);
extern void jsvObjectRemoveChild(JsVar *parent, const char *name);