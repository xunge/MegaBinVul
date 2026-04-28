#include <stdlib.h>
#include <string.h>

#define SC_ESTEID_PD_DOCUMENT_NR 1
#define SC_ERROR_INTERNAL -1
#define SC_SUCCESS 0
#define SC_LOG_DEBUG_NORMAL 1
#define SC_RECORD_BY_REC_NR 1
#define SC_ALGORITHM_EC 1
#define SC_ALGORITHM_RSA 2

#define SC_PKCS15_TOKEN_PRN_GENERATION 0x01
#define SC_PKCS15_TOKEN_EID_COMPLIANT 0x02  
#define SC_PKCS15_TOKEN_READONLY 0x04
#define SC_PKCS15_PIN_FLAG_UNBLOCKING_PIN 0x01
#define SC_PKCS15_PIN_AUTH_TYPE_PIN 1
#define SC_PKCS15_PIN_TYPE_ASCII_NUMERIC 1
#define SC_PKCS15_PRKEY_USAGE_SIGN 0x01
#define SC_PKCS15_PRKEY_USAGE_ENCRYPT 0x02
#define SC_PKCS15_PRKEY_USAGE_DECRYPT 0x04  
#define SC_PKCS15_PRKEY_USAGE_NONREPUDIATION 0x08
#define SC_PKCS15_PRKEY_USAGE_DERIVE 0x10
#define SC_PKCS15_CO_FLAG_PRIVATE 0x01

typedef unsigned char u8;

typedef struct sc_path {
    unsigned char value[16];
    size_t len;
} sc_path_t;

typedef struct sc_object_id {
    unsigned long value[16];
} sc_object_id_t;

typedef struct sc_pkcs15_id {
    unsigned char value[16];
    size_t len;
} sc_pkcs15_id_t;

typedef struct sc_pkcs15_pin_attrs {
    int reference;
    int flags;
    int type;
    int min_length;
    int stored_length;
    int max_length;
    char pad_char;
} sc_pkcs15_pin_attrs_t;

typedef struct sc_pkcs15_auth_info {
    sc_pkcs15_id_t auth_id;
    int auth_type;
    int tries_left;
    int max_tries;
    struct {
        sc_pkcs15_pin_attrs_t pin;
    } attrs;
} sc_pkcs15_auth_info_t;

typedef struct sc_pkcs15_object {
    char label[64];
    sc_pkcs15_id_t auth_id;
    int flags;
    int user_consent;
} sc_pkcs15_object_t;

typedef struct sc_pkcs15_cert_info {
    sc_pkcs15_id_t id;
    sc_path_t path;
} sc_pkcs15_cert_info_t;

typedef struct sc_pkcs15_prkey_info {
    sc_pkcs15_id_t id;
    int native;
    int key_reference;
    size_t field_length;
    size_t modulus_length;
    int usage;
} sc_pkcs15_prkey_info_t;

typedef struct sc_ec_params {
    size_t field_length;
} sc_ec_params_t;

typedef struct sc_rsa_modulus {
    size_t len;
} sc_rsa_modulus_t;

typedef union sc_key_data {
    struct {
        sc_ec_params_t params;
    } ec;
    struct {
        sc_rsa_modulus_t modulus;
    } rsa;
} sc_key_data_t;

typedef struct sc_key {
    int algorithm;
    sc_key_data_t u;
} sc_key_t;

typedef struct sc_pkcs15_cert {
    sc_key_t *key;
    unsigned char *subject;
    size_t subject_len;
} sc_pkcs15_cert_t;

typedef struct sc_tokeninfo {
    char *label;
    char *manufacturer_id;
    char *serial_number;
    int flags;
} sc_tokeninfo_t;

typedef struct sc_card {
    void *ctx;
} sc_card_t;

typedef struct sc_pkcs15_card {
    sc_card_t *card;
    sc_tokeninfo_t *tokeninfo;
} sc_pkcs15_card_t;

static inline void SC_TEST_RET(void *ctx, int level, int ret, const char *msg) {}
static int sc_select_file(sc_card_t *card, sc_path_t *path, void *null) { return 0; }
static int sc_read_record(sc_card_t *card, int rec_nr, unsigned char *buf, size_t len, int flags) { return 0; }
static void set_string(char **dst, const char *src) {}
static int sc_pkcs15emu_add_x509_cert(sc_pkcs15_card_t *p15card, sc_pkcs15_object_t *obj, sc_pkcs15_cert_info_t *info) { return 0; }
static int sc_pkcs15_read_certificate(sc_pkcs15_card_t *p15card, sc_pkcs15_cert_info_t *info, sc_pkcs15_cert_t **cert) { return 0; }
static void sc_pkcs15_get_name_from_dn(void *ctx, const u8 *dn, size_t dn_len, const sc_object_id_t *oid, u8 **out, size_t *out_len) {}
static void sc_pkcs15_free_certificate(sc_pkcs15_cert_t *cert) {}
static int sc_pkcs15emu_add_pin_obj(sc_pkcs15_card_t *p15card, sc_pkcs15_object_t *obj, sc_pkcs15_auth_info_t *info) { return 0; }
static int sc_pkcs15emu_add_rsa_prkey(sc_pkcs15_card_t *p15card, sc_pkcs15_object_t *obj, sc_pkcs15_prkey_info_t *info) { return 0; }
static int sc_pkcs15emu_add_ec_prkey(sc_pkcs15_card_t *p15card, sc_pkcs15_object_t *obj, sc_pkcs15_prkey_info_t *info) { return 0; }
static void sc_format_path(const char *str, sc_path_t *path) {}
static size_t strlcpy(char *dst, const char *src, size_t size) { return 0; }