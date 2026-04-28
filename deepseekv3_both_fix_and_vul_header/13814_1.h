#include <stddef.h>
#include <assert.h>
#include <stdint.h>

typedef struct Parse Parse;
typedef struct Token Token;
typedef struct Table Table;
typedef struct sqlite3 sqlite3;
typedef struct Index Index;
typedef struct Select Select;
typedef struct Vdbe Vdbe;
typedef struct SelectDest SelectDest;
typedef struct Db Db;
typedef struct Schema Schema;
typedef struct Hash Hash;
typedef struct Column Column;
typedef struct Check Check;
typedef struct Expr Expr;

typedef unsigned char u8;
typedef unsigned int u32;

#define SQLITE_OMIT_CHECK
#define SQLITE_OMIT_GENERATED_COLUMNS
#define SQLITE_OMIT_VIEW
#define SQLITE_OMIT_AUTOINCREMENT
#define SQLITE_OMIT_ALTERTABLE

#define TF_Shadow 0x01
#define TF_Readonly 0x02
#define TF_HasPrimaryKey 0x04
#define TF_WithoutRowid 0x08
#define TF_NoVisibleRowid 0x10
#define TF_Autoincrement 0x20
#define TF_HasGenerated 0x40
#define TF_HasVirtual 0x80
#define TF_HasStored 0x100

#define NC_IsCheck 0x01
#define NC_GenCol 0x02

#define COLFLAG_GENERATED 0x01
#define COLFLAG_VIRTUAL 0x02
#define COLFLAG_STORED 0x04

#define SRT_Coroutine 0x01
#define OPFLAG_P2ISREG 0x01

#define OP_Close 1
#define OP_OpenWrite 2
#define OP_InitCoroutine 3
#define OP_Yield 4
#define OP_MakeRecord 5
#define OP_NewRowid 6
#define OP_Insert 7

#define SQLITE_AFF_BLOB 0x01
#define DBFLAG_SchemaChange 0x01

#define MASTER_NAME "sqlite_master"

#define NEVER(x) (x)
#define VdbeCoverage(v)
#define testcase(x)

struct Token {
    const char *z;
    int n;
};

struct Hash {
    void *pFirst;
};

struct Column {
    u32 colFlags;
    Expr *pDflt;
};

struct Check {
    Expr *pExpr;
};

struct Index {
    Index *pNext;
};

struct Table {
    char *zName;
    int tnum;
    u8 tabFlags;
    int iPKey;
    int nCol;
    int nNVCol;
    Column *aCol;
    Index *pIndex;
    Schema *pSchema;
    Select *pSelect;
    Check *pCheck;
    int addColOffset;
};

struct Select {
};

struct Parse {
    sqlite3 *db;
    Table *pNewTable;
    int nMem;
    int nTab;
    int regRoot;
    int regRowid;
    int nErr;
    Token sNameToken;
    Token sLastToken;
};

struct sqlite3 {
    int mallocFailed;
    struct {
        int busy;
        int newTnum;
    } init;
    Db *aDb;
    unsigned int mDbFlags;
};

struct Db {
    char *zDbSName;
    Schema *pSchema;
};

struct Schema {
    Table *pSeqTab;
    Hash tblHash;
};

struct Vdbe {
};

struct SelectDest {
    int iSDParm;
    int iSdst;
    int nSdst;
};

static Vdbe *sqlite3GetVdbe(Parse*);
static int sqlite3SchemaMutexHeld(sqlite3*,int,int);
static void *sqlite3HashInsert(Hash*,const char*,void*);