#include <stdbool.h>

typedef struct JsVar JsVar;
typedef long long JsVarInt;

#define NO_INLINE
#define LEX_R_DELETE 0
#define JSP_SHOULD_EXECUTE 1

struct ExecInfo {
    JsVar *root;
};
extern struct ExecInfo execInfo;

#define JSP_ASSERT_MATCH(x)

JsVar *jspeFactor();
JsVar *jspeFactorMember(JsVar *var, JsVar **parent);
bool jsvIsName(JsVar *var);
bool jsvIsNewChild(JsVar *var);
bool jsvIsChild(JsVar *parent, JsVar *child);
JsVar *jsvLockAgain(JsVar *var);
bool jsvHasChildren(JsVar *var);
bool jsvIsArray(JsVar *var);
JsVarInt jsvGetArrayLength(JsVar *var);
void jsvRemoveChild(JsVar *parent, JsVar *child);
void jsvSetArrayLength(JsVar *var, JsVarInt length, bool updateLength);
JsVar *jsvNewFromBool(bool value);
void jsvUnLock2(JsVar *a, JsVar *b);