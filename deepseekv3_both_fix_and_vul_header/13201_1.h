#include <stdbool.h>

typedef struct JsVar {
    unsigned int flags;
} JsVar;

typedef struct JsvObjectIterator {
    // Placeholder for iterator implementation
    void *data;
} JsvObjectIterator;

#define JSET_TYPEERROR 0
#define JSV_NATIVE 0x1
#define JSV_VARTYPEMASK 0xF
#define JSV_FUNCTION_RETURN 0x2
#define JSV_FUNCTION 0x4

#define JSPARSE_FUNCTION_SCOPE_NAME "scope"
#define JSPARSE_PROTOTYPE_VAR "prototype"

bool jsvIsFunction(JsVar *v);
bool jsvIsNativeFunction(JsVar *v);
bool jsvIsFunctionReturn(JsVar *v);
void jsExceptionHere(int type, const char *message);
JsVar *jsvFindChildFromString(JsVar *parent, const char *name, bool createIfNotFound);
void jsvRemoveAllChildren(JsVar *parent);
void jsvObjectIteratorNew(JsvObjectIterator *it, JsVar *obj);
bool jsvObjectIteratorHasValue(JsvObjectIterator *it);
JsVar *jsvObjectIteratorGetKey(JsvObjectIterator *it);
void jsvObjectIteratorNext(JsvObjectIterator *it);
void jsvObjectIteratorFree(JsvObjectIterator *it);
bool jsvIsStringEqual(JsVar *v, const char *str);
JsVar *jsvCopy(JsVar *v, bool recursive);
void jsvAddName(JsVar *parent, JsVar *child);
void jsvUnLock(JsVar *v);