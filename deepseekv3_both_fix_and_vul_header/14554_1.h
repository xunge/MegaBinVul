#include <stdbool.h>
#include <stdlib.h>
#include <alloca.h>

typedef int IOEventFlags;
typedef struct JsVar JsVar;
typedef struct JshI2CInfo {
    bool started;
} JshI2CInfo;
typedef struct JsvArrayBufferIterator {
    // Minimal definition to make it compile
    JsVar *array;
    size_t index;
} JsvArrayBufferIterator;

#define DEVICE_IS_I2C(x) (0)
#define EV_NONE 0
#define DEVICE_OPTIONS_NAME ""
#define SAVE_ON_FLASH
#define JSET_ERROR 0
#define ARRAYBUFFERVIEW_UINT8 0

IOEventFlags jsiGetDeviceFromClass(JsVar *parent);
int i2c_get_address(JsVar *addressVar, bool *sendStop);
unsigned int jsuGetFreeStack(void);
void jsExceptionHere(int type, const char *message);
void jshI2CRead(IOEventFlags device, unsigned char address, int nBytes, unsigned char *buf, bool sendStop);
bool jsi2cPopulateI2CInfo(JshI2CInfo *inf, JsVar *options);
void jsi2cRead(JshI2CInfo *inf, unsigned char address, int nBytes, unsigned char *buf, bool sendStop);
JsVar *jsvNewTypedArray(int type, int length);
void jsvArrayBufferIteratorNew(JsvArrayBufferIterator *it, JsVar *array, int index);
void jsvArrayBufferIteratorSetByteValue(JsvArrayBufferIterator *it, char value);
void jsvArrayBufferIteratorNext(JsvArrayBufferIterator *it);
void jsvArrayBufferIteratorFree(JsvArrayBufferIterator *it);
JsVar *jsvObjectGetChild(JsVar *parent, const char *name, int flags);
bool jsvGetBoolAndUnLock(JsVar *var);
JsVar *jsvObjectSetChild(JsVar *parent, const char *name, JsVar *child);
JsVar *jsvNewFromBool(bool value);
void jsvUnLock2(JsVar *var1, JsVar *var2);