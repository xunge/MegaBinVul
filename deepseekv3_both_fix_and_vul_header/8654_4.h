#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_PREPARE_VERSION 40100
#define MYSQL_VERSION_5_0 50000
#define FIELD_CHARSETNR_VERSION 40100
#define MULTIPLE_RESULT_SET_VERSION 40100
#define NEW_DATATYPE_VERSION 50000

#define JW_ERR_SEQUENCE 1
#define MYSQL_ASYNC 0
#define MYSQL_DATA_TRUNCATED 100
#define MYSQL_NO_DATA 100

/* MySQL type constants */
#define MYSQL_TYPE_DECIMAL    0
#define MYSQL_TYPE_TINY       1
#define MYSQL_TYPE_SHORT      2
#define MYSQL_TYPE_LONG       3
#define MYSQL_TYPE_FLOAT      4
#define MYSQL_TYPE_DOUBLE     5
#define MYSQL_TYPE_NULL       6
#define MYSQL_TYPE_TIMESTAMP  7
#define MYSQL_TYPE_LONGLONG   8
#define MYSQL_TYPE_INT24      9
#define MYSQL_TYPE_DATE      10
#define MYSQL_TYPE_TIME      11
#define MYSQL_TYPE_DATETIME  12
#define MYSQL_TYPE_YEAR      13
#define MYSQL_TYPE_NEWDATE   14
#define MYSQL_TYPE_VARCHAR   15
#define MYSQL_TYPE_BIT       16
#define MYSQL_TYPE_JSON     245
#define MYSQL_TYPE_NEWDECIMAL 246
#define MYSQL_TYPE_ENUM     247
#define MYSQL_TYPE_SET      248
#define MYSQL_TYPE_TINY_BLOB 249
#define MYSQL_TYPE_MEDIUM_BLOB 250
#define MYSQL_TYPE_LONG_BLOB 251
#define MYSQL_TYPE_BLOB     252
#define MYSQL_TYPE_VAR_STRING 253
#define MYSQL_TYPE_STRING   254
#define MYSQL_TYPE_GEOMETRY 255

typedef char** MYSQL_ROW;
typedef struct st_mysql {
    struct {
        int last_errno;
    } net;
} MYSQL;
typedef struct st_mysql_field {
    int type;
    int flags;
    int charsetnr;
} MYSQL_FIELD;
typedef struct st_mysql_bind {
    int buffer_type;
    int is_unsigned;
    unsigned long *length;
    unsigned long buffer_length;
    char *buffer;
} MYSQL_BIND;
typedef struct st_mysql_stmt MYSQL_STMT;

typedef struct {
    int is_null;
    unsigned long length;
    char *data;
    double ddata;
    long ldata;
    int error;
    int charsetnr;
} imp_sth_fbh_t;

typedef struct {
    MYSQL *pmysql;
    int async_query_in_flight;
    int enable_utf8;
    int enable_utf8mb4;
} imp_dbh_t;

typedef struct {
    void *result;
    MYSQL_STMT *stmt;
    MYSQL_BIND *buffer;
    imp_sth_fbh_t *fbh;
    int use_server_side_prepare;
    int done_desc;
    int fetch_done;
    int row_num;
    int currow;
    int active;
    int trace_level;
    FILE *logpio;
    int num_fields;
    void *fields_av;
} imp_sth_t;

#define DBIc_TRACE_LEVEL(imp) ((imp)->trace_level)
#define DBIc_LOGPIO(imp) ((imp)->logpio)
#define DBIc_ACTIVE(imp) ((imp)->active)
#define DBIc_is(imp, flag) (1)
#define DBIc_DBISTATE(imp) ((dbistate_t*)0)
#define DBIc_FIELDS_AV(imp) ((imp)->fields_av)
#define DBIc_NUM_FIELDS(imp) ((imp)->num_fields)
#define DBIcf_ChopBlanks 1

#define dTHX void *my_perl = NULL
#define D_imp_dbh_from_sth imp_dbh_t *imp_dbh = (imp_dbh_t*)0
#define D_imp_xxh(sth) imp_sth_t *imp_xxh = (imp_sth_t*)0

#define Nullav ((void*)0)
#define SvOK_off(sv) (0)
#define SvNOK_only(sv) (0)
#define SvIOK_only(sv) (0)
#define SvIOK_only_UV(sv) (0)
#define SvREADONLY(sv) (0)
#define SvREADONLY_off(sv) (0)
#define SvREADONLY_on(sv) (0)

#define BINARY_FLAG 1
#define UNSIGNED_FLAG 2

typedef struct {
    void* (*get_fbav)(imp_sth_t*);
} dbistate_t;

typedef void SV;
typedef void AV;
typedef size_t STRLEN;

/* Perl scalar manipulation functions */
void sv_setpvn(SV *sv, const char *ptr, size_t len);
double SvNV(SV *sv);
unsigned long SvUV(SV *sv);
long SvIV(SV *sv);
void sv_setnv(SV *sv, double num);
void sv_setuv(SV *sv, unsigned long num);
void sv_setiv(SV *sv, long num);

int PerlIO_printf(FILE *fh, const char *fmt, ...);
void* dbd_describe(SV *sth, imp_sth_t* imp_sth);
void dbd_st_finish(SV *sth, imp_sth_t* imp_sth);
void do_error(SV *sth, int errno, const char *error, const char *state);
int mysql_db_async_result(SV *sth, void **result);
int mysql_to_perl_type(int mysql_type);
int mysql_stmt_fetch(MYSQL_STMT *stmt);
int mysql_stmt_field_count(MYSQL_STMT *stmt);
int mysql_stmt_errno(MYSQL_STMT *stmt);
const char* mysql_stmt_error(MYSQL_STMT *stmt);
const char* mysql_stmt_sqlstate(MYSQL_STMT *stmt);
int mysql_stmt_affected_rows(MYSQL_STMT *stmt);
int mysql_stmt_fetch_column(MYSQL_STMT *stmt, MYSQL_BIND *bind, int column, unsigned long offset);
int mysql_num_fields(void *result);
long long mysql_num_rows(void *result);
long long mysql_affected_rows(MYSQL *mysql);
MYSQL_ROW mysql_fetch_row(void *result);
MYSQL_FIELD *mysql_fetch_fields(void *result);
unsigned long *mysql_fetch_lengths(void *result);
int mysql_errno(MYSQL *mysql);
const char *mysql_error(MYSQL *mysql);
const char *mysql_sqlstate(MYSQL *mysql);
int mysql_more_results(MYSQL *mysql);
int av_len(AV *av);
void av_store(AV *av, int key, SV *val);
SV* newSV(int value);
void SvREFCNT_dec(SV *sv);
SV* av_pop(AV *av);
SV** AvARRAY(AV *av);