#include <assert.h>
#include <string.h>

typedef struct Parse Parse;
typedef struct Expr Expr;
typedef struct Vdbe Vdbe;
typedef struct AggInfo AggInfo;
typedef struct Column Column;
typedef struct Table Table;
typedef struct FuncDef FuncDef;
typedef struct ExprList ExprList;
typedef struct CollSeq CollSeq;
typedef struct sqlite3 sqlite3;
typedef struct Window Window;
typedef struct Select Select;

struct ExprList_item {
    Expr *pExpr;
};

struct ExprList {
    int nExpr;
    struct ExprList_item *a;
};

struct Select {
    ExprList *pEList;
};

struct Expr {
    int op;
    Expr *pLeft;
    Expr *pRight;
    union {
        ExprList *pList;
        Select *pSelect;
    } x;
    int iTable;
    int iColumn;
    int op2;
    int iAgg;
    int iMem;
    int target;
    int nMem;
    unsigned flags;
    union {
        int iValue;
        char *zToken;
    } u;
    union {
        Table *pTab;
        Window *pWin;
    } y;
    AggInfo *pAggInfo;
    Parse *pParse;
    sqlite3 *db;
    int affExpr;
};

struct Window {
    int regResult;
};

struct AggInfo_col {
    int iMem;
    int iSorterColumn;
};

struct AggInfo {
    int directMode;
    int useSortingIdx;
    int sortingIdxPTab;
    struct AggInfo_col *aCol;
    struct AggInfo_func {
        int iMem;
    } *aFunc;
};

struct Column {
    char *zName;
    char affinity;
    unsigned colFlags;
};

struct Table {
    int nCol;
    Column *aCol;
    int iPKey;
};

struct FuncDef {
    int funcFlags;
    void *xFinalize;
};

struct Parse {
    int nMem;
    int iSelfTab;
    Vdbe *pVdbe;
    sqlite3 *db;
    int okConstFactor;
    int *pVList;
    Table *pTriggerTab;
    int explain;
};

struct Vdbe {
    sqlite3 *db;
};

struct sqlite3 {
    CollSeq *pDfltColl;
    int mallocFailed;
};

#define SQLITE_AFF_BLOB 'A'
#define SQLITE_AFF_TEXT 'B'
#define SQLITE_AFF_NUMERIC 'C'
#define SQLITE_AFF_INTEGER 'D'
#define SQLITE_AFF_REAL 'E'
#define SQLITE_AFF_NONE 0
#define XN_ROWID -1
#define COLFLAG_GENERATED 0x01
#define COLFLAG_BUSY 0x02
#define COLFLAG_NOTAVAIL 0x04
#define SQLITE_NULLEQ 0x80
#define SQLITE_STOREP2 0x08
#define SQLITE_JUMPIFNULL 0x01
#define SQLITE_ECEL_DUP 0x01
#define SQLITE_ECEL_FACTOR 0x02
#define SQLITE_FUNC_COALESCE 0x01
#define SQLITE_FUNC_UNLIKELY 0x02
#define SQLITE_FUNC_AFFINITY 0x04
#define SQLITE_FUNC_NEEDCOLL 0x08
#define SQLITE_FUNC_LENGTH 0x10
#define SQLITE_FUNC_TYPEOF 0x20
#define SQLITE_FUNC_OFFSET 0x40
#define OPFLAG_LENGTHARG 0x10
#define OPFLAG_TYPEOFARG 0x20
#define EP_IntValue 0x0001
#define EP_TokenOnly 0x0002
#define EP_Commuted 0x0004
#define EP_xIsSelect 0x0008
#define EP_WinFunc 0x0010
#define EP_FixedCol 0x0020
#define EP_InfixFunc 0x0040
#define OE_Rollback 0
#define OE_Abort 1
#define OE_Fail 2
#define OE_Ignore 3
#define SQLITE_OK 0
#define SQLITE_CONSTRAINT_TRIGGER 19

typedef unsigned int u32;
typedef unsigned char u8;

#define TK_NULL 0
#define TK_INTEGER 1
#define TK_FLOAT 2
#define TK_STRING 3
#define TK_BLOB 4
#define TK_VARIABLE 5
#define TK_REGISTER 6
#define TK_IS 7
#define TK_ISNOT 8
#define TK_LT 9
#define TK_LE 10
#define TK_GT 11
#define TK_GE 12
#define TK_NE 13
#define TK_EQ 14
#define TK_AND 15
#define TK_OR 16
#define TK_PLUS 17
#define TK_STAR 18
#define TK_MINUS 19
#define TK_REM 20
#define TK_BITAND 21
#define TK_BITOR 22
#define TK_SLASH 23
#define TK_LSHIFT 24
#define TK_RSHIFT 25
#define TK_CONCAT 26
#define TK_UMINUS 27
#define TK_BITNOT 28
#define TK_NOT 29
#define TK_TRUEFALSE 30
#define TK_ISNULL 31
#define TK_NOTNULL 32
#define TK_BETWEEN 33
#define TK_SPAN 34
#define TK_COLLATE 35
#define TK_UPLUS 36
#define TK_TRIGGER 37
#define TK_VECTOR 38
#define TK_IF_NULL_ROW 39
#define TK_CASE 40
#define TK_RAISE 41
#define TK_AGG_COLUMN 42
#define TK_COLUMN 43
#define TK_AGG_FUNCTION 44
#define TK_FUNCTION 45
#define TK_SELECT 46
#define TK_EXISTS 47
#define TK_SELECT_COLUMN 48
#define TK_IN 49
#define TK_TRUTH 50
#define TK_CAST 51

#define OP_Lt 9
#define OP_Le 10
#define OP_Gt 11
#define OP_Ge 12
#define OP_Ne 13
#define OP_Eq 14
#define OP_And 15
#define OP_Or 16
#define OP_Add 17
#define OP_Subtract 19
#define OP_BitAnd 21
#define OP_BitOr 22
#define OP_Divide 23
#define OP_ShiftLeft 24
#define OP_ShiftRight 25
#define OP_Concat 26
#define OP_BitNot 28
#define OP_Not 29
#define OP_IsNull 31
#define OP_NotNull 32
#define OP_Column 33
#define OP_Affinity 34
#define OP_Integer 35
#define OP_Null 36
#define OP_Blob 37
#define OP_Variable 38
#define OP_Cast 39
#define OP_RealAffinity 40
#define OP_SCopy 41
#define OP_IfNullRow 42
#define OP_Param 43
#define OP_IsTrue 44
#define OP_Offset 45
#define OP_CollSeq 46
#define OP_Halt 47
#define OP_Remainder 20
#define OP_AddImm 48

#define P4_STATIC 0
#define P4_DYNAMIC 1
#define P4_COLLSEQ 2

#define MASKBIT32(n) (1U << (n))

#define VdbeCoverage(v)
#define VdbeCoverageIf(v,x)
#define VdbeComment(v,...)
#define VdbeJumpHere(v,x)

static void sqlite3ErrorMsg(Parse *pParse, const char *zFormat, ...) {}
static void sqlite3MayAbort(Parse *pParse) {}
static void sqlite3HaltConstraint(Parse *pParse, int errCode, int onError, const char *zMsg, int iMem, int iCol) {}
static void sqlite3SubselectError(Parse *pParse, int nActual, int nExpect) {}
static void sqlite3ExprDelete(sqlite3 *db, Expr *pExpr) {}
static Expr *sqlite3ExprDup(sqlite3 *db, Expr *pExpr, int flags) { return 0; }
static int sqlite3ExprIsConstantNotJoin(Expr *pExpr) { return 0; }
static int sqlite3ExprIsConstant(Expr *pExpr) { return 0; }
static int sqlite3ExprIsVector(Expr *pExpr) { return 0; }
static int sqlite3ExprVectorSize(Expr *pExpr) { return 0; }
static int sqlite3ExprTruthValue(Expr *pExpr) { return 0; }
static int sqlite3ExprAffinity(Expr *pExpr) { return 0; }
static CollSeq *sqlite3ExprCollSeq(Parse *pParse, Expr *pExpr) { return 0; }
static int sqlite3TableColumnAffinity(Table *pTab, int iCol) { return 0; }
static int sqlite3TableColumnToStorage(Table *pTab, int iCol) { return 0; }
static int sqlite3Strlen30(const char *z) { return 0; }
static char *sqlite3HexToBlob(sqlite3 *db, const char *z, int n) { return 0; }
static const char *sqlite3VListNumToName(void *pVList, int iCol) { return 0; }
static FuncDef *sqlite3FindFunction(sqlite3 *db, const char *zName, int nArg, int enc, int flags) { return 0; }
static FuncDef *sqlite3VtabOverloadFunction(sqlite3 *db, FuncDef *pDef, int nArg, Expr *pExpr) { return 0; }
static int sqlite3ExprCodeAtInit(Parse *pParse, Expr *pExpr, int target) { return 0; }
static int sqlite3ExprCodeTemp(Parse *pParse, Expr *pExpr, int *pReg) { return 0; }
static void sqlite3ExprCode(Parse *pParse, Expr *pExpr, int target) {}
static void sqlite3ExprCodeExprList(Parse *pParse, ExprList *pList, int target, int src, int flags) {}
static void sqlite3ExprIfFalse(Parse *pParse, Expr *pExpr, int dest, int jumpIfNull) {}
static int sqlite3VdbeAddOp1(Vdbe *v, int op, int p1) { return 0; }
static void sqlite3VdbeAddOp2(Vdbe *v, int op, int p1, int p2) {}
static void sqlite3VdbeAddOp3(Vdbe *v, int op, int p1, int p2, int p3) {}
static void sqlite3VdbeAddOp4(Vdbe *v, int op, int p1, int p2, int p3, const char *zP4, int p4type) {}
static void sqlite3VdbeAddOp4Int(Vdbe *v, int op, int p1, int p2, int p3, int p4) {}
static void sqlite3VdbeAddFunctionCall(Parse *pParse, int constMask, int r1, int target, int nFarg, FuncDef *pDef, int op2) {}
static void sqlite3VdbeAppendP4(Vdbe *v, char *z, int p4type) {}
static void sqlite3VdbeLoadString(Vdbe *v, int target, const char *z) {}
static void sqlite3VdbeGoto(Vdbe *v, int label) {}
static void sqlite3VdbeResolveLabel(Vdbe *v, int label) {}
static int sqlite3VdbeMakeLabel(Parse *pParse) { return 0; }
static void sqlite3VdbeJumpHere(Vdbe *v, int addr) {}
static void sqlite3ReleaseTempReg(Parse *pParse, int reg) {}
static void sqlite3ReleaseTempRange(Parse *pParse, int reg, int n) {}
static int sqlite3GetTempRange(Parse *pParse, int n) { return 0; }
static int sqlite3ExprCodeGetColumn(Parse *pParse, Table *pTab, int iCol, int iTab, int target, int op2) { return 0; }
static void sqlite3ExprCodeGeneratedColumn(Parse *pParse, Column *pCol, int iSrc) {}
static void codeInteger(Parse *pParse, Expr *pExpr, int negFlag, int target) {}
static void codeReal(Vdbe *v, const char *z, int negFlag, int target) {}
static void codeCompare(Parse *pParse, Expr *pLeft, Expr *pRight, int op, int r1, int r2, int target, int p5, int commuted) {}
static void codeVectorCompare(Parse *pParse, Expr *pExpr, int target, int op, int p5) {}
static void exprCodeBetween(Parse *pParse, Expr *pExpr, int target, int jumpIfNull, int rev) {}
static void sqlite3ExprCodeIN(Parse *pParse, Expr *pExpr, int destIfFalse, int destIfNull) {}
static int sqlite3CodeSubselect(Parse *pParse, Expr *pExpr) { return 0; }
static int exprCodeVector(Parse *pParse, Expr *pExpr, int *pReg) { return 0; }
static void exprToRegister(Expr *pExpr, int reg) {}
static int ConstFactorOk(Parse *pParse) { return 0; }
static int ExprHasProperty(Expr *pExpr, int prop) { return pExpr->flags & prop; }
static sqlite3 *sqlite3VdbeDb(Vdbe *v) { return v->db; }
static void sqlite3VdbeChangeP3(Vdbe *v, int addr, int p3) {}
static void testcase(int x) {}
static int sqlite3AffinityType(const char *z, int n) { return 0; }
static int ENC(sqlite3 *db) { return 0; }