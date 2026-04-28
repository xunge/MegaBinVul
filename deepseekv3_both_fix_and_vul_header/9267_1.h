#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_mysql MYSQL;
typedef struct st_mysql_res MYSQL_RES;
typedef char **MYSQL_ROW;
typedef unsigned long ulong;

#define UNINIT_VAR(x) x
#define NullS ((char *)0)
#define NAME_LEN 64

extern char *my_progname;
extern int opt_count;
extern int opt_show_keys;

char *strmov(char *dst, const char *src);
char *strxmov(char *dst, const char *src, ...);
char *strxnmov(char *dst, size_t len, const char *src, ...);
int my_snprintf(char *str, size_t size, const char *format, ...);
unsigned long long strtoull(const char *nptr, char **endptr, int base);

int mysql_select_db(MYSQL *mysql, const char *db);
int mysql_query(MYSQL *mysql, const char *q);
MYSQL_RES *mysql_store_result(MYSQL *mysql);
MYSQL_ROW mysql_fetch_row(MYSQL_RES *result);
void mysql_free_result(MYSQL_RES *result);
char *mysql_error(MYSQL *mysql);
unsigned long mysql_num_rows(MYSQL_RES *res);

void print_res_header(MYSQL_RES *result);
void print_res_row(MYSQL_RES *result, MYSQL_ROW row);
void print_res_top(MYSQL_RES *result);