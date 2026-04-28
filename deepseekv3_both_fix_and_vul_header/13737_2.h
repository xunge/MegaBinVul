#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char u8;

#define SC_MAX_SUPPORTED_ALGORITHMS 16
#define SC_PKCS15_MAX_ACCESS_RULES 16
#define SC_PKCS15_GOSTR3410_KEYSIZE 32
#define SC_ERROR_ASN1_END_OF_CONTENTS 1
#define SC_ERROR_INVALID_ASN1_OBJECT 2
#define SC_ERROR_OUT_OF_MEMORY 3
#define SC_ASN1_PRESENT 0x01
#define C_ASN1_COM_KEY_ATTR_SIZE 6
#define C_ASN1_COM_PRKEY_ATTR_SIZE 1
#define C_ASN1_RSAKEY_ATTR_SIZE 2
#define C_ASN1_PRK_RSA_ATTR_SIZE 1
#define C_ASN1_DSAKEY_ATTR_SIZE 1
#define C_ASN1_PRK_DSA_ATTR_SIZE 1
#define C_ASN1_DSAKEY_I_P_ATTR_SIZE 1
#define C_ASN1_DSAKEY_VALUE_ATTR_SIZE 2
#define C_ASN1_GOSTR3410KEY_ATTR_SIZE 4
#define C_ASN1_PRK_GOSTR3410_ATTR_SIZE 1
#define C_ASN1_ECCKEY_ATTR 2
#define C_ASN1_PRK_ECC_ATTR 1
#define C_ASN1_PRKEY_SIZE 4
#define C_ASN1_SUPPORTED_ALGORITHMS_SIZE SC_MAX_SUPPORTED_ALGORITHMS

enum {
    SC_PKCS15_TYPE_PRKEY_RSA,
    SC_PKCS15_TYPE_PRKEY_EC,
    SC_PKCS15_TYPE_PRKEY_DSA,
    SC_PKCS15_TYPE_PRKEY_GOSTR3410
};

enum {
    SC_PATH_TYPE_PATH_PROT
};

enum {
    SC_PKCS15_CO_FLAG_PRIVATE = 0x01
};

enum {
    SC_PKCS15_ACCESS_RULE_MODE_EXECUTE = 0x01,
    SC_PKCS15_ACCESS_RULE_MODE_PSO_CDS = 0x02,
    SC_PKCS15_ACCESS_RULE_MODE_PSO_DECRYPT = 0x04,
    SC_PKCS15_ACCESS_RULE_MODE_INT_AUTH = 0x08
};

struct sc_context {
    /* Context structure definition */
};

typedef struct sc_context sc_context_t;

struct sc_aid {
    u8 *value;
    size_t len;
};

struct sc_path {
    int type;
    struct sc_aid aid;
    /* Other path fields */
};

struct sc_asn1_entry {
    const char *name;
    void *parm;
    size_t *len;
    int flags;
    /* Other ASN.1 entry fields */
};

struct sc_asn1_pkcs15_object {
    struct sc_pkcs15_object *obj;
    struct sc_asn1_entry *com_key_attr;
    struct sc_asn1_entry *com_prkey_attr;
    struct sc_asn1_entry *key_attr;
};

struct sc_pkcs15_keyinfo_gostparams {
    int gostr3410;
    int gostr3411;
    int gost28147;
};

struct sc_pkcs15_prkey_info_params {
    void *data;
    size_t len;
};

struct sc_pkcs15_id {
    u8 *value;
    size_t len;
};

struct sc_pkcs15_prkey_info {
    struct sc_path path;
    int modulus_length;
    int field_length;
    int key_reference;
    int native;
    unsigned int usage;
    unsigned int access_flags;
    struct sc_pkcs15_id id;
    struct {
        u8 *value;
        size_t len;
    } subject;
    struct sc_pkcs15_prkey_info_params params;
    int algo_refs[SC_MAX_SUPPORTED_ALGORITHMS];
};

struct sc_pkcs15_object {
    int type;
    int flags;
    struct sc_pkcs15_id auth_id;
    struct {
        int access_mode;
        struct sc_pkcs15_id auth_id;
    } access_rules[SC_PKCS15_MAX_ACCESS_RULES];
    void *data;
};

struct sc_pkcs15_card {
    struct {
        sc_context_t *ctx;
    } *card;
    struct {
        struct sc_path path;
    } *file_app;
    struct {
        struct {
            struct sc_aid aid;
        } ddo;
    } *app;
};

extern int sc_asn1_decode_choice(sc_context_t *ctx, struct sc_asn1_entry *entries,
                                const u8 *in, size_t inlen, const u8 **out, size_t *outlen);
extern void sc_copy_asn1_entry(const struct sc_asn1_entry *src, struct sc_asn1_entry *dst);
extern void sc_format_asn1_entry(struct sc_asn1_entry *entry, void *parm, size_t *len, int flags);
extern void sc_pkcs15_free_key_params(struct sc_pkcs15_prkey_info_params *params);
extern int sc_pkcs15_make_absolute_path(const struct sc_path *base, struct sc_path *path);
extern const char *sc_pkcs15_print_id(const struct sc_pkcs15_id *id);
extern const char *sc_print_path(const struct sc_path *path);
extern const char *sc_dump_hex(const u8 *data, size_t len);
extern void LOG_TEST_RET(sc_context_t *ctx, int r, const char *msg);
extern void LOG_FUNC_RETURN(sc_context_t *ctx, int r);
extern void sc_log(sc_context_t *ctx, const char *fmt, ...);

extern const struct sc_asn1_entry c_asn1_prkey[];
extern const struct sc_asn1_entry c_asn1_supported_algorithms[];
extern const struct sc_asn1_entry c_asn1_prk_rsa_attr[];
extern const struct sc_asn1_entry c_asn1_rsakey_attr[];
extern const struct sc_asn1_entry c_asn1_prk_dsa_attr[];
extern const struct sc_asn1_entry c_asn1_dsakey_attr[];
extern const struct sc_asn1_entry c_asn1_dsakey_value_attr[];
extern const struct sc_asn1_entry c_asn1_dsakey_i_p_attr[];
extern const struct sc_asn1_entry c_asn1_prk_gostr3410_attr[];
extern const struct sc_asn1_entry c_asn1_gostr3410key_attr[];
extern const struct sc_asn1_entry c_asn1_prk_ecc_attr[];
extern const struct sc_asn1_entry c_asn1_ecckey_attr[];
extern const struct sc_asn1_entry c_asn1_com_prkey_attr[];
extern const struct sc_asn1_entry c_asn1_com_key_attr[];