#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

typedef struct dnode {
    struct dnode *next;
    union {
        long i_val;
        char *sval;
        struct {
            struct dnode *h;
        } *lval;
    } data;
    int type;
} dnode;

typedef struct symbol {
    union {
        long i_val;
        char *sval;
        struct {
            struct dnode *h;
        } *lval;
    } data;
} symbol;

typedef struct node {
    struct node *next;
    void *data;
} node;

typedef struct list {
    node *h;
} list;

typedef struct sql_schema sql_schema;

typedef struct sql_key {
    int type;
    list *columns;
} sql_key;

typedef struct sql_pkey {
    sql_key k;
} sql_pkey;

typedef struct sql_table {
    sql_schema *s;
    struct {
        char *name;
    } base;
    void *keys;
    void *idxs;
    sql_pkey *pkey;
} sql_table;

typedef struct sql_fkey sql_fkey;

typedef struct sql_column {
    struct {
        char *name;
    } base;
    struct {
        int dummy;
    } type;
} sql_column;

typedef struct sql_kc {
    sql_column *c;
} sql_kc;

typedef struct mvc {
    char errstr[1];
    struct {
        int status;
    } *session;
    void *sa;
    void *ta;
} mvc;

#define SQL_OK 0
#define SQL_ERR -1
#define ERR_NOTFOUND -2
#define MAL_MALLOC_FAIL -3
#define SQLSTATE(x) "42" #x
#define SQL_KEY_PRIMARY 0
#define SQL_KEY_FOREIGN 1
#define type_int 0

enum {
    pkey = SQL_KEY_PRIMARY,
    fkey = SQL_KEY_FOREIGN
};

typedef char *str;

extern char *qname_schema(void *);
extern char *qname_schema_object(void *);
extern sql_table *find_table_or_view_on_scope(mvc *, sql_schema *, char *, char *, const char *, bool);
extern int sql_error(mvc *, int, const char *, ...);
extern int ol_find_name(void *, const char *);
extern int mvc_bind_key(mvc *, sql_schema *, const char *);
extern int mvc_bind_idx(mvc *, sql_schema *, const char *);
extern sql_key *mvc_bind_ukey(sql_table *, list *);
extern int mvc_create_fkey(sql_fkey **, mvc *, sql_table *, const char *, int, sql_key *, int, int);
extern sql_column *mvc_bind_column(mvc *, sql_table *, char *);
extern int foreign_key_check_types(void *, void *);
extern char *sql_subtype_string(void *, void *);
extern int mvc_create_fkc(mvc *, sql_fkey *, sql_column *);
extern int mvc_create_key_done(mvc *, sql_key *);
extern bool isTempSchema(sql_schema *);
extern bool isTempTable(sql_table *);
extern bool isGlobal(sql_table *);
extern bool isUnloggedTable(sql_table *);
extern list *sa_list(void *);
extern void list_append(list *, char *);