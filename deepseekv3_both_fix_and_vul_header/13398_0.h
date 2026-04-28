#include <stddef.h>

typedef struct client_connection_t client_connection_t;
typedef struct dbe_table_t dbe_table_t;
typedef struct dbe_key_t dbe_key_t;
typedef struct query_t query_t;
typedef void* caddr_t;

extern client_connection_t *sqlc_client(void);
extern void sqlc_set_client(client_connection_t *);
extern dbe_table_t *sch_name_to_table(void *, const char *);
extern dbe_key_t *tb_find_key(dbe_table_t *, const char *, void *);
extern query_t *eql_compile_2(const char *, client_connection_t *, caddr_t *, int);
extern void log_error(const char *, ...);
extern char *err_first_line(const char *);
extern void dk_free_tree(caddr_t);
extern caddr_t qr_quick_exec(query_t *, client_connection_t *, const char *, void *, int);
extern void qr_free(query_t *);
extern void local_commit(client_connection_t *);

extern client_connection_t *bootstrap_cli;
extern unsigned int first_id;
extern struct {
    void *wi_schema;
} wi_inst;

#define QC_ERRNO 0
#define QC_ERROR_STRING 1
#define SQL_NO_DATA_FOUND ((void*)1)
#define SQLC_DEFAULT 0
#define DD_FIRST_PRIVATE_OID 0
#define DD_FIRST_FREE_OID 0