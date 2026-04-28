#include <stdbool.h>
#include <stdlib.h>

typedef struct JsVar JsVar;
typedef struct LexToken {
    int tk;
} LexToken;
typedef struct ExecInfo {
    JsVar *thisVar;
    JsVar *currentClassConstructor;
} ExecInfo;

extern LexToken *lex;
extern ExecInfo execInfo;

#define NO_INLINE
#define LEX_R_NEW 0
#define LEX_R_SUPER 0
#define JSPARSE_PROTOTYPE_VAR ""
#define JSPARSE_INHERITS_VAR ""
#define JSPARSE_CONSTRUCTOR_VAR ""
#define JSP_SHOULD_EXECUTE 0
#define ESPR_NO_CLASSES
#define ESPR_NO_GET_SET
#define JSET_ERROR 0
#define JSET_SYNTAXERROR 0

#define JSP_ASSERT_MATCH(x)
#define jsvIsObject(x) false
#define jsvIsFunction(x) false
#define jsvLockAgain(x) NULL
#define jsvUnLock(x)
#define jsvUnLock2(x,y)
#define jsvUnLock3(x,y,z)
#define jsvObjectGetChildIfExists(x,y) NULL
#define jsvIsBasicName(x) false
#define jsvIsNewChild(x) false
#define jsvGetFirstChild(x) NULL
#define jsvIsGetterOrSetter(x) false
#define jsvCopyNameOnly(x,y,z) NULL
#define jsvCreateNewChild(x,y,z) NULL
#define jsvLockSafe(x) NULL
#define jsvSkipName(x) NULL
#define jsExceptionHere(x,y)
#define jspSetError(x)
#define jspIsInterrupted() false

JsVar *jspeFactor();
JsVar *jspeFactorMember(JsVar *a, JsVar **parent);
JsVar *jspeConstruct(JsVar *func, JsVar *funcName, bool parseArgs);
JsVar *jspeFunctionCall(JsVar *func, JsVar *funcName, JsVar *parent, bool b, int x, int y);