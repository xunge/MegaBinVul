#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZM_SQL_MED_BUFSIZ 1024

typedef struct MYSQL MYSQL;
typedef struct MYSQL_RES MYSQL_RES;
typedef char** MYSQL_ROW;

extern MYSQL dbconn;

class User {
public:
    User(MYSQL_ROW dbrow);
    const char* getUsername();
};

void Error(const char* format, ...);
void Warning(const char* format, ...);
void Info(const char* format, ...);

unsigned long mysql_real_escape_string(MYSQL* mysql, char* to, const char* from, unsigned long length);
int mysql_query(MYSQL* mysql, const char* query);
const char* mysql_error(MYSQL* mysql);
unsigned int mysql_errno(MYSQL* mysql);
MYSQL_RES* mysql_store_result(MYSQL* mysql);
unsigned int mysql_num_rows(MYSQL_RES* result);
void mysql_free_result(MYSQL_RES* result);
MYSQL_ROW mysql_fetch_row(MYSQL_RES* result);