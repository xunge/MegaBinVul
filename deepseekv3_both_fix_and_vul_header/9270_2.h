#include <stdio.h>
#include <string.h>

#define NullS ((char *) 0)
#define NAME_LEN 512
extern char *my_progname;
#define ER_PARSE_ERROR 1064

typedef struct st_mysql MYSQL;
typedef struct st_mysql_res MYSQL_RES;
typedef char **MYSQL_ROW;

char *strxmov(char *dst, ...);
char *strxnmov(char *dst, unsigned int len, ...);
int my_snprintf(char *str, size_t size, const char *format, ...);
int mysql_query(MYSQL *mysql, const char *query);
MYSQL_RES *mysql_store_result(MYSQL *mysql);
char *mysql_error(MYSQL *mysql);
unsigned int mysql_errno(MYSQL *mysql);
MYSQL_ROW mysql_fetch_row(MYSQL_RES *result);
void mysql_free_result(MYSQL_RES *result);

void print_res_header(MYSQL_RES *result);
void print_res_row(MYSQL_RES *result, MYSQL_ROW row);
void print_res_top(MYSQL_RES *result);