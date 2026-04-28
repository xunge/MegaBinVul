#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t Pin;
#define PIN_UNDEFINED ((Pin)0xFFFFFFFF)

typedef struct JsvArrayBufferIterator {
    // Dummy structure definition since actual implementation is not available
    void *data;
    size_t index;
} JsvArrayBufferIterator;

typedef struct JsvStringIterator {
    // Dummy structure definition since actual implementation is not available
    void *data;
    size_t position;
} JsvStringIterator;

typedef struct {
    void (*spiSend)(const unsigned char *tx, unsigned char *rx, size_t len, void *data);
    void *spiSendData;
    size_t rxAmt;
    size_t txAmt;
    JsvArrayBufferIterator it;
} jswrap_spi_send_data;

typedef struct JsVar JsVar;

typedef enum {
    ARRAYBUFFERVIEW_UINT8
} JsVarArrayBufferViewType;

typedef unsigned int IOEventFlags;

#define NOT_USED(x) (void)(x)

typedef void (*jsvIterateBufferCallbackFn)(void *userData, JsVar *value, size_t index);
void jswrap_spi_send_cb(void *userData, JsVar *value, size_t index);

bool DEVICE_IS_SPI(IOEventFlags device);
IOEventFlags jsiGetDeviceFromClass(JsVar *parent);
bool jsspiGetSendFunction(JsVar *parent, void (**spiSend)(const unsigned char *, unsigned char *, size_t, void *), void **spiSendData);
void jshSPISetReceive(IOEventFlags device, bool enabled);
void jshPinOutput(Pin pin, bool value);
JsVar *jsvNewFromInteger(int value);
JsVar *jsvNewFromEmptyString();
JsVar *jsvNewTypedArray(JsVarArrayBufferViewType type, int length);
bool jsvIsNumeric(JsVar *var);
bool jsvIsString(JsVar *var);
int jsvGetInteger(JsVar *var);
void jsvStringIteratorNew(JsvStringIterator *it, JsVar *str, size_t startIdx);
bool jsvStringIteratorHasChar(JsvStringIterator *it);
void jsvStringIteratorGetPtrAndNext(JsvStringIterator *it, unsigned char **data, unsigned int *len);
void jsvStringIteratorFree(JsvStringIterator *it);
void jsvAppendStringBuf(JsVar *dst, const char *data, size_t len);
int jsvIterateCallbackCount(JsVar *var);
void jsvArrayBufferIteratorNew(JsvArrayBufferIterator *it, JsVar *arrayBuffer, size_t index);
void jsvArrayBufferIteratorFree(JsvArrayBufferIterator *it);
void jsvIterateBufferCallback(JsVar *var, jsvIterateBufferCallbackFn callback, void *userData);
bool jspIsInterrupted();