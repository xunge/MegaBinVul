#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef long ptrlong;
typedef int key_id_t;
typedef struct client_connection_t client_connection_t;
typedef struct local_cursor_t local_cursor_t;
typedef struct dk_set_t *dk_set_t;
typedef struct dbe_table_t dbe_table_t;

typedef struct query_instance_t {
    client_connection_t *qi_client;
} query_instance_t;

#define K_MAX_PARTS 32
#define BOX_ELEMENTS(arr) (sizeof(arr)/sizeof((arr)[0]))
#define DV_ARRAY_OF_POINTER 1
#define QRP_STR 1
#define QRP_INT 2
#define CM_MSSQL 1
#define KO_NO_PK(opts) (0)

static int case_mode = CM_MSSQL;

extern void sqlr_new_error(const char*, const char*, const char*, ...);
extern void qr_rec_exec(const char*, client_connection_t*, local_cursor_t**, query_instance_t*, void*, int, ...);
extern int lc_next(local_cursor_t*);
extern caddr_t lc_get_col(local_cursor_t*, const char*);
extern void lc_free(local_cursor_t*);
extern void ddl_check_duplicate_cols(void*, caddr_t*);
extern void ddl_insert_sec_key_parts(query_instance_t*, key_id_t, char*, char*, caddr_t*, int, key_id_t*, int, int, int);
extern void ddl_key_options(query_instance_t*, char*, key_id_t, caddr_t*);
extern void ddl_key_opt(query_instance_t*, char*, key_id_t);
extern void ddl_table_changed(query_instance_t*, char*);
extern void inx_opt_cluster(query_instance_t*, caddr_t, caddr_t, caddr_t*);
extern dbe_table_t* qi_name_to_table(query_instance_t*, char*);
extern void ddl_create_subtable_keys(query_instance_t*, dbe_table_t*, char*, key_id_t, key_id_t);
extern caddr_t box_string(const char*);
extern caddr_t box_dv_short_string(const char*);
extern void dk_free_box(caddr_t);
extern void dk_set_push(dk_set_t*, caddr_t);
extern caddr_t list_to_array(dk_set_t);
extern void dk_free_tree(caddr_t);
extern caddr_t dk_alloc_box(size_t, int);
extern size_t box_length(caddr_t);
extern ptrlong unbox(caddr_t);
extern int CASEMODESTRCMP(const char*, const char*);

static const char* find_primary_stmt = "";
static const char* get_key_parts_stmt = "";