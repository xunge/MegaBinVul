#include <string.h>
#include <stdlib.h>

typedef struct {
    char *c;
    size_t len;
    size_t a;
} smart_str;

typedef struct pg_conn PGconn;

#define SUCCESS 0

char *estrdup(const char *s);
char *php_strtok_r(char *str, const char *delim, char **saveptr);
int _php_pgsql_detect_identifier_escape(const char *str, size_t len);
char *PGSQLescapeIdentifier(PGconn *conn, const char *str, size_t len);
void PGSQLfree(char *ptr);
void smart_str_appendl(smart_str *str, const char *s, size_t len);
void smart_str_appends(smart_str *str, const char *s);
void smart_str_appendc(smart_str *str, char c);
void efree(void *ptr);