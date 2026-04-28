#include <stdbool.h>
#include <assert.h>

typedef int JsVarRef;
typedef int JsVarInt;

typedef struct JsVar {
    // 假设的结构体成员，根据实际使用情况可能需要调整
    JsVarRef firstChild;
    JsVarRef lastChild;
    JsVarRef prevSibling;
    JsVarRef nextSibling;
} JsVar;

bool jsvHasChildren(JsVar *v);
bool jsvIsName(JsVar *v);
bool jsvIsArray(JsVar *v);
JsVarRef jsvGetRef(JsVar *v);
JsVarRef jsvGetFirstChild(JsVar *v);
JsVarRef jsvGetLastChild(JsVar *v);
JsVarRef jsvGetPrevSibling(JsVar *v);
JsVarRef jsvGetNextSibling(JsVar *v);
void jsvSetFirstChild(JsVar *v, JsVarRef ref);
void jsvSetLastChild(JsVar *v, JsVarRef ref);
JsVar *jsvLock(JsVarRef ref);
void jsvUnLock(JsVar *v);
JsVarInt jsvGetIntegerAndUnLock(JsVar *v);
void jsvSetArrayLength(JsVar *v, JsVarInt length, bool update);
void jsvSetPrevSibling(JsVar *v, JsVarRef ref);
void jsvSetNextSibling(JsVar *v, JsVarRef ref);
void jsvUnRef(JsVar *v);