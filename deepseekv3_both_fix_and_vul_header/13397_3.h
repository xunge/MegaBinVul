#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client_connection_t client_connection_t;
typedef struct query_t query_t;
typedef struct dbe_column_t dbe_column_t;

typedef struct dbe_table_t {
    char *tb_name;
} dbe_table_t;

typedef struct query_instance_t {
    client_connection_t *qi_client;
} query_instance_t;

typedef char *caddr_t;

#define SQL_SUCCESS 0
#define SQLC_DEFAULT 0
#define COL_NOT_NULL 0
#define COL_DEFAULT 0
#define QRP_STR 0
#define QRP_RAW 0

#define AS_DBA(qi, expr) expr
#define QI_POISON_TRX(qi)
#define ptrlong long

extern caddr_t bootstrap_cli;
extern dbe_table_t *qi_name_to_table(query_instance_t *qi, const char *table);
extern dbe_column_t *tb_name_to_column(dbe_table_t *tb, const char *col);
extern int count_exceed(query_instance_t *qi, const char *table, int flag, void *arg);
extern int ddl_col_opt_set(caddr_t *col, caddr_t opt);
extern caddr_t box_copy_tree(caddr_t col);
extern void sqlr_new_error(const char *code, const char *state, const char *fmt, ...);
extern void sql_error_if_remote_table(dbe_table_t *tb);
extern void sqlr_resignal(caddr_t err);
extern query_t *sql_compile_static(const char *query, caddr_t cli, caddr_t *err, int flags);
extern caddr_t qr_rec_exec(query_t *proc, client_connection_t *cli, void *arg1, void *arg2, void *arg3, int argc, ...);