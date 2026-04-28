#include <stddef.h>

#define WRC_Continue 0
#define WRC_Abort 1
#define WRC_Prune 2
#define ALWAYS(X) (1)
#define SF_View 0x0001

typedef struct Walker Walker;
typedef struct Parse Parse;
typedef struct Select Select;
typedef struct ExprList ExprList;
typedef struct SrcList SrcList;

struct Walker {
    Parse *pParse;
};

struct Parse {
    int nErr;
};

struct Select {
    ExprList *pEList;
    SrcList *pSrc;
    unsigned selFlags;
};

struct ExprList {
    int nExpr;
    struct {
        char *zName;
    } *a;
};

struct SrcList {
    int nSrc;
    struct {
        char *zName;
    } *a;
};

void sqlite3RenameTokenRemap(Parse*, int, void*);
void renameWalkWith(Walker*, Select*);