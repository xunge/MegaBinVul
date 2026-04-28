#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NAME_LEN 64

typedef struct st_mysql MYSQL;
typedef struct st_mysql_res {
    unsigned int row_count;
    // 其他必要字段...
} MYSQL_RES;

typedef struct st_mysql_field {
    unsigned int max_length;
    // 其他必要字段...
} MYSQL_FIELD;

typedef char **MYSQL_ROW;
typedef unsigned long long my_ulonglong;

struct charset_info_st {
    // 必要字段...
};

extern char *my_progname;
extern int opt_status;
extern int opt_verbose;
extern const char *NullS;
extern struct charset_info_st my_charset_latin1;

typedef unsigned int uint;
typedef unsigned long ulong;

// MySQL API 函数声明
MYSQL_RES *mysql_list_dbs(MYSQL *mysql, const char *wild);
const char *mysql_error(MYSQL *mysql);
unsigned int mysql_num_rows(MYSQL_RES *res);
MYSQL_ROW mysql_fetch_row(MYSQL_RES *res);
void mysql_free_result(MYSQL_RES *res);
MYSQL_FIELD *mysql_fetch_field(MYSQL_RES *res);
int mysql_select_db(MYSQL *mysql, const char *db);
MYSQL_RES *mysql_list_tables(MYSQL *mysql, const char *wild);
my_ulonglong mysql_affected_rows(MYSQL *mysql);
int mysql_query(MYSQL *mysql, const char *query);
MYSQL_RES *mysql_store_result(MYSQL *mysql);

// 其他函数声明
int my_strcasecmp(const struct charset_info_st *cs, const char *s, const char *t);
int list_table_status(MYSQL *mysql, const char *db, const char *table);
int list_tables(MYSQL *mysql, const char *db, const char *table);
void print_header(const char *header, uint length, ...);
void print_row(const char *row, uint length, ...);
void print_trailer(uint length, ...);
char *strmov(char *dst, const char *src);