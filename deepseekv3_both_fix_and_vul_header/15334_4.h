#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_QUAL_NAME_LEN 128
#define MAX_NAME_LEN 128

typedef struct query_instance query_instance_t;
typedef struct client_connection_t client_connection_t;
typedef struct query_t query_t;
typedef struct local_cursor_t local_cursor_t;
typedef struct dbe_table_t dbe_table_t;
typedef long ptrlong;
typedef void* box_t;

struct query_instance {
    client_connection_t *qi_client;
};

typedef struct ST ST;
struct ST {
    union {
        struct {
            ST *left;
            ST *right;
        } bin_exp;
    } _;
};

#define BOP_NOT 0
#define SELECT_STMT 0
#define TABLE_EXP 0
#define TABLE_REF 0
#define TABLE_DOTTED 0
#define COMPOUND_STMT 0
#define IF_STMT 0
#define COND_CLAUSE 0
#define CALL_STMT 0
#define TRIGGER_DEF 0
#define TRIG_BEFORE 0
#define TRIG_INSERT 0
#define TRIG_UPDATE 0
#define OLD_ALIAS 0

#define SQL_SUCCESS 0
#define SQLC_DO_NOT_STORE_PROC 0
#define GPF_T (void)0
#define CALLER_LOCAL NULL
#define QI_POISON_TRX(qi) (void)0
#define ST_P(st, op) 0

extern client_connection_t *bootstrap_cli;
extern void sch_split_name(const char *, caddr_t, char *, char *, char *);
extern int sqlc_contains_args(ST *, int *);
extern void sqlr_new_error(const char *, const char *, const char *);
extern ST *listst(int, ...);
extern ST *list(int, ...);
extern box_t box_num(int);
extern box_t box_copy_tree(box_t);
extern box_t box_string(caddr_t);
extern box_t box_dv_short_string(const char *);
extern caddr_t sqlp_box_id_upcase(caddr_t);
extern ST *sqlp_infoschema_redirect(ST *);
extern query_t *sql_compile_1(const char *, client_connection_t *, caddr_t *, int, ST *, void *);
extern void dk_free_tree(box_t);
extern caddr_t qr_rec_exec(query_t *, client_connection_t *, local_cursor_t **, void *, void *, int);
extern int lc_next(local_cursor_t *);
extern void lc_free(local_cursor_t *);
extern void qr_free(query_t *);
extern caddr_t srv_make_new_error(const char *, const char *, const char *, ...);
extern void sqlr_resignal(caddr_t);
extern void ddl_adj_internal_name(char *);
extern dbe_table_t *sch_name_to_table(void *, caddr_t);
extern void *isp_schema(void *);
extern void tb_drop_trig_def(dbe_table_t *, const char *);