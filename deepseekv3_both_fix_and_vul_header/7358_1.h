#include <assert.h>
#include <stdbool.h>

typedef int JsVarInt;
typedef int JsVarRef;

typedef struct JsVar {
    union {
        JsVarInt integer;
    } varData;
} JsVar;

int jsvIsName(JsVar *v);
int jsvIsArray(JsVar *v);
int jsvIsInt(JsVar *v);
JsVarInt jsvGetArrayLength(JsVar *v);
void jsvSetArrayLength(JsVar *v, JsVarInt length, bool b);
JsVarRef jsvGetLastChild(JsVar *v);
JsVar *jsvRef(JsVar *v);
JsVar *jsvLock(JsVarRef ref);
int jsvCompareInteger(JsVar *a, JsVar *b);
JsVarRef jsvGetPrevSibling(JsVar *v);
void jsvUnLock(JsVar *v);
JsVar *jsvLockSafe(JsVarRef ref);
JsVarRef jsvGetNextSibling(JsVar *v);
JsVarRef jsvGetRef(JsVar *v);
void jsvSetPrevSibling(JsVar *v, JsVarRef ref);
void jsvSetNextSibling(JsVar *v, JsVarRef ref);
void jsvSetLastChild(JsVar *v, JsVarRef ref);
JsVarRef jsvGetFirstChild(JsVar *v);
void jsvSetFirstChild(JsVar *v, JsVarRef ref);