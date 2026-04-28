#include <stdbool.h>
#include <stddef.h>

typedef struct JsVar JsVar;
typedef struct JsvIterator JsvIterator;
typedef unsigned int JsVarFlags;

#define JSV_LOCK_MASK 0
#define JSIF_DEFINED_ARRAY_ElEMENTS 0

struct JsVar {
    union {
        int integer;
        struct {
            void *ptr;
            int argTypes;
        } native;
    } varData;
    JsVar *firstChild;
    JsVar *lastChild;
    JsVarFlags flags;
};

struct JsvIterator {
    JsVar *var;
    int flags;
};

void jsiConsolePrint(const char *str);
void jsiConsolePrintf(const char *fmt, ...);
void jsvTraceLockInfo(JsVar *var);
int _jsvTraceGetLowestLevel(JsVar *baseVar, JsVar *var);
bool jsvIsName(JsVar *var);
bool jsvIsObject(JsVar *var);
bool jsvIsArray(JsVar *var);
bool jsvIsNativeFunction(JsVar *var);
bool jsvIsFunction(JsVar *var);
bool jsvIsFunctionReturn(JsVar *var);
bool jsvIsPin(JsVar *var);
int jsvGetInteger(JsVar *var);
bool jsvIsInt(JsVar *var);
bool jsvIsBoolean(JsVar *var);
bool jsvGetBool(JsVar *var);
bool jsvIsFloat(JsVar *var);
double jsvGetFloat(JsVar *var);
bool jsvIsFunctionParameter(JsVar *var);
bool jsvIsArrayBufferName(JsVar *var);
bool jsvIsArrayBuffer(JsVar *var);
const char *jswGetBasicObjectName(JsVar *var);
bool jsvIsString(JsVar *var);
JsVar *jsvLock(JsVar *var);
void jsvUnLock(JsVar *var);
int jsvCountJsVarsUsed(JsVar *var);
bool jsvIsFlatString(JsVar *var);
int jsvGetFlatStringBlocks(JsVar *var);
bool jsvIsNativeString(JsVar *var);
bool jsvIsNameInt(JsVar *var);
int jsvGetFirstChildSigned(JsVar *var);
bool jsvIsNameIntBool(JsVar *var);
JsVar *jsvGetFirstChild(JsVar *var);
bool jsvHasSingleChild(JsVar *var);
bool jsvHasChildren(JsVar *var);
void jsvIteratorNew(JsvIterator *it, JsVar *var, int flags);
bool jsvIteratorHasElement(JsvIterator *it);
bool jspIsInterrupted(void);
JsVar *jsvIteratorGetKey(JsvIterator *it);
void jsvIteratorNext(JsvIterator *it);
void jsvIteratorFree(JsvIterator *it);