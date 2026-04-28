#include <stddef.h>
#include <assert.h>

typedef struct JsNetwork JsNetwork;
typedef int SocketType;
typedef struct JsVar JsVar;
typedef long long JsVarInt;

#define JSET_ERROR 1

JsVar *jsvNewFromInteger(JsVarInt value);
JsVar *callFn(const char *name, int argCount, JsVar **args);
void jsvUnLockMany(int count, JsVar **vars);
int jsvIsString(JsVar *var);
int jsvIsInt(JsVar *var);
size_t jsvGetStringLength(JsVar *var);
void jsvGetStringChars(JsVar *var, size_t start, char *buf, size_t len);
JsVarInt jsvGetInteger(JsVar *var);
void jsvUnLock(JsVar *var);
void jsExceptionHere(int type, const char *message);

#define NOT_USED(x) (void)(x)