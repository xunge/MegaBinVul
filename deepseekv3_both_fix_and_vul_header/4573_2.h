#include <stdlib.h>
#include <string.h>

#define PHP_PGSQL_API
#define TSRMLS_DC
#define TSRMLS_CC
#define FAILURE 0
#define SUCCESS 1
#define E_WARNING 2
#define PGRES_TUPLES_OK 2

typedef struct pg_conn PGconn;
typedef struct pg_result PGresult;

typedef struct _zval_struct zval;
typedef struct _smart_str {
    char *c;
    size_t len;
    size_t a;
} smart_str;

size_t PQescapeStringConn(PGconn *conn, char *to, const char *from, size_t length, int *error);
PGresult *PQexec(PGconn *conn, const char *command);
int PQresultStatus(const PGresult *res);
int PQntuples(const PGresult *res);
void PQclear(PGresult *res);
char *PQgetvalue(const PGresult *res, int row_number, int column_number);

#define MAKE_STD_ZVAL(zv) 
#define array_init(zv) 
#define add_assoc_long(zv, k, l) 
#define add_assoc_string(zv, k, s, dup) 
#define add_assoc_bool(zv, k, b) 
#define add_assoc_zval(zv, k, v) 

void php_error_docref(const char *docref, int type, const char *format, ...);
char *estrdup(const char *s);
char *php_strtok_r(char *s, const char *delim, char **last);
void *safe_emalloc(size_t nmemb, size_t size, size_t offset);
void efree(void *ptr);
void smart_str_appends(smart_str *str, const char *append);
void smart_str_appendl(smart_str *str, const char *append, size_t len);
void smart_str_0(smart_str *str);
void smart_str_free(smart_str *str);