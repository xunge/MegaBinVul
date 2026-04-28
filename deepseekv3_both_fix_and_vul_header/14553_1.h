#include <stdint.h>
#include <stdbool.h>

typedef int JsVarInt;
typedef void JsVar;
typedef unsigned int IOEventFlags;
typedef int Pin;

#define PIN_UNDEFINED (-1)
#define NOT_USED(x) (void)(x)
#define DEVICE_IS_SPI(x) (0)

typedef struct {
    void (*spiSend)(void*);
    void* spiSendData;
} spi_sender;

typedef struct {
    void* data;
} spi_sender_data;

typedef struct {
    spi_sender spiSend;
    spi_sender_data spiSendData;
} jswrap_spi_write_data;

typedef void (*jsvIterateBufferCallbackFn)(void*, void*);

int jsvIsPin(JsVar*);
Pin jshGetPinFromVar(JsVar*);
JsVar* jsvGetArrayItem(JsVar*, JsVarInt);
JsVarInt jsvGetArrayLength(JsVar*);
void jsvUnLock(JsVar*);
JsVar* jsvArrayPop(JsVar*);
IOEventFlags jsiGetDeviceFromClass(JsVar*);
int jsspiGetSendFunction(JsVar*, spi_sender*, spi_sender_data*);
void jshPinOutput(Pin, bool);
void jshSPISetReceive(IOEventFlags, bool);
void jshSPIWait(IOEventFlags);
void jsvIterateBufferCallback(JsVar*, jsvIterateBufferCallbackFn, void*);
void jswrap_spi_write_cb(void*, void*);