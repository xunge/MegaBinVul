#include <assert.h>

typedef struct Walker Walker;
typedef struct Expr Expr;
typedef struct IdxExprTrans IdxExprTrans;

struct Walker {
    union {
        IdxExprTrans *pIdxTrans;
    } u;
};

struct Expr {
    int op;
    int iTable;
    int iColumn;
    union {
        void *pTab;
    } y;
    char affExpr;
};

struct IdxExprTrans {
    int iTabCur;
    int iTabCol;
    int iIdxCur;
    int iIdxCol;
};

#define TK_COLUMN 1
#define WRC_Continue 0

char sqlite3TableColumnAffinity(void*, int);