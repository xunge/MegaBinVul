#include <stddef.h>
#include <assert.h>

typedef struct Parse Parse;
typedef struct Expr Expr;
typedef struct NameContext NameContext;
typedef struct sqlite3 sqlite3;
typedef struct Schema Schema;
typedef struct Table Table;
typedef struct Column Column;
typedef struct SrcList SrcList;
typedef struct SrcList_item SrcList_item;
typedef struct ExprList ExprList;
typedef struct Upsert Upsert;
typedef struct Select Select;
typedef struct Vdbe Vdbe;

#define TK_COLUMN 0
#define TK_REGISTER 0
#define TK_TRIGGER 0
#define TK_STRING 0
#define TK_ID 0
#define TK_DELETE 0
#define TK_UPDATE 0
#define TK_INSERT 0

#define EP_NoReduce 0
#define EP_TokenOnly 0
#define EP_Reduced 0
#define EP_CanBeNull 0
#define EP_Alias 0
#define EP_Agg 0
#define EP_Win 0
#define EP_Leaf 0
#define EP_DblQuoted 0

#define NC_PartIdx 0
#define NC_IsCheck 0
#define NC_UEList 0
#define NC_AllowAgg 0
#define NC_AllowWin 0
#define NC_IdxExpr 0
#define NC_GenCol 0
#define NC_UUpsert 0

#define SF_NestedFrom 0
#define IN_RENAME_OBJECT 0
#define WRC_Abort 0
#define WRC_Prune 0
#define SQLITE_OMIT_TRIGGER 0
#define SQLITE_OMIT_UPSERT 0
#define SQLITE_WARNING 0
#define SQLITE_ENABLE_NORMALIZE 0
#define SQLITE_AFF_INTEGER 0

#define JT_NATURAL 0
#define JT_LEFT 0
#define JT_RIGHT 0

#define TF_HasGenerated 0
#define COLFLAG_GENERATED 0

#define BMS 64
typedef unsigned int Bitmask;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short i16;

struct NameContext {
    int ncFlags;
    NameContext *pNext;
    SrcList *pSrcList;
    struct {
        ExprList *pEList;
        Upsert *pUpsert;
    } uNC;
    int nErr;
    int nRef;
};

struct Parse {
    sqlite3 *db;
    int checkSchema;
    u32 oldmask;
    u32 newmask;
    Table *pTriggerTab;
    int eTriggerOp;
    Vdbe *pVdbe;
};

struct Expr {
    int op;
    int iTable;
    int iColumn;
    union {
        Table *pTab;
    } y;
    Expr *pLeft;
    Expr *pRight;
    union {
        ExprList *pList;
        Select *pSelect;
    } x;
    int affExpr;
    unsigned flags;
};

struct sqlite3 {
    int nDb;
    struct Db {
        char *zDbSName;
        Schema *pSchema;
    } *aDb;
};

struct SrcList {
    int nSrc;
    SrcList_item *a;
};

struct SrcList_item {
    Table *pTab;
    char *zName;
    char *zAlias;
    Select *pSelect;
    ExprList *pUsing;
    int iCursor;
    struct {
        int jointype;
    } fg;
    Bitmask colUsed;
};

struct Table {
    char *zName;
    int nCol;
    Column *aCol;
    Schema *pSchema;
    int iPKey;
    int tabFlags;
};

struct Column {
    char *zName;
    int colFlags;
};

struct ExprList {
    int nExpr;
    struct {
        Expr *pExpr;
        char *zName;
        char *zSpan;
    } *a;
};

struct Upsert {
    int regData;
    SrcList *pUpsertSrc;
};

struct Select {
    int selFlags;
    ExprList *pEList;
};

static int sqlite3StrICmp(const char *, const char *);
static int sqlite3MatchSpanName(const char *, const char *, const char *, const char *);
static int sqlite3IsRowid(const char *);
static int VisibleRowid(Table *);
static int nameInUsingClause(ExprList *, const char *);
static void sqlite3ErrorMsg(Parse *, const char *, ...);
static void sqlite3ExprDelete(sqlite3 *, Expr *);
static void sqlite3AuthRead(Parse *, Expr *, Schema *, SrcList *);
static void resolveAlias(Parse *, ExprList *, int, Expr *, const char *, int);
static int sqlite3ExprIdToTrueFalse(Expr *);
static int sqlite3ExprVectorSize(Expr *);
static void sqlite3RenameTokenRemap(Parse *, int, void *);
static void sqlite3VdbeAddDblquoteStr(sqlite3 *, Vdbe *, const char *);
static void sqlite3_log(int, const char *, ...);
static int areDoubleQuotedStringsEnabled(sqlite3 *, NameContext *);
static int ExprHasProperty(Expr *, int);
static void ExprSetVVAProperty(Expr *, int);
static void ExprSetProperty(Expr *, int);
static void testcase(int);