#include <stdint.h>
#include <stdbool.h>

typedef int JsVar;
typedef int Pin;
typedef int IOEventFlags;
typedef int JshSPIInfo;
typedef struct {
    // Minimal iterator structure definition
    JsVar* obj;
    int index;
    int flags;
} JsvIterator;

#define NOT_USED(x) (void)(x)
#define DEVICE_IS_SPI(x) (0)
#define PIN_UNDEFINED (-1)
#define JSET_ERROR (0)
#define JSIF_EVERY_ARRAY_ELEMENT (0)

bool jsvIsNumeric(JsVar* v);
bool jsvIsIterable(JsVar* v);
int jsvGetInteger(JsVar* v);
void jsExceptionHere(int type, const char* msg, ...);
IOEventFlags jsiGetDeviceFromClass(JsVar* parent);
void jshSPISet16(IOEventFlags device, bool is16bit);
bool jshIsDeviceInitialised(IOEventFlags device);
void jshSPIInitInfo(JshSPIInfo* inf);
void jshSPISetup(IOEventFlags device, JshSPIInfo* inf);
void jshSPISetReceive(IOEventFlags device, bool receive);
void jshPinOutput(Pin pin, bool value);
void jsspiSend4bit(IOEventFlags device, unsigned char data, int bit0, int bit1);
void jshInterruptOff();
void jshInterruptOn();
void jshSPIWait(IOEventFlags device);

void jsvIteratorNew(JsvIterator* it, JsVar* obj, int flags);
bool jsvIteratorHasElement(JsvIterator* it);
int jsvIteratorGetIntegerValue(JsvIterator* it);
void jsvIteratorNext(JsvIterator* it);
void jsvIteratorFree(JsvIterator* it);