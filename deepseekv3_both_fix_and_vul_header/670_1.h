#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned char u8;
typedef size_t sc_format_len_size_t;

struct sc_context;
typedef struct sc_context sc_context_t;

struct sc_asn1_entry {
    int type;
    char *name;
    void *parm;
    void *arg;
    int flags;
};

struct sc_object_id;
struct sc_path;
typedef struct sc_path sc_path_t;
struct sc_pkcs15_id {
    u8 value[256];
    size_t len;
};
struct sc_asn1_pkcs15_object;
struct sc_algorithm_id;
struct sc_pkcs15_sec_env_info;
typedef struct sc_pkcs15_sec_env_info sc_pkcs15_sec_env_info_t;

enum {
    SC_ASN1_STRUCT = 1,
    SC_ASN1_NULL,
    SC_ASN1_BOOLEAN,
    SC_ASN1_INTEGER,
    SC_ASN1_ENUMERATED,
    SC_ASN1_BIT_STRING_NI,
    SC_ASN1_BIT_STRING,
    SC_ASN1_BIT_FIELD,
    SC_ASN1_OCTET_STRING,
    SC_ASN1_GENERALIZEDTIME,
    SC_ASN1_OBJECT,
    SC_ASN1_PRINTABLESTRING,
    SC_ASN1_UTF8STRING,
    SC_ASN1_PATH,
    SC_ASN1_PKCS15_ID,
    SC_ASN1_PKCS15_OBJECT,
    SC_ASN1_ALGORITHM_ID,
    SC_ASN1_SE_INFO,
    SC_ASN1_CALLBACK
};

#define SC_LOG_DEBUG_ASN1 0
#define SC_ASN1_ALLOC (1 << 0)
#define SC_ASN1_UNSIGNED (1 << 1)
#define SC_ASN1_PRESENT (1 << 2)

#define SC_ERROR_INVALID_ASN1_OBJECT (-1)
#define SC_ERROR_OUT_OF_MEMORY (-2)

#define SC_FORMAT_LEN_SIZE_T "z"

extern void sc_debug(sc_context_t *ctx, int level, const char *fmt, ...);
extern char *sc_dump_hex(const u8 *buf, size_t len);
extern char *sc_strerror(int err);
extern int asn1_decode(sc_context_t *ctx, struct sc_asn1_entry *entry, const u8 *obj, size_t objlen, void *a, void *b, int c, int depth);
extern int sc_asn1_decode_integer(const u8 *obj, size_t objlen, int *out);
extern int decode_bit_string(const u8 *obj, size_t objlen, u8 *out, size_t outlen, int invert);
extern int decode_bit_field(const u8 *obj, size_t objlen, u8 *out, size_t outlen);
extern int sc_asn1_decode_object_id(const u8 *obj, size_t objlen, struct sc_object_id *out);
extern int sc_asn1_decode_utf8string(const u8 *obj, size_t objlen, u8 *out, size_t *outlen);
extern int asn1_decode_path(sc_context_t *ctx, const u8 *obj, size_t objlen, struct sc_path *out, int depth);
extern int asn1_decode_p15_object(sc_context_t *ctx, const u8 *obj, size_t objlen, struct sc_asn1_pkcs15_object *out, int depth);
extern int sc_asn1_decode_algorithm_id(sc_context_t *ctx, const u8 *obj, size_t objlen, struct sc_algorithm_id *out, int depth);
extern int asn1_decode_se_info(sc_context_t *ctx, const u8 *obj, size_t objlen, sc_pkcs15_sec_env_info_t ***out, size_t *outlen, int depth);