#include <stdbool.h>

typedef int IOEventFlags;
typedef int JshPinState;
typedef int JshPin;

#define PIN_UNDEFINED (-1)
#define JSHPINSTATE_GPIO_OUT 0
#define JSHPINSTATE_GPIO_IN_PULLUP 1
#define EV_NONE 0
#define LINUX 0
#define SAVE_ON_FLASH 0
#define USART_BAUDRATE_NAME "baudrate"
#define DEVICE_OPTIONS_NAME "options"
#define JSET_ERROR 0

typedef struct {
    int baudRate;
    JshPin pinTX;
    JshPin pinRX;
    JshPin pinCK;
} JshUSARTInfo;

typedef struct JsVar JsVar;

IOEventFlags jsiGetDeviceFromClass(JsVar *parent);
bool jsserialPopulateUSARTInfo(JshUSARTInfo *inf, JsVar *baud, JsVar *options);
void jshUSARTSetup(IOEventFlags device, JshUSARTInfo *inf);
void jshPinSetState(JshPin pin, JshPinState state);
void jshPinOutput(JshPin pin, int value);
void jsserialEventCallbackInit(JsVar *parent, JshUSARTInfo *inf);
void jsExceptionHere(int type, const char *message);
JsVar *jsvObjectGetChild(JsVar *parent, const char *name, int createIfNotFound);
void jsvObjectSetChildAndUnLock(JsVar *parent, const char *name, JsVar *child);
void jsvObjectRemoveChild(JsVar *parent, const char *name);
JsVar *jsvNewFromInteger(int value);
bool jsvIsUndefined(JsVar *var);
bool jsvIsObject(JsVar *var);
void jsvUnLock(JsVar *var);
void jsvLockAgain(JsVar *var);
bool DEVICE_IS_SERIAL(IOEventFlags device);
bool DEVICE_IS_USART(IOEventFlags device);