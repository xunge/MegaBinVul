#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int SV;
typedef int AV;
typedef int PerlIO;

typedef struct MYSQL_BIND MYSQL_BIND;
typedef struct MYSQL_STMT MYSQL_STMT;
typedef struct imp_sth_phb_t imp_sth_phb_t;

struct MYSQL_BIND {
    int buffer_type;
    void* buffer;
    int* length;
    char* is_null;
};

struct MYSQL_STMT {
    struct {
        int type;
    } *fields;
};

struct imp_sth_phb_t {
    int length;
    int is_null;
};

typedef struct imp_sth_t {
    int use_server_side_prepare;
    int fetch_done;
    int done_desc;
    void* result;
    int currow;
    int use_mysql_use_result;
    AV* av_attr[1];
    MYSQL_STMT* stmt;
    int has_been_bound;
    MYSQL_BIND* bind;
    imp_sth_phb_t* fbind;
    int is_async;
    int NUM_PARAMS;
    void* params;
} imp_sth_t;

typedef struct imp_dbh_t {
    int TRACE_LEVEL;
    PerlIO* LOGPIO;
    void* pmysql;
    int bind_comment_placeholders;
    int use_server_side_prepare;
    int use_mysql_use_result;
} imp_dbh_t;

typedef struct imp_xxh_t {
    int TRACE_LEVEL;
    PerlIO* LOGPIO;
    void* pmysql;
} imp_xxh_t;

#define DBIc_TRACE_LEVEL(imp) ((imp)->TRACE_LEVEL)
#define DBIc_LOGPIO(imp) ((imp)->LOGPIO)
#define DBIc_NUM_PARAMS(imp) ((imp)->NUM_PARAMS)
#define DBIc_IMPSET_on(imp)

#define SERVER_PREPARE_VERSION 0
#define CALL_PLACEHOLDER_VERSION 0
#define LIMIT_PLACEHOLDER_VERSION 0
#define MYSQL_ASYNC 0
#define MYSQL_VERSION_ID 0

#define TRUE 1
#define FALSE 0
#define Nullav NULL

#define dTHX
#define aTHX_

#define D_imp_xxh(sth) imp_xxh_t *imp_xxh = (imp_xxh_t *)sth
#define D_imp_dbh_from_sth imp_dbh_t *imp_dbh = (imp_dbh_t *)imp_xxh

#define DBD_ATTRIB_GET_SVP(attribs, name, len) NULL

#define AV_ATTRIB_LAST 1

#define ER_UNSUPPORTED_PS 0
#define MYSQL_TYPE_STRING 0
#define MYSQL_TYPE_VAR_STRING 1

#define SvTRUE(sv) 1

extern void* alloc_bind(int);
extern void* alloc_fbind(int);
extern void* alloc_param(int);
extern int count_params(imp_dbh_t*, void*, int);
extern void do_error(SV*, int, const char*, const char*);
extern void mysql_st_free_result_sets(SV*, imp_sth_t*);
extern int mysql_errno(void*);
extern char* mysql_error(void*);
extern MYSQL_STMT* mysql_stmt_init(void*);
extern int mysql_stmt_prepare(MYSQL_STMT*, char*, int);
extern int mysql_stmt_errno(MYSQL_STMT*);
extern char* mysql_stmt_error(MYSQL_STMT*);
extern char* mysql_sqlstate(void*);
extern void mysql_stmt_close(MYSQL_STMT*);
extern int mysql_stmt_param_count(MYSQL_STMT*);
extern int mysql_to_perl_type(int);
extern int PerlIO_printf(PerlIO*, const char*, ...);