#include <stddef.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

typedef uint16_t u16;
typedef uint32_t u32;
typedef int16_t i16;
typedef uint8_t u8;

struct Walker {
    struct Parse *pParse;
    u8 eCode;
};

struct Select {
    u16 selFlags;
    int selId;
    struct SrcList *pSrc;
    struct ExprList *pEList;
    void *pWith;
};

struct Parse {
    struct sqlite3 *db;
    int nSelect;
    int nErr;
};

struct SrcList {
    int nSrc;
    struct SrcList_item *a;
};

struct ExprList {
    int nExpr;
    struct ExprList_item *a;
};

struct sqlite3 {
    unsigned mallocFailed;
    unsigned flags;
    struct Db *aDb;
    unsigned *aLimit;
};

struct Expr {
    int op;
    struct Expr *pLeft;
    struct Expr *pRight;
    u32 flags;
    union {
        char *zToken;
        int iValue;
    } u;
};

struct Table {
    char *zName;
    struct Schema *pSchema;
    int nCol;
    struct Column *aCol;
    struct Select *pSelect;
    int nTabRef;
};

struct Token {
    char *z;
};

struct Db {
    const char *zDbSName;
};

struct Column {
    char *zName;
    unsigned hidden:1;
};

struct Schema {
    int dummy;
};

struct IdList {
    int dummy;
};

struct SrcList_item {
    char *zName;
    char *zAlias;
    struct Table *pTab;
    struct Select *pSelect;
    struct {
        unsigned isRecursive:1;
        unsigned jointype:8;
    } fg;
    struct IdList *pUsing;
};

struct ExprList_item {
    struct Expr *pExpr;
    char *zName;
    char *zSpan;
    unsigned bSpanIsTab:1;
};

#define WRC_Continue 0
#define WRC_Abort 1
#define WRC_Prune 2

#define SF_Expanded 0x0001
#define SF_NestedFrom 0x0002
#define SF_IncludeHidden 0x0004
#define SF_ComplexResult 0x0008

#define EP_IntValue 0x0100
#define EP_HasFunc 0x0200
#define EP_Subquery 0x0400

#define SQLITE_OMIT_CTE 0
#define SQLITE_OMIT_SUBQUERY 0
#define SQLITE_OMIT_VIEW 0
#define SQLITE_OMIT_VIRTUALTABLE 0

#define SQLITE_FullColNames 0x0001
#define SQLITE_ShortColNames 0x0002
#define SQLITE_EnableView 0x0004

#define SQLITE_LIMIT_COLUMN 0

#define TK_ID 1
#define TK_ASTERISK 2
#define TK_DOT 3

#define JT_NATURAL 0x01

static int ExprHasProperty(struct Expr *p, int prop) { return p->flags & prop; }
static int sqlite3StrICmp(const char *zLeft, const char *zRight) { return strcasecmp(zLeft, zRight); }
static void testcase(int x) { (void)x; }

static int sqlite3WalkSelect(struct Walker*, struct Select*);
static int sqlite3ViewGetColumnNames(struct Parse*, struct Table*);
static struct Select *sqlite3SelectDup(struct sqlite3*, struct Select*, int);
static int sqlite3ExpandSubquery(struct Parse*, struct SrcList_item*);
static int sqlite3IndexedByLookup(struct Parse*, struct SrcList_item*);
static int sqliteProcessJoin(struct Parse*, struct Select*);
static int withExpand(struct Walker*, struct SrcList_item*);
static int IsHiddenColumn(struct Column*);
static int IsVirtual(struct Table*);
static int cannotBeFunction(struct Parse*, struct SrcList_item*);
static int tableAndColumnIndex(struct SrcList*, int, const char*, int*, int*);
static int sqlite3IdListIndex(struct IdList*, const char*);
static int sqlite3MatchSpanName(const char*, int, const char*, int);
static int sqlite3SchemaToIndex(struct sqlite3*, struct Schema*);
static struct Table *sqlite3LocateTableItem(struct Parse*, int, struct SrcList_item*);
static void sqlite3WithPush(struct Parse*, void*, int);
static void sqlite3SrcListAssignCursors(struct Parse*, struct SrcList*);
static struct Expr *sqlite3Expr(struct sqlite3*, int, const char*);
static struct Expr *sqlite3PExpr(struct Parse*, int, struct Expr*, struct Expr*);
static struct ExprList *sqlite3ExprListAppend(struct Parse*, struct ExprList*, struct Expr*);
static void sqlite3ExprListSetName(struct Parse*, struct ExprList*, struct Token*, int);
static void sqlite3TokenInit(struct Token*, char*);
static void sqlite3ExprListDelete(struct sqlite3*, struct ExprList*);
static char *sqlite3MPrintf(struct sqlite3*, const char*, ...);
static char *sqlite3DbStrDup(struct sqlite3*, const char*);
static void sqlite3DbFree(struct sqlite3*, void*);
static void sqlite3ErrorMsg(struct Parse*, const char*, ...);

typedef struct Walker Walker;
typedef struct Select Select;
typedef struct Parse Parse;
typedef struct SrcList SrcList;
typedef struct ExprList ExprList;
typedef struct sqlite3 sqlite3;
typedef struct Expr Expr;
typedef struct Table Table;
typedef struct Token Token;