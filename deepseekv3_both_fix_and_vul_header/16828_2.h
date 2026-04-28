#include <stdint.h>
#include <stdbool.h>

#define FALSE false
#define TRUE true
typedef bool bool_t;
typedef int32_t krb5_int32;
typedef int16_t krb5_int16;
typedef krb5_int32 krb5_timestamp;
typedef krb5_int32 krb5_deltat;
typedef krb5_int32 krb5_flags;
typedef krb5_int32 krb5_kvno;

typedef enum {
    XDR_ENCODE = 0,
    XDR_DECODE = 1,
    XDR_FREE = 2
} xdr_op;

typedef struct {
    xdr_op x_op;
} XDR;

typedef struct {
    int dummy;
} krb5_key_data;

typedef struct {
    int dummy;
} krb5_tl_data;

typedef struct {
    int dummy;
} krb5_principal_data;
typedef krb5_principal_data *krb5_principal;

typedef struct {
    krb5_principal principal;
    krb5_timestamp princ_expire_time;
    krb5_timestamp last_pwd_change;
    krb5_timestamp pw_expiration;
    krb5_deltat max_life;
    krb5_principal mod_name;
    krb5_timestamp mod_date;
    krb5_flags attributes;
    krb5_kvno kvno;
    krb5_kvno mkvno;
    char *policy;
    long aux_attributes;
    krb5_deltat max_renewable_life;
    krb5_timestamp last_success;
    krb5_timestamp last_failed;
    krb5_kvno fail_auth_count;
    krb5_int16 n_key_data;
    krb5_int16 n_tl_data;
    krb5_tl_data *tl_data;
    krb5_key_data *key_data;
} kadm5_principal_ent_rec;

typedef char* caddr_t;

bool_t xdr_krb5_principal(XDR *xdrs, krb5_principal *objp);
bool_t xdr_krb5_timestamp(XDR *xdrs, krb5_timestamp *objp);
bool_t xdr_krb5_deltat(XDR *xdrs, krb5_deltat *objp);
bool_t xdr_nulltype(XDR *xdrs, void **objp, bool_t (*xdr_func)(XDR *, void *));
bool_t xdr_krb5_flags(XDR *xdrs, krb5_flags *objp);
bool_t xdr_krb5_kvno(XDR *xdrs, krb5_kvno *objp);
bool_t xdr_nullstring(XDR *xdrs, char **objp);
bool_t xdr_long(XDR *xdrs, long *objp);
bool_t xdr_krb5_int16(XDR *xdrs, krb5_int16 *objp);
bool_t xdr_krb5_tl_data(XDR *xdrs, krb5_tl_data *objp);
bool_t xdr_krb5_key_data_nocontents(XDR *xdrs, krb5_key_data *objp);
bool_t xdr_array(XDR *xdrs, caddr_t *addrp, unsigned int *sizep,
                unsigned int maxsize, unsigned int elsize,
                bool_t (*elproc)(XDR *, caddr_t));