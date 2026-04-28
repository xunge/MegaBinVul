#include <stddef.h>
#include <string.h>
#include <assert.h>

typedef struct Parse Parse;
typedef struct Select Select;
typedef struct Vdbe Vdbe;
typedef struct sqlite3 sqlite3;
typedef struct SrcList SrcList;
typedef struct Expr Expr;
typedef struct ExprList ExprList;
typedef struct Window Window;
typedef struct Table Table;

#define SQLITE_OK 0
#define SQLITE_NOMEM 7
#define SF_WinRewrite 0x00000000
#define SF_Aggregate 0x00000000
#define SF_Expanded 0x00000000
#define SQLITE_FUNC_SUBTYPE 0x00000000
#define SQLITE_AFF_NONE 0x00000000
#define TF_Ephemeral 0x00000000
#define TK_INTEGER 0x00000000
#define OP_Null 0
#define OP_OpenEphemeral 0
#define OP_OpenDup 0

struct Parse {
    sqlite3 *db;
    int nTab;
    int nMem;
    int nErr;
};

struct Select {
    Window *pWin;
    Select *pPrior;
    unsigned selFlags;
    SrcList *pSrc;
    Expr *pWhere;
    ExprList *pGroupBy;
    Expr *pHaving;
    ExprList *pEList;
    ExprList *pOrderBy;
};

struct Expr {
    int op;
    char *z;
    struct {
        ExprList *pList;
    } x;
};

struct ExprList {
    int nExpr;
    Expr *a[1];
};

struct Window {
    ExprList *pPartition;
    ExprList *pOrderBy;
    Window *pNextWin;
    int iEphCsr;
    int nBufferCol;
    int regAccum;
    int regResult;
    Expr *pOwner;
    struct {
        unsigned funcFlags;
    } *pFunc;
    Expr *pFilter;
    int iArgCol;
    int bExprArgs;
};

struct Table {
    int tabFlags;
};

struct SrcList {
    struct {
        Select *pSelect;
        Table *pTab;
    } a[1];
};

struct sqlite3 {
    int mallocFailed;
};

static int sqlite3ErrorToParser(sqlite3 *db, int err) { return err; }
static Vdbe *sqlite3GetVdbe(Parse *pParse) { return 0; }
static Table *sqlite3DbMallocZero(sqlite3 *db, size_t size) { return 0; }
static ExprList *sqlite3ExprListDup(sqlite3 *db, ExprList *p, int flags) { return 0; }
static ExprList *exprListAppendList(Parse *pParse, ExprList *pList1, ExprList *pList2, int flags) { return 0; }
static int sqlite3ExprListCompare(ExprList *pA, ExprList *pB, int i) { return 0; }
static void sqlite3ExprListDelete(sqlite3 *db, ExprList *p) {}
static void selectWindowRewriteEList(Parse *pParse, Window *pMWin, SrcList *pSrc, ExprList *pList, Table *pTab, ExprList **ppSublist) {}
static Expr *sqlite3ExprDup(sqlite3 *db, Expr *p, int flags) { return 0; }
static ExprList *sqlite3ExprListAppend(Parse *pParse, ExprList *pList, Expr *pExpr) { return 0; }
static Expr *sqlite3Expr(sqlite3 *db, int op, const char *z) { return 0; }
static Select *sqlite3SelectNew(Parse *pParse, ExprList *pEList, SrcList *pSrc, Expr *pWhere, ExprList *pGroupBy, Expr *pHaving, ExprList *pOrderBy, int isDistinct, int selLimit) { return 0; }
static SrcList *sqlite3SrcListAppend(Parse *pParse, SrcList *pList, Table *pTab, const char *zAlias) { return 0; }
static void sqlite3SrcListAssignCursors(Parse *pParse, SrcList *pList) {}
static Table *sqlite3ResultSetOfSelect(Parse *pParse, Select *pSelect, int aff) { return 0; }
static void sqlite3VdbeAddOp2(Vdbe *v, int op, int p1, int p2) {}
static void sqlite3SelectDelete(sqlite3 *db, Select *p) {}
static void sqlite3DbFree(sqlite3 *db, void *p) {}