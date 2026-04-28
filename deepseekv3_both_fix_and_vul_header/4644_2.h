#include <stdlib.h>

typedef int RETCODE;
typedef short SQLSMALLINT;
typedef long SQLLEN;
typedef unsigned short SQLUSMALLINT;

enum {
    SQL_COLUMN_DISPLAY_SIZE = 1,
    SQL_COLUMN_TYPE = 2,
    SQL_BINARY = 3,
    SQL_VARBINARY = 4,
    SQL_LONGVARBINARY = 5,
    SQL_LONGVARCHAR = 6,
    SQL_WLONGVARCHAR = 7,
    SQL_TIMESTAMP = 8,
    SQL_CHAR = 9,
    SQL_VARCHAR = 10,
    SQL_WCHAR = 11,
    SQL_WVARCHAR = 12,
    SQL_DESC_OCTET_LENGTH = 13,
    SQL_DESC_NAME = 14,
    SQL_C_CHAR = 15,
    SQL_SUCCESS = 16,
    SQL_SUCCESS_WITH_INFO = 17
};

typedef void* SQLHSTMT;

typedef struct _odbc_result {
    int numcols;
    struct _odbc_result_value *values;
    SQLHSTMT stmt;
    long longreadlen;
    int binmode;
} odbc_result;

typedef struct _odbc_result_value {
    char name[256];
    SQLSMALLINT coltype;
    char *value;
    SQLLEN vallen;
} odbc_result_value;

#define TSRMLS_DC
#define ODBCG(x) (0)
#define PHP_ODBC_SQLCOLATTRIBUTE(x,y,z,a,b,c,d) (0)
#define SQLBindCol(x,y,z,a,b,d) (0)
#define safe_emalloc(size,count,zero) malloc((size)*(count))
#define emalloc(size) malloc(size)