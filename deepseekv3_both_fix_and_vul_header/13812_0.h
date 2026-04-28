#include <string.h>
#include <assert.h>

#define UNUSED_PARAMETER(x) (void)(x)
#define SQLITE_OK 0
#define SQLITE_OMIT_AUTHORIZATION
#define SQLITE_OMIT_FOREIGN_KEY
#define SQLITE_OMIT_TRIGGER
#define SQLITE_LegacyAlter 0
#define SQLITE_ForeignKeys 0
#define SF_View 0x01

typedef struct sqlite3 {
    unsigned int flags;
    void* xAuth;
} sqlite3;

typedef struct sqlite3_context sqlite3_context;
typedef struct sqlite3_value sqlite3_value;
typedef struct sqlite3_xauth sqlite3_xauth;

typedef struct Parse {
    int nErr;
    int rc;
    char* zErrMsg;
    struct Table* pNewTable;
    struct Index* pNewIndex;
    struct Trigger* pNewTrigger;
} Parse;

typedef struct RenameCtx {
    struct Table* pTab;
    void* pList;
} RenameCtx;

typedef struct Walker {
    Parse* pParse;
    void (*xExprCallback)(struct Walker*, void*);
    void (*xSelectCallback)(struct Walker*, void*);
    union {
        RenameCtx* pRename;
    } u;
} Walker;

typedef struct Table {
    char* zName;
    void* pSelect;
    void* pCheck;
    struct FKey* pFKey;
    void* pSchema;
} Table;

typedef struct Index {
    char* zName;
    void* pPartIdxWhere;
} Index;

typedef struct NameContext {
    Parse* pParse;
} NameContext;

typedef struct FKey {
    char* zTo;
    struct FKey* pNextFrom;
} FKey;

typedef struct Trigger {
    char* table;
    struct TriggerStep* step_list;
    void* pTabSchema;
} Trigger;

typedef struct TriggerStep {
    char* zTarget;
    struct TriggerStep* pNext;
} TriggerStep;

typedef struct RenameToken {
    void* p;
    struct RenameToken* pNext;
} RenameToken;

typedef struct Select {
    unsigned int selFlags;
} Select;

static void renameTableExprCb(Walker* pWalker, void* pExpr) {}
static void renameTableSelectCb(Walker* pWalker, void* pSelect) {}
static int renameParseSql(Parse* pParse, const char* zDb, int iDb, sqlite3* db, const char* zInput, int bTemp) { return SQLITE_OK; }
static void renameTokenFind(Parse* pParse, RenameCtx* pCtx, void* pToken) {}
static int renameResolveTrigger(Parse* pParse, const char* zDb) { return SQLITE_OK; }
static void renameWalkTrigger(Walker* pWalker, Trigger* pTrigger) {}
static int renameEditSql(sqlite3_context* context, RenameCtx* pCtx, const char* zInput, const char* zNew, int bQuote) { return SQLITE_OK; }
static void renameColumnParseError(sqlite3_context* context, int bId, sqlite3_value* p1, sqlite3_value* p2, Parse* pParse) {}
static void renameParseCleanup(Parse* pParse) {}
static void renameTokenFree(sqlite3* db, RenameToken* pToken) {}

static sqlite3* sqlite3_context_db_handle(sqlite3_context* context) { return 0; }
static const char* sqlite3_value_text(sqlite3_value* pVal) { return 0; }
static int sqlite3_value_int(sqlite3_value* pVal) { return 0; }
static void sqlite3BtreeEnterAll(sqlite3* db) {}
static Table* sqlite3FindTable(sqlite3* db, const char* zName, const char* zDb) { return 0; }
static void sqlite3SelectPrep(Parse* pParse, void* pSelect, NameContext* pNC) {}
static void sqlite3WalkSelect(Walker* pWalker, void* pSelect) {}
static int sqlite3_stricmp(const char* z1, const char* z2) { return 0; }
static void sqlite3WalkExprList(Walker* pWalker, void* pList) {}
static void sqlite3WalkExpr(Walker* pWalker, void* pExpr) {}
static void sqlite3_result_error_code(sqlite3_context* context, int errCode) {}
static void sqlite3BtreeLeaveAll(sqlite3* db) {}