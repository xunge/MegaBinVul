#include <stdbool.h>
#include <string.h>

#define NO_INLINE
#define JSPARSE_PROTOTYPE_VAR "prototype"
#define JSPARSE_CONSTRUCTOR_VAR "constructor"
#define JSPARSE_INHERITS_VAR "__proto__"

typedef struct JsVar JsVar;

extern JsVar *jspeiFindChildFromStringInParents(JsVar *object, const char* name);
extern JsVar *jswFindBuiltInFunction(JsVar *object, const char* name);
extern bool jsvIsName(JsVar *var);
extern JsVar *jsvGetValueOfName(JsVar *var);
extern void jsvUnLock(JsVar *var);
extern void jsvUnLock2(JsVar *var1, JsVar *var2);
extern JsVar *jsvNewFromString(const char *str);
extern JsVar *jsvCreateNewChild(JsVar *parent, JsVar *name, JsVar *child);
extern bool jsvIsFunction(JsVar *var);
extern JsVar *jsvNewObject();
extern void jsvObjectSetChild(JsVar *parent, const char *name, JsVar *child);
extern JsVar *jsvAddNamedChild(JsVar *parent, JsVar *child, const char *name);
extern void jspEnsureIsPrototype(JsVar *func, JsVar *proto);
extern const char *jswGetBasicObjectName(JsVar *object);
extern JsVar *jspNewPrototype(const char *name);