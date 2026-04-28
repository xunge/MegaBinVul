#include <stdlib.h>
#include <assert.h>

typedef int sqlid;
typedef int oid;

typedef enum {
    LOG_OK,
    DROP_CASCADE_START,
    DROP_CASCADE,
    ddl,
    dml
} constants;

typedef struct base {
    sqlid id;
    int deleted;
} base;

typedef struct sql_column {
    base base;
    int colnr;
    struct sql_table *t;
} sql_column;

typedef struct node {
    void *data;
    struct node *next;
} node;

typedef struct list {
    node *h;
} list;

typedef struct columns {
    list *l;
} columns;

typedef struct sql_table {
    base base;
    columns *columns;
} sql_table;

typedef struct sql_trans {
    struct sqlstore *store;
    struct list *dropped;
} sql_trans;

typedef struct table_api {
    oid (*column_find_row)(sql_trans *, sql_column *, sqlid *, void *);
    int (*column_update_value)(sql_trans *, sql_column *, oid, int *);
} table_api;

typedef struct storage_api {
    int (*drop_col)(sql_trans *, sql_column *);
} storage_api;

typedef struct sqlstore {
    table_api table_api;
    storage_api storage_api;
} sqlstore;

typedef void (*fdestroy)(void *);

#define MNEW(type) ((type*)malloc(sizeof(type)))
#define _DELETE(ptr) free(ptr)

int isGlobal(sql_table *t);
int isGlobalTemp(sql_table *t);
int isTempTable(sql_table *t);
int isNew(sql_column *col);
int isDeclaredTable(sql_table *t);
int is_oid_nil(oid rid);
sql_table *find_sql_table(sql_trans *tr, void *schema, const char *name);
void *find_sql_schema(sql_trans *tr, const char *name);
sql_column *find_sql_column(sql_table *t, const char *name);
int new_table(sql_trans *tr, sql_table *t, sql_table **dup);
int sql_trans_add_dependency_change(sql_trans *tr, sqlid id, int type);
int sql_trans_add_dependency(sql_trans *tr, sqlid id, int type);
int sys_drop_column(sql_trans *tr, sql_column *col, int drop_action);
void ol_del(void *columns, sqlstore *store, node *n);
void id_destroy(void *id);
list *list_create(fdestroy destroy);
int list_append(list *list, void *data);
void list_destroy(list *list);
void *dup_base(base *b);