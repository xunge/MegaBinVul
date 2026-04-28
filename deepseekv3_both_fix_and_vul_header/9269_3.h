#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NAME_LEN 64
#define NullS ((char *)0)

typedef struct st_mysql MYSQL;
typedef struct st_mysql_res MYSQL_RES;
typedef struct st_mysql_field {
    char *name;
    char *org_name;
    char *table;
    char *org_table;
    char *db;
    char *catalog;
    char *def;
    unsigned long length;
    unsigned long max_length;
    unsigned int name_length;
    unsigned int org_name_length;
    unsigned int table_length;
    unsigned int org_table_length;
    unsigned int db_length;
    unsigned int catalog_length;
    unsigned int def_length;
    unsigned int flags;
    unsigned int decimals;
    unsigned int charsetnr;
    unsigned int type;  // Changed from enum to unsigned int
} MYSQL_FIELD;
typedef char **MYSQL_ROW;

extern char *my_progname;
extern int opt_table_type;
extern int opt_verbose;

extern int mysql_select_db(MYSQL *mysql, const char *db);
extern char *mysql_error(MYSQL *mysql);
extern unsigned long mysql_real_escape_string(MYSQL *mysql, char *to, const char *from, unsigned long length);
extern int mysql_query(MYSQL *mysql, const char *q);
extern MYSQL_RES *mysql_store_result(MYSQL *mysql);
extern MYSQL_FIELD *mysql_fetch_field(MYSQL_RES *result);
extern MYSQL_ROW mysql_fetch_row(MYSQL_RES *result);
extern MYSQL_RES *mysql_list_fields(MYSQL *mysql, const char *table, const char *wild);
extern unsigned int mysql_num_fields(MYSQL_RES *result);
extern void mysql_free_result(MYSQL_RES *result);
extern char *strmov(char *dst, const char *src);
extern int my_snprintf(char *str, size_t size, const char *format, ...);
extern void print_header(const char *head, uint head_length, ...);
extern void print_row(const char *head, uint head_length, ...);
extern void print_trailer(uint head_length, ...);