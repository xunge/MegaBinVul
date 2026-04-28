#include <stdlib.h>

typedef long SQLLEN;
typedef short SQLSMALLINT;
typedef unsigned short SQLUSMALLINT;
typedef int RETCODE;

enum {
    SQL_COLUMN_DISPLAY_SIZE = 1,
    SQL_COLUMN_TYPE = 2,
    SQL_DESC_OCTET_LENGTH = 3,
    SQL_DESC_NAME = 4,
    SQL_C_CHAR = 5,
    SQL_SUCCESS = 6,
    SQL_SUCCESS_WITH_INFO = 7,
    SQL_BINARY = 8,
    SQL_VARBINARY = 9,
    SQL_LONGVARBINARY = 10,
    SQL_LONGVARCHAR = 11,
    SQL_WLONGVARCHAR = 12,
    SQL_TIMESTAMP = 13,
    SQL_CHAR = 14,
    SQL_VARCHAR = 15,
    SQL_WCHAR = 16,
    SQL_WVARCHAR = 17
};

#define ODBCVER 0
#define HAVE_ADABAS 0

#define ODBCG(x) (0)
#define TSRMLS_DC
#define PHP_ODBC_SQLCOLATTRIBUTE(x,y,z,a,b,c,d) (0)
#define SQLBindCol(x,y,z,a,b,c) (0)
#define safe_emalloc(x,y,z) malloc((x)*(y))
#define emalloc malloc

typedef struct _odbc_result_value {
    char name[256];
    SQLSMALLINT coltype;
    char *value;
    SQLLEN vallen;
} odbc_result_value;

typedef struct _odbc_result {
    int numcols;
    odbc_result_value *values;
    long longreadlen;
    int binmode;
    void *stmt;
} odbc_result;