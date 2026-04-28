#include <stddef.h>

typedef struct {
  unsigned char host[4];
  unsigned short port;
  size_t length;
} JsNetUDPPacketHeader;

typedef struct JsVar JsVar;
#define JSVAPPENDSTRINGVAR_MAXLENGTH 0
#define DGRAM_NAME_ON_MESSAGE "message"

void jsvGetStringChars(JsVar *v, size_t start, char *buf, size_t bufSize);
size_t jsvGetStringLength(JsVar *v);
JsVar *jsvNewObject();
JsVar *jsvNewFromStringVar(JsVar *v, size_t start, size_t length);
void jsvUnLock(JsVar *v);
void jsvUnLock2(JsVar *v1, JsVar *v2);
JsVar *jsvVarPrintf(const char *fmt, ...);
JsVar *jsvNewFromInteger(int i);
void jsvObjectSetChildAndUnLock(JsVar *parent, const char *name, JsVar *child);
void jsiQueueObjectCallbacks(JsVar *obj, const char *eventName, JsVar **args, int argCount);