#include <stddef.h>
#include <stdbool.h>

typedef struct JsVar JsVar;
typedef struct JsvStringIterator JsvStringIterator;
typedef struct LexToken {
    int tk;
} LexToken;
typedef struct {
    JsVar *thisVar;
    JsVar *root;
} ExecInfo;

#define NO_INLINE
#define LEX_ID 0
#define LEX_TEMPLATE_LITERAL 0
#define LEX_ARROW_FUNCTION 0
#define LEX_INT 0
#define LEX_FLOAT 0
#define LEX_R_TRUE 0
#define LEX_R_FALSE 0
#define LEX_R_NULL 0
#define LEX_R_UNDEFINED 0
#define LEX_STR 0
#define LEX_REGEX 0
#define LEX_R_FUNCTION 0
#define LEX_R_CLASS 0
#define LEX_R_SUPER 0
#define LEX_R_THIS 0
#define LEX_R_DELETE 0
#define LEX_R_TYPEOF 0
#define LEX_R_VOID 0
#define LEX_EOF 0
#define JSET_SYNTAXERROR 0
#define JSV_NULL 0
#define JSPARSE_INHERITS_VAR ""
#define JSPARSE_PROTOTYPE_VAR ""
#define SAVE_ON_FLASH
#define JSP_SHOULD_EXECUTE 0
#define JSP_SHOULDNT_PARSE 0
#define JSVAPPENDSTRINGVAR_MAXLENGTH 0

extern LexToken *lex;
extern ExecInfo execInfo;

JsVar *jspGetNamedVariable(const char *name);
void JSP_ASSERT_MATCH(int tk);
char *jslGetTokenValueAsString(LexToken *lex);
JsVar *jsvNewFromLongInteger(long x);
JsVar *jsvNewFromFloat(double x);
JsVar *jsvNewFromBool(bool b);
JsVar *jsvNewWithFlags(int flags);
JsVar *jsvLockAgain(JsVar *var);
void jsvUnLock(JsVar *var);
void jsvUnLock3(JsVar *a, JsVar *b, JsVar *c);
bool jsvIsName(JsVar *var);
bool jsvIsObject(JsVar *var);
bool jsvIsFunction(JsVar *var);
JsVar *jsvObjectGetChild(JsVar *obj, const char *name, int flags);
JsVar *jslGetTokenValueAsVar(LexToken *lex);
void jsExceptionHere(int type, const char *msg);
long stringToInt(const char *str);
double stringToFloat(const char *str);
void jsvStringIteratorNew(JsvStringIterator *it, JsVar *str, size_t start);
bool jsvStringIteratorHasChar(JsvStringIterator *it);
char jsvStringIteratorGetChar(JsvStringIterator *it);
void jsvStringIteratorNext(JsvStringIterator *it);
void jsvStringIteratorFree(JsvStringIterator *it);
JsVar *jsvNewFromStringVar(JsVar *str, size_t start, size_t length);
JsVar *jswrap_regexp_constructor(JsVar *source, JsVar *flags);
JsVar *jspeArrowFunction(int flags, JsVar *name);
JsVar *jspeExpression();
JsVar *jspeExpressionOrArrowFunction();
JsVar *jspeFactorObject();
JsVar *jspeFactorArray();
JsVar *jspeFunctionDefinition(bool isExpression);
JsVar *jspeClassDefinition(bool isExpression);
JsVar *jspeFactorDelete();
JsVar *jspeFactorTypeOf();
JsVar *jspeUnaryExpression();
JsVar *jspeTemplateLiteral();
bool jspCheckStackPosition();
void JSP_MATCH(int tk);
JsVar *JSP_MATCH_WITH_RETURN(int tk, JsVar *ret);