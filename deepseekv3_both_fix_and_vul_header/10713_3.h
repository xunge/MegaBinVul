#include <stdlib.h>
#include <stdio.h>

typedef struct imp_sth_t {
    void *bind;
    void *fbind;
    void *fbh;
    void *stmt;
    void *params;
    void *buffer;
    void **av_attr;
} imp_sth_t;

typedef struct imp_sth_fbh_t {
    void *data;
} imp_sth_fbh_t;

typedef struct imp_xxh_t imp_xxh_t;
typedef struct sv SV;

#define DBIc_NUM_PARAMS(imp_sth) 0
#define DBIc_TRACE_LEVEL(imp_xxh) 0
#define DBIc_LOGPIO(imp_xxh) NULL
#define DBIc_NUM_FIELDS(imp_sth) 0
#define DBIc_PARENT_H(imp_sth) NULL
#define DBIc_IMPSET_off(imp_sth)
#define SERVER_PREPARE_VERSION 0
#define MYSQL_VERSION_ID 0
#define dTHX
#define dTHR
#define dTHXa(a)
#define aTHX
#define aTHX_
#define D_imp_xxh(sth)
#define AV_ATTRIB_LAST 0
#define Nullav NULL
#define Safefree free

void free_bind(void *);
void free_fbind(void *);
void free_fbuffer(void *);
void free_param(void *, int);
void do_error(void *, int, const char *, const char *);
int mysql_stmt_close(void *);
unsigned int mysql_stmt_errno(void *);
const char *mysql_stmt_error(void *);
const char *mysql_stmt_sqlstate(void *);
int PerlIO_printf(void *, const char *, ...);
void SvREFCNT_dec(void *);