#include <stdbool.h>

typedef struct imp_dbh_t {
    struct {
        int auto_reconnects_ok;
        int auto_reconnects_failed;
    } stats;
    bool bind_type_guessing;
    bool bind_comment_placeholders;
    bool has_transactions;
    bool auto_reconnect;
    bool enable_utf8;
    void* pmysql;
} imp_dbh_t;

typedef struct sv SV;
typedef struct my_perl THX;
#define dTHX THX *aTHX
#define aTHX_ aTHX,
#define dTHR
#define D_imp_xxh(dbh)
#define DBIc_TRACE_LEVEL(imp_xxh) 0
#define DBIc_LOGPIO(imp_xxh) NULL
#define PerlIO_printf(f, ...)
#define DBIc_ACTIVE_on(imp_dbh)
#define DBIc_on(imp_dbh, flag)
#define DBIcf_IMPSET 0
#define FALSE false
#define TRUE true
#define SERVER_PREPARE_VERSION 0
#define MYSQL_VERSION_ID 0
#define sv_utf8_decode
#define mysql_errno(pmysql) 0
#define mysql_error(pmysql) ""
#define mysql_sqlstate(pmysql) ""

int my_login(THX *aTHX, SV* dbh, imp_dbh_t* imp_dbh);
void do_error(SV* dbh, unsigned int errno, const char* error, const char* sqlstate);