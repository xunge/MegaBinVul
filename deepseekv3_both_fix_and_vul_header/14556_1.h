#include <stdint.h>
#include <stdbool.h>

typedef int JsVar;
typedef int Pin;
typedef int IOEventFlags;
typedef int JshSPIInfo;
typedef int JsvIterator;
typedef int JSIF_EVERY_ARRAY_ELEMENT;
typedef int JSET_ERROR;

#define NOT_USED(x) (void)(x)
#define DEVICE_IS_SPI(x) (0)
#define PIN_UNDEFINED (0)
#define JSIF_EVERY_ARRAY_ELEMENT (0)
#define JSET_ERROR (0)

int jsiGetDeviceFromClass(JsVar*);
void jsExceptionHere(int, const char*, ...);
void jshSPISet16(IOEventFlags, bool);
int jshIsDeviceInitialised(IOEventFlags);
void jshSPIInitInfo(JshSPIInfo*);
void jshSPISetup(IOEventFlags, JshSPIInfo*);
void jshSPISetReceive(IOEventFlags, bool);
void jshPinOutput(Pin, bool);
int jsvIsNumeric(JsVar*);
int jsvGetInteger(JsVar*);
void jsspiSend8bit(IOEventFlags, unsigned char, int, int);
int jsvIsIterable(JsVar*);
void jshInterruptOff();
void jsvIteratorNew(JsvIterator*, JsVar*, int);
int jsvIteratorHasElement(JsvIterator*);
int jsvIteratorGetIntegerValue(JsvIterator*);
void jsvIteratorNext(JsvIterator*);
void jsvIteratorFree(JsvIterator*);
void jshInterruptOn();
void jshSPIWait(IOEventFlags);