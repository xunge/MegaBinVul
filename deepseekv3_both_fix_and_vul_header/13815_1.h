#include <string.h>

#define SQLITE_OK 0
#define SQLITE_ERROR 1

typedef struct sqlite3 sqlite3;
typedef struct Parse Parse;

struct sqlite3 {
    struct {
        int busy;
        char **azInit;
        int imposterTable;
    } init;
};

struct Parse {
    sqlite3 *db;
    int nested;
};

extern struct {
    int bExtraSchemaChecks;
} sqlite3Config;

int sqlite3WritableSchema(sqlite3 *db);
int sqlite3_stricmp(const char *, const char *);
int sqlite3StrNICmp(const char *, const char *, int);
void sqlite3ErrorMsg(Parse *, const char *, ...);