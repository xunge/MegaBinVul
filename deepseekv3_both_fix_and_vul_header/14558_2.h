#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct JsVar JsVar;
typedef int IOEventFlags;

#define EV_NONE 0
#define DEVICE_IS_I2C(x) (0)
#define SAVE_ON_FLASH
#define DEVICE_OPTIONS_NAME "options"
#define JSV_GET_AS_CHAR_ARRAY(ptr, len, var) char *ptr = NULL; size_t len = 0

typedef struct {
    bool started;
} JshI2CInfo;

int i2c_get_address(JsVar *addressVar, bool *sendStop);
void jshI2CWrite(IOEventFlags device, unsigned char address, int dataLen, unsigned char* dataPtr, bool sendStop);
bool jsi2cPopulateI2CInfo(JshI2CInfo *inf, JsVar *options);
void jsi2cWrite(JshI2CInfo *inf, unsigned char address, int dataLen, unsigned char* dataPtr, bool sendStop);
IOEventFlags jsiGetDeviceFromClass(JsVar *parent);
JsVar *jsvObjectGetChild(JsVar *parent, const char *name, int createIfNotExists);
bool jsvGetBoolAndUnLock(JsVar *var);
JsVar *jsvObjectSetChild(JsVar *parent, const char *name, JsVar *child);
JsVar *jsvNewFromBool(bool value);
void jsvUnLock2(JsVar *var1, JsVar *var2);