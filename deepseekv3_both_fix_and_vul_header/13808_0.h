#include <assert.h>

typedef struct Parse Parse;
typedef struct sqlite3 sqlite3;
typedef struct Walker Walker;
typedef struct Select Select;
typedef struct RenameCtx RenameCtx;
typedef struct SrcList SrcList;
typedef struct SrcList_item SrcList_item;

struct Parse {
    sqlite3 *db;
};

struct sqlite3 {
    int mallocFailed;
};

struct Walker {
    struct {
        RenameCtx *pRename;
    } u;
    Parse *pParse;
};

struct Select {
    SrcList *pSrc;
    unsigned selFlags;
};

struct RenameCtx {
    void *pTab;
};

struct SrcList {
    int nSrc;
    SrcList_item *a;
};

struct SrcList_item {
    void *pTab;
    char *zName;
};

#define WRC_Abort 0
#define WRC_Continue 1
#define WRC_Prune 2
#define SF_View 0x0001

void renameTokenFind(Parse *pParse, RenameCtx *p, char *zName);
void renameWalkWith(Walker *pWalker, Select *pSelect);