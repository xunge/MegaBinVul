#include <stddef.h>

#define NO_INLINE
#define JSV_FUNCTION 0
#define JSLEX_MAX_TOKEN_LENGTH 255

typedef struct JsVar JsVar;

JsVar *jsvNewWithFlags(int flags);
size_t jsvGetString(JsVar *var, char *buf, size_t bufSize);
JsVar *jsvAddNamedChild(JsVar *parent, int index, const char *name);
void jsvMakeFunctionParameter(JsVar *var);
void jsvUnLock(JsVar *var);