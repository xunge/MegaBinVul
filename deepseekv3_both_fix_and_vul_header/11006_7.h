#include <stddef.h>
#include <string.h>
#include <stdint.h>

struct sqlite3 {
    int mallocFailed;
};

struct Table {
    int nTabRef;
    struct Table *pNextZombie;
};

struct IdList {
    // Placeholder for IdList structure
};

struct Expr {
    struct Expr *pRight;
};

struct ExprList_item {
    union {
        struct {
            int iOrderByCol;
        } x;
    } u;
};

struct ExprList {
    int nExpr;
    struct ExprList_item a[1];
};

struct SrcList_item {
    char *zDatabase;
    char *zName;
    char *zAlias;
    struct Select *pSelect;
    struct Table *pTab;
    int iCursor;
    struct {
        unsigned jointype;
        unsigned isTabFunc:1;
    } fg;
    struct IdList *pUsing;
};

struct SrcList {
    int nSrc;
    struct SrcList_item a[1];
};

struct Select {
    struct Select *pPrior;
    struct Select *pNext;
    struct Expr *pWhere;
    struct ExprList *pOrderBy;
    struct Expr *pLimit;
    struct SrcList *pSrc;
    struct ExprList *pEList;
    unsigned selFlags;
    int op;
    struct Select *pWin;
};

struct Parse {
    struct sqlite3 *db;
    const char *zAuthContext;
    char *zName;
    struct Table *pZombieTab;
};

struct SubstContext {
    struct Parse *pParse;
    int iTable;
    int iNewTable;
    int isLeftJoin;
    struct ExprList *pEList;
};

typedef uint8_t u8;

#define SQLITE_OMIT_WINDOWFUNC
#define SQLITE_EXTRA_IFNULLROW
#define SELECTTRACE_ENABLED 0
#define ALWAYS(X) (X)
#define TESTONLY(X) X
#define testcase(X)
#define assert(X)
#define SELECTTRACE(X,Y,Z,W)
#define SQLITE_DENY 0
#define SQLITE_SELECT 0
#define SQLITE_QueryFlattener 0
#define TK_ALL 0
#define SF_Recursive 0
#define SF_Distinct 0
#define SF_Aggregate 0
#define SF_Compound 0
#define JT_OUTER 0

int OptimizationDisabled(struct sqlite3*, int);
int sqlite3AuthCheck(struct Parse*, int, int, int, int);
void sqlite3DbFree(struct sqlite3*, void*);
struct Select *sqlite3SelectDup(struct sqlite3*, struct Select*, int);
struct SrcList *sqlite3SrcListAppend(struct Parse*, int, int, int);
struct SrcList *sqlite3SrcListEnlarge(struct Parse*, struct SrcList*, int, int);
void sqlite3IdListDelete(struct sqlite3*, struct IdList*);
void sqlite3SetJoinExpr(struct Expr*, int);
struct Expr *sqlite3ExprAnd(struct Parse*, struct Expr*, struct Expr*);
void substSelect(struct SubstContext*, struct Select*, int);
void sqlite3SelectDelete(struct sqlite3*, struct Select*);
struct Parse *sqlite3ParseToplevel(struct Parse*);
int IsVirtual(struct Table*);

typedef struct Parse Parse;
typedef struct Select Select;
typedef struct SrcList SrcList;
typedef struct SrcList_item SrcList_item;
typedef struct Expr Expr;
typedef struct ExprList ExprList;
typedef struct Table Table;
typedef struct sqlite3 sqlite3;
typedef struct SubstContext SubstContext;