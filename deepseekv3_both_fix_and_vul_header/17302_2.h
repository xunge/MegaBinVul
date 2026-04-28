#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

typedef struct JsVar JsVar;
typedef struct JsvIterator JsvIterator;
typedef struct JslCharPos JslCharPos;
typedef uint32_t JsExecFlags;
typedef int LexTokenType;
typedef bool (*JsvIsInternalChecker)(JsVar*);

struct JslCharPos {
    int pos;
};

struct Lexer {
    LexTokenType tk;
    JslCharPos tokenStart;
};

struct execInfo {
    JsExecFlags execute;
    JsVar *root;
};

struct JsvIterator {
    void *data;
};

#define NO_INLINE
#define JSP_ASSERT_MATCH(x)
#define JSP_MATCH(x)
#define JSP_MATCH_WITH_CLEANUP_AND_RETURN(x, y, z)
#define LEX_R_FOR 1
#define LEX_R_IN 2
#define EXEC_IN_LOOP (1 << 0)
#define EXEC_FOR_INIT (1 << 1)
#define EXEC_YES (1 << 2)
#define EXEC_CONTINUE (1 << 3)
#define EXEC_BREAK (1 << 4)
#define JSIF_DEFINED_ARRAY_ElEMENTS 0
#define JSPARSE_INHERITS_VAR "__proto__"
#define JSPARSE_MAX_LOOP_ITERATIONS 10000
#define STRINGIFY(x) #x
#define JSP_SHOULD_EXECUTE 1
#define JSET_ERROR 1

extern struct execInfo execInfo;
extern struct Lexer *lex;

/* Function declarations */
JsVar *jspeStatement();
bool jspIsInterrupted();
void jsvUnLock(JsVar *);
void jsvUnLock2(JsVar *, JsVar *);
bool jsvIsName(JsVar *);
void jsExceptionHere(int, const char *, ...);
bool jsvGetRefs(JsVar *);
void jsvAddName(JsVar *, JsVar *);
JsVar *jspeExpression();
JsVar *jsvSkipNameAndUnLock(JsVar *);
void JSP_SAVE_EXECUTE();
void jspSetNoExecute();
void JSP_RESTORE_EXECUTE();
JsVar *jspeBlockOrStatement();
bool jsvIsIterable(JsVar *);
JsvIsInternalChecker jsvGetInternalFunctionCheckerFor(JsVar *);
void jsvIteratorNew(JsvIterator *, JsVar *, int);
bool jsvIteratorHasElement(JsvIterator *);
JsVar *jsvIteratorGetKey(JsvIterator *);
bool jsvIsString(JsVar *);
bool jsvIsStringEqual(JsVar *, const char *);
JsVar *jsvSkipName(JsVar *);
JsVar *jsvCopyNameOnly(JsVar *, bool, bool);
void jsvSetValueOfName(JsVar *, JsVar *);
void jsvIteratorNext(JsvIterator *);
void jspDebuggerLoopIfCtrlC();
void jsvIteratorFree(JsvIterator *);
bool jsvIsUndefined(JsVar *);
void jsvRemoveChild(JsVar *, JsVar *);
JsVar *jspeAssignmentExpression();
bool jsvGetBoolAndUnLock(JsVar *);
JslCharPos jslCharPosClone(const JslCharPos *);
void jslCharPosFree(JslCharPos *);
void jslSeekToP(const JslCharPos *);