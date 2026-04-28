#include <stdint.h>
#include <stdbool.h>

typedef int IOEventFlags;
typedef int JsVar;
typedef int Pin;

#define PIN_UNDEFINED 0
#define JSHPINSTATE_UNDEFINED 0
#define DEVICE_OPTIONS_NAME ""
#define USART_BAUDRATE_NAME ""
#define DEVICE_IS_SERIAL(x) (0)

typedef struct {
    Pin pinCK;
    Pin pinCTS;
    Pin pinRX;
    Pin pinTX;
} JshUSARTInfo;

IOEventFlags jsiGetDeviceFromClass(JsVar *parent);
JsVar *jsvObjectGetChild(JsVar *parent, const char *name, int createIfNotExists);
void jsserialPopulateUSARTInfo(JshUSARTInfo *inf, JsVar *baud, JsVar *options);
void jshPinSetState(Pin pin, int state);
void jsserialEventCallbackKill(JsVar *parent, JshUSARTInfo *inf);
void jsvUnLock2(JsVar *a, JsVar *b);
void jsvObjectRemoveChild(JsVar *parent, const char *name);
void jshUSARTUnSetup(IOEventFlags device);
void jshSetFlowControlEnabled(IOEventFlags device, bool enabled, Pin pin);