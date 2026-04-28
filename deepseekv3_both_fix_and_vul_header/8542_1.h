#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

typedef int IV;
typedef int STRLEN;
typedef struct SV SV;
typedef struct imp_sth_t imp_sth_t;
typedef struct imp_xxh_t imp_xxh_t;
typedef struct DBIc_t DBIc_t;
typedef struct PerlIO PerlIO;
typedef struct MYSQL_STMT MYSQL_STMT;

#define FALSE 0
#define TRUE 1
#define SQL_NUMERIC 1
#define SQL_DECIMAL 2
#define SQL_INTEGER 3
#define SQL_SMALLINT 4
#define SQL_FLOAT 5
#define SQL_REAL 6
#define SQL_DOUBLE 7
#define SQL_CHAR 8
#define SQL_VARCHAR 9
#define SQL_DATE 10
#define SQL_TIME 11
#define SQL_TIMESTAMP 12
#define SQL_LONGVARCHAR 13
#define SQL_BINARY 14
#define SQL_VARBINARY 15
#define SQL_LONGVARBINARY 16
#define SQL_BIGINT 17
#define SQL_TINYINT 18
#define MYSQL_TYPE_LONG 1
#define MYSQL_TYPE_DOUBLE 2
#define MYSQL_TYPE_BLOB 3
#define MYSQL_TYPE_STRING 4
#define SERVER_PREPARE_VERSION 0
#define MYSQL_VERSION_ID 0
#define JW_ERR_ILLEGAL_PARAM_NUM 0
#define JW_ERR_NOT_IMPLEMENTED 0

#define dTHX
#define D_imp_xxh(sth)
#define D_imp_dbh_from_sth
#define ASYNC_CHECK_RETURN(sth, val) val
#define DBIc_TRACE_LEVEL(imp) 0
#define DBIc_LOGPIO(imp) NULL
#define DBIc_NUM_PARAMS(imp) 0
#define SvIV(sv) 0
#define SvOK(sv) 0
#define looks_like_number(sv) 0
#define neatsvpv(sv, len) ""
#define SvIOK(sv) 0
#define SvNOK(sv) 0
#define SvNV(sv) 0.0
#define SvPV(sv, len) NULL
#define PRId32 "d"
#define croak(fmt, ...) exit(1)

struct imp_sth_params_t {
    SV *value;
};

struct fbind_t {
    union {
        int32_t lval;
        double dval;
    } numeric_val;
    int length;
    int is_null;
};

struct bind_t {
    int buffer_type;
    void *buffer;
    int buffer_length;
};

struct stmt_t {
    struct bind_t *params;
};

struct imp_sth_t {
    struct imp_sth_params_t *params;
    struct fbind_t *fbind;
    struct bind_t *bind;
    int has_been_bound;
    int use_server_side_prepare;
    struct stmt_t *stmt;
    imp_xxh_t *imp_xxh;
};

int bind_param(struct imp_sth_params_t *param, SV *value, IV sql_type);
void do_error(SV *sth, int err_code, const char *err_msg, void *arg);
void PerlIO_printf(PerlIO *io, const char *fmt, ...);