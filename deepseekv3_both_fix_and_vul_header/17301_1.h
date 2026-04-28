#include <stdint.h>
#include <stdbool.h>

typedef struct JsVar JsVar;
typedef struct JsExecInfo {
    uint32_t execute;
} JsExecInfo;
typedef enum JsExecFlags {
    EXEC_DEBUGGER_NEXT_LINE,
    EXEC_IN_LOOP,
    EXEC_IN_SWITCH,
    EXEC_RUN_MASK,
    EXEC_CONTINUE,
    EXEC_BREAK
} JsExecFlags;
typedef enum JsExceptionType {
    JSET_SYNTAXERROR
} JsExceptionType;
typedef struct Lexer {
    int tk;
    struct {
        struct {
            int index;
        } it;
    } tokenStart;
    int tokenLastStart;
} Lexer;

extern Lexer *lex;
extern JsExecInfo execInfo;

#define JSP_SHOULD_EXECUTE 1
#define NO_INLINE
#define USE_DEBUGGER
#define LEX_ID 0
#define LEX_INT 0
#define LEX_FLOAT 0
#define LEX_STR 0
#define LEX_TEMPLATE_LITERAL 0
#define LEX_REGEX 0
#define LEX_R_NEW 0
#define LEX_R_NULL 0
#define LEX_R_UNDEFINED 0
#define LEX_R_TRUE 0
#define LEX_R_FALSE 0
#define LEX_R_THIS 0
#define LEX_R_DELETE 0
#define LEX_R_TYPEOF 0
#define LEX_R_VOID 0
#define LEX_R_SUPER 0
#define LEX_PLUSPLUS 0
#define LEX_MINUSMINUS 0
#define LEX_R_VAR 0
#define LEX_R_LET 0
#define LEX_R_CONST 0
#define LEX_R_IF 0
#define LEX_R_DO 0
#define LEX_R_WHILE 0
#define LEX_R_FOR 0
#define LEX_R_TRY 0
#define LEX_R_RETURN 0
#define LEX_R_THROW 0
#define LEX_R_FUNCTION 0
#define LEX_R_CLASS 0
#define LEX_R_CONTINUE 0
#define LEX_R_BREAK 0
#define LEX_R_SWITCH 0
#define LEX_R_DEBUGGER 0
#define LEX_EOF 0

#define JSP_ASSERT_MATCH(x)
#define JSP_MATCH(x)

JsVar *jspeExpression();
JsVar *jspeBlock();
JsVar *jspeStatementVar();
JsVar *jspeStatementIf();
JsVar *jspeStatementDoOrWhile(bool isWhile);
JsVar *jspeStatementFor();
JsVar *jspeStatementTry();
JsVar *jspeStatementReturn();
JsVar *jspeStatementThrow();
JsVar *jspeStatementFunctionDecl(bool isClass);
JsVar *jspeStatementSwitch();
void jsiDebuggerLoop();
void jsExceptionHere(JsExceptionType type, const char* msg);
int jsvStringIteratorGetIndex(void* it);