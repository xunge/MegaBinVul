#include <assert.h>

typedef struct sqlite3 sqlite3;

struct Parse {
    sqlite3 *db;
};

typedef struct Expr Expr;
typedef struct ExprList ExprList;
typedef struct Parse Parse;

#define TK_INTEGER 1
#define TK_NULL 2

#define EP_MemToken 0x01
#define EP_IntValue 0x02
#define EP_IsTrue 0x04
#define EP_IsFalse 0x08

struct Expr {
    int op;
    int flags;
    union {
        char *zToken;
    } u;
};

struct ExprList {
    int nExpr;
    struct ExprList_item {
        Expr *pExpr;
        int sortFlags;
    } *a;
};

Expr *sqlite3ExprDup(sqlite3*, Expr*, int);
ExprList *sqlite3ExprListAppend(Parse*, ExprList*, Expr*);
int ExprHasProperty(Expr*, int);