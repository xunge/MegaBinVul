#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

typedef int krb5_error_code;
typedef void* krb5_context;
typedef void* krb5_auth_context;
typedef void* krb5_pointer;
typedef void* krb5_keytab;
typedef void* krb5_ticket;
typedef void* krb5_rcache;
typedef unsigned char krb5_octet;
typedef unsigned int krb5_flags;
typedef int krb5_int32;

typedef struct {
    char *data;
    size_t length;
} krb5_data;

typedef struct krb5_principal_data {
    int length;
    char *data;
} *krb5_principal;

typedef struct {
    krb5_principal server;
    int error;
    krb5_data text;
    int stime;
    int susec;
} krb5_error;

#define KRB5_RECVAUTH_SKIP_VERSION 0x1
#define KRB5_RECVAUTH_BADAUTHVERS 0x2
#define KRB5_SENDAUTH_BADAUTHVERS (-1765328243)
#define KRB5_SENDAUTH_BADAPPLVERS (-1765328242)
#define ERROR_TABLE_BASE_krb5 (-1756800000)
#define KRB_ERR_GENERIC 60
#define AP_OPTS_MUTUAL_REQUIRED 0x20
#define ENOMEM 12

static const char *sendauth_version = "KRB5_SENDAUTH_V1.0";

static inline krb5_data make_data(char *data, size_t length) {
    krb5_data d;
    d.data = data;
    d.length = length;
    return d;
}

static inline int data_eq(krb5_data d1, krb5_data d2) {
    return (d1.length == d2.length && memcmp(d1.data, d2.data, d1.length) == 0);
}

static const char *error_message(int code) {
    return "Unknown error";
}

static krb5_error_code krb5_read_message(krb5_context ctx, krb5_pointer fd, krb5_data *data) { return 0; }
static int krb5_net_write(krb5_context ctx, int fd, char *buf, int len) { return 0; }
static krb5_error_code krb5_auth_con_init(krb5_context ctx, krb5_auth_context *auth) { return 0; }
static void krb5_auth_con_getrcache(krb5_context ctx, krb5_auth_context auth, krb5_rcache *rcache) {}
static krb5_error_code krb5_get_server_rcache(krb5_context ctx, krb5_data *data, krb5_rcache *rcache) { return 0; }
static krb5_error_code krb5_auth_con_setrcache(krb5_context ctx, krb5_auth_context auth, krb5_rcache rcache) { return 0; }
static krb5_error_code krb5_rd_req(krb5_context ctx, krb5_auth_context *auth, krb5_data *in, 
                                  krb5_principal server, krb5_keytab keytab, krb5_flags *opts, 
                                  krb5_ticket **ticket) { return 0; }
static void krb5_us_timeofday(krb5_context ctx, int *stime, int *susec) {}
static krb5_error_code krb5_parse_name(krb5_context ctx, const char *name, krb5_principal *princ) { return 0; }
static krb5_error_code krb5_mk_error(krb5_context ctx, krb5_error *error, krb5_data *out) { return 0; }
static void krb5_free_principal(krb5_context ctx, krb5_principal princ) {}
static krb5_error_code krb5_write_message(krb5_context ctx, krb5_pointer fd, krb5_data *data) { return 0; }
static krb5_error_code krb5_mk_rep(krb5_context ctx, krb5_auth_context auth, krb5_data *out) { return 0; }
static void krb5_auth_con_free(krb5_context ctx, krb5_auth_context auth) {}
static void krb5_rc_close(krb5_context ctx, krb5_rcache rcache) {}