#include <stddef.h>
#include <stdbool.h>

typedef struct JsVar JsVar;
typedef struct LexToken LexToken;

#define NO_INLINE
#define LEX_PLUSEQUAL 1
#define LEX_MINUSEQUAL 2
#define LEX_MULEQUAL 3
#define LEX_DIVEQUAL 4
#define LEX_MODEQUAL 5
#define LEX_ANDEQUAL 6
#define LEX_OREQUAL 7
#define LEX_XOREQUAL 8
#define LEX_RSHIFTEQUAL 9
#define LEX_LSHIFTEQUAL 10
#define LEX_RSHIFTUNSIGNEDEQUAL 11
#define LEX_RSHIFT 12
#define LEX_LSHIFT 13
#define LEX_RSHIFTUNSIGNED 14

#define JSP_SHOULD_EXECUTE 1

struct LexToken {
    int tk;
};

extern LexToken *lex;

JsVar *jspeAssignmentExpression();
JsVar *jsvSkipNameAndUnLock(JsVar *var);
unsigned int jsvGetRefs(JsVar *var);
int jsvIsName(JsVar *var);
int jsvIsArrayBufferName(JsVar *var);
int jsvIsNewChild(JsVar *var);
void jsvAddName(JsVar *root, JsVar *name);
void jspReplaceWith(JsVar *lhs, JsVar *rhs);
JsVar *jsvSkipName(JsVar *var);
int jsvIsString(JsVar *var);
int jsvIsFlatString(JsVar *var);
JsVar *jsvAsString(JsVar *var, bool b);
void jsvAppendStringVarComplete(JsVar *dest, JsVar *src);
void jsvUnLock(JsVar *var);
JsVar *jsvMathsOpSkipNames(JsVar *lhs, JsVar *rhs, int op);

struct ExecInfo {
    JsVar *root;
};
extern struct ExecInfo execInfo;

#define JSP_ASSERT_MATCH(x)