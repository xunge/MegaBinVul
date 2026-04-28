#include <stdlib.h>
#include <assert.h>

typedef struct ODBCDbc ODBCDbc;
typedef struct ODBCStmt ODBCStmt;
typedef struct ODBCDesc ODBCDesc;

struct ODBCDbc {
    void *mid;
    int qtimeout;
    ODBCStmt *FirstStmt;
};

struct ODBCStmt {
    ODBCDbc *Dbc;
    void *Error;
    int RetrievedErrors;
    int State;
    void *hdl;
    int currentRow;
    int startRow;
    int rowSetSize;
    int queryid;
    int nparams;
    int querytype;
    int rowcount;
    int qtimeout;
    int cursorType;
    int cursorScrollable;
    int retrieveData;
    int noScan;
    ODBCDesc *ApplRowDescr;
    ODBCDesc *ApplParamDescr;
    ODBCDesc *ImplRowDescr;
    ODBCDesc *ImplParamDescr;
    int Type;
    ODBCStmt *next;
    ODBCDesc *AutoApplRowDescr;
    ODBCDesc *AutoApplParamDescr;
};

struct ODBCDesc {
    int sql_desc_alloc_type;
    ODBCStmt *Stmt;
};

enum {
    INITED,
    SQL_CURSOR_FORWARD_ONLY,
    SQL_NONSCROLLABLE,
    SQL_RD_ON,
    SQL_NOSCAN_OFF,
    SQL_DESC_ALLOC_AUTO,
    ODBC_STMT_MAGIC_NR
};

void addDbcError(ODBCDbc *dbc, const char *code, const char *msg, int len);
void destroyODBCStmt(ODBCStmt *stmt);
ODBCDesc *newODBCDesc(ODBCDbc *dbc);
void *mapi_new_handle(void *mid);