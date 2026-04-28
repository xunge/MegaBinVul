#include <stddef.h>
#include <assert.h>

typedef struct sqlite3 {
    int mallocFailed;
} sqlite3;

typedef struct Token {
    const char *z;
    unsigned int n;
} Token;

typedef struct Select {
    unsigned int selFlags;
} Select;

typedef struct ExprList ExprList;
typedef struct Schema Schema;

typedef struct Table {
    Schema *pSchema;
    Select *pSelect;
    ExprList *pCheck;
} Table;

typedef struct Parse {
    sqlite3 *db;
    int nVar;
    int nErr;
    Table *pNewTable;
    Token sLastToken;
} Parse;

typedef struct DbFixer {
    Parse *pParse;
    int iDb;
    const char *zType;
    Token *pName;
} DbFixer;

#define IN_RENAME_OBJECT 0
#define EXPRDUP_REDUCE 0
#define TRUE 1
#define SF_View 0x0001

void sqlite3ErrorMsg(Parse*, const char*);
void sqlite3StartTable(Parse*, Token*, Token*, int, int, int, int);
void sqlite3TwoPartName(Parse*, Token*, Token*, Token**);
int sqlite3SchemaToIndex(sqlite3*, Schema*);
void sqlite3FixInit(DbFixer*, Parse*, int, const char*, Token*);
int sqlite3FixSelect(DbFixer*, Select*);
Select *sqlite3SelectDup(sqlite3*, Select*, int);
ExprList *sqlite3ExprListDup(sqlite3*, ExprList*, int);
int sqlite3Isspace(char);
void sqlite3EndTable(Parse*, int, Token*, int, int);
void sqlite3SelectDelete(sqlite3*, Select*);
void sqlite3RenameExprlistUnmap(Parse*, ExprList*);
void sqlite3ExprListDelete(sqlite3*, ExprList*);