#include <assert.h>
#include <stddef.h>
#include <stdbool.h>

typedef unsigned short JsVarRef;
typedef struct JsVar JsVar;

#define ALWAYS_INLINE inline __attribute__((always_inline))
#define JSV_UNUSED 0
#define CLEAR_MEMORY_ON_FREE

extern JsVarRef jsVarFirstEmpty;
extern bool touchedFreeList;

struct JsVar {
    unsigned int flags;
    JsVarRef nextSibling;
    JsVarRef prevSibling;
    JsVarRef firstChild;
    JsVarRef lastChild;
};

JsVar* jsvGetAddressOf(JsVarRef ref);
JsVarRef jsvGetRef(JsVar* var);
JsVarRef jsvGetNextSibling(JsVar* var);
JsVarRef jsvGetPrevSibling(JsVar* var);
JsVarRef jsvGetFirstChild(JsVar* var);
JsVarRef jsvGetLastChild(JsVar* var);
void jsvSetNextSibling(JsVar* var, JsVarRef ref);
void jsvSetPrevSibling(JsVar* var, JsVarRef ref);
void jsvSetFirstChild(JsVar* var, JsVarRef ref);
void jsvSetLastChild(JsVar* var, JsVarRef ref);
int jsvIsRefUsedForData(JsVar* var);
int jsvIsName(JsVar* var);
int jsvIsNameWithValue(JsVar* var);
int jsvHasSingleChild(JsVar* var);
int jsvHasStringExt(JsVar* var);
int jsvIsStringExt(JsVar* var);
int jsvIsFlatString(JsVar* var);
size_t jsvGetFlatStringBlocks(JsVar* var);
int jsvIsBasicString(JsVar* var);
int jsvHasChildren(JsVar* var);
int jsvIsFloat(JsVar* var);
void jsvFreePtrInternal(JsVar* var);
JsVar* jsvLock(JsVarRef ref);
void jsvUnLock(JsVar* var);
void jsvUnRef(JsVar* var);
void jsvUnRefRef(JsVarRef ref);
int jsuGetFreeStack();
void jshInterruptOff();
void jshInterruptOn();