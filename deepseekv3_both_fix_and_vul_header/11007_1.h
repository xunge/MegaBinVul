#include <stdarg.h>
#include <assert.h>

typedef struct sqlite3 {
    int mallocFailed;
} sqlite3;

typedef struct Parse {
    int nErr;
} Parse;

typedef struct VdbeOp {
    char *zComment;
} VdbeOp;

typedef struct Vdbe {
    int nOp;
    VdbeOp *aOp;
    sqlite3 *db;
    Parse *pParse;
} Vdbe;

char *sqlite3VMPrintf(sqlite3*, const char*, va_list);
void sqlite3DbFree(sqlite3*, void*);