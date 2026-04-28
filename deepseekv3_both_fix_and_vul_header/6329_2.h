#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct json_t json_t;
typedef struct cbor_item_t cbor_item_t;
typedef void* gnutls_pubkey_t;
typedef void* gnutls_x509_crt_t;

typedef struct {
    cbor_item_t *key;
    cbor_item_t *value;
} cbor_pair;

typedef struct {
    unsigned char *data;
    size_t size;
} gnutls_datum_t;

typedef enum {
    G_OK,
    G_ERROR,
    G_ERROR_PARAM
} g_result;

typedef enum {
    Y_LOG_LEVEL_DEBUG,
    Y_LOG_LEVEL_ERROR
} y_log_level;

typedef enum {
    digest_SHA256
} digest_type;

#define GNUTLS_X509_FMT_DER 0
#define GNUTLS_SIGN_ECDSA_SHA256 0
#define GNUTLS_KEYID_USE_SHA256 0

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static json_t *json_array(void);
static json_t *json_string(const char *value);
static void json_array_append_new(json_t *array, json_t *value);
static json_t *json_object_get(const json_t *object, const char *key);
static json_t *json_null(void);
static size_t json_array_size(const json_t *array);
static json_t *json_pack(const char *fmt, ...);
static void json_decref(json_t *json);

static int cbor_isa_map(const cbor_item_t *item);
static size_t cbor_map_size(const cbor_item_t *item);
static cbor_pair *cbor_map_handle(const cbor_item_t *item);
static int cbor_isa_string(const cbor_item_t *item);
static const unsigned char *cbor_string_handle(const cbor_item_t *item);
static size_t cbor_string_length(const cbor_item_t *item);
static int cbor_isa_array(const cbor_item_t *item);
static size_t cbor_array_size(const cbor_item_t *item);
static cbor_item_t *cbor_array_get(const cbor_item_t *array, size_t index);
static const unsigned char *cbor_bytestring_handle(const cbor_item_t *item);
static size_t cbor_bytestring_length(const cbor_item_t *item);
static int cbor_isa_bytestring(const cbor_item_t *item);
static void cbor_decref(cbor_item_t **item);

static int gnutls_x509_crt_init(gnutls_x509_crt_t *cert);
static int gnutls_pubkey_init(gnutls_pubkey_t *key);
static int gnutls_x509_crt_import(gnutls_x509_crt_t cert, const gnutls_datum_t *data, unsigned int format);
static int gnutls_x509_crt_get_issuer_dn2(gnutls_x509_crt_t cert, gnutls_datum_t *dn);
static void gnutls_free(void *data);
static int gnutls_pubkey_import_x509(gnutls_pubkey_t key, gnutls_x509_crt_t crt, unsigned int flags);
static int gnutls_x509_crt_get_key_id(gnutls_x509_crt_t crt, unsigned int flags, unsigned char *output_data, size_t *output_data_size);
static int gnutls_pubkey_verify_data2(gnutls_pubkey_t pubkey, unsigned int algo, unsigned int flags, const gnutls_datum_t *data, const gnutls_datum_t *signature);
static void gnutls_pubkey_deinit(gnutls_pubkey_t key);
static void gnutls_x509_crt_deinit(gnutls_x509_crt_t cert);

static size_t o_strlen(const char *s);
static int o_strncmp(const char *s1, const char *s2, size_t n);
static char *msprintf(const char *format, ...);
static void o_free(void *ptr);
static int o_base64_encode(const unsigned char *in, size_t in_len, unsigned char *out, size_t *out_len);
static int generate_digest_raw(digest_type type, const unsigned char *in, size_t in_len, unsigned char *out, size_t *out_len);
static g_result validate_certificate_from_root(json_t *j_params, gnutls_x509_crt_t cert, cbor_item_t *x5c);
static void y_log_message(y_log_level level, const char *format, ...);