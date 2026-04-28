#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int OM_uint32;
typedef unsigned int gss_qop_t;
typedef unsigned int krb5_keyusage;
typedef unsigned int krb5_ui_4;
typedef unsigned long long gssint_uint64;

#define KG_USAGE_SIGN 0
#define KG_USAGE_SEAL 1
#define SEAL_ALG_NONE 0
#define SEAL_ALG_1 1
#define SEAL_ALG_DES3KD 2
#define SEAL_ALG_MICROSOFT_RC4 3
#define SGN_ALG_3 3
#define SGN_ALG_DES_MAC_MD5 4
#define SGN_ALG_MD2_5 5
#define SGN_ALG_HMAC_MD5 6
#define SGN_ALG_HMAC_SHA1_DES3_KD 7
#define SGN_ALG_DES_MAC 8
#define CKSUMTYPE_RSA_MD5 0
#define CKSUMTYPE_HMAC_MD5_ARCFOUR 0
#define CKSUMTYPE_HMAC_SHA1_DES3 0
#define KG_TOK_WRAP_MSG 0
#define GSS_C_DCE_STYLE 0
#define GSS_C_QOP_DEFAULT 0
#define G_BAD_DIRECTION 0
#define GSS_IOV_BUFFER_TYPE_TRAILER 0
#define KRB5_BAD_MSIZE 0
#define GSS_S_DEFECTIVE_TOKEN 0
#define GSS_S_BAD_SIG 0
#define GSS_S_FAILURE 0
#define GSS_S_COMPLETE 0

typedef struct {
    size_t length;
    void *contents;
    unsigned int checksum_type;
} krb5_checksum;

typedef struct {
    size_t length;
    void *contents;
    int enctype;
} krb5_keyblock;

typedef struct gss_iov_buffer_desc {
    int type;
    struct {
        void *value;
        size_t length;
    } buffer;
} gss_iov_buffer_desc;

typedef gss_iov_buffer_desc *gss_iov_buffer_t;

typedef struct krb5_gss_ctx_id_rec {
    int sealalg;
    int gss_flags;
    int initiate;
    struct {
        krb5_keyblock keyblock;
    } *enc;
    struct {
        krb5_keyblock keyblock;
    } *seq;
    void *mech_used;
    void *seqstate;
} krb5_gss_ctx_id_rec;

typedef void* krb5_context;

static void *gss_mech_krb5_old;

static void store_32_be(int val, unsigned char buf[4]) {
    buf[0] = (val >> 24) & 0xFF;
    buf[1] = (val >> 16) & 0xFF;
    buf[2] = (val >> 8) & 0xFF;
    buf[3] = val & 0xFF;
}

static int k5_bcmp(void *a, void *b, size_t len) {
    return memcmp(a, b, len);
}

static int g_OID_equal(void *oid1, void *oid2) {
    return oid1 == oid2;
}