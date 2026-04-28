#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define G_OK 0
#define G_ERROR -1
#define G_ERROR_PARAM -2
#define G_ERROR_MEMORY -3
#define G_ERROR_UNAUTHORIZED -4
#define G_ERROR_NOT_FOUND -5
#define G_ERROR_DB -6

#define H_OK 0

#define Y_LOG_LEVEL_DEBUG 0
#define Y_LOG_LEVEL_ERROR 1

#define FLAGS_OFFSET 32
#define COUNTER_OFFSET 33
#define FLAG_USER_PRESENT 0x01
#define FLAG_USER_VERIFY 0x04
#define FLAG_ED 0x80

#define GLWD_METRICS_DATABSE_ERROR 0

#define G_TABLE_WEBAUTHN_ASSERTION "webauthn_assertion"
#define G_TABLE_WEBAUTHN_CREDENTIAL "webauthn_credential"

struct config_module {
    void *conn;
    int (*glewlwyd_module_callback_metrics_increment_counter)(struct config_module *, int, int, void *);
    int hash_algorithm;
};

typedef enum {
    digest_SHA256
} digest_algorithm;

typedef struct {
    unsigned char *data;
    size_t size;
} gnutls_datum_t;

typedef void* gnutls_pubkey_t;
typedef void* json_t;

#define GNUTLS_X509_FMT_PEM 0
#define GNUTLS_SIGN_ECDSA_SHA256 0
#define JSON_DECODE_ANY 0

void y_log_message(int level, const char *format, ...);
int o_strcmp(const char *s1, const char *s2);
size_t o_strlen(const char *s);
char *o_strstr(const char *haystack, const char *needle);
char *o_strchr(const char *s, int c);
void *o_malloc(size_t size);
void o_free(void *ptr);
int o_base64_decode(const unsigned char *source, size_t source_len, unsigned char *target, size_t *target_len);
int o_base64url_2_base64(unsigned char *source, size_t source_len, unsigned char *target, size_t *target_len);
int o_base64url_decode(const unsigned char *source, size_t source_len, unsigned char *target, size_t *target_len);
char *generate_hash(int algorithm, const char *input);
int generate_digest_raw(digest_algorithm algorithm, unsigned char *input, size_t input_len, unsigned char *output, size_t *output_len);
json_t *get_credential(struct config_module *config, json_t *j_params, const char *username, const char *credential_id);
int check_result_value(json_t *j_result, int expected_value);
int h_update(void *conn, json_t *j_query, void *j_result);
int gnutls_pubkey_init(gnutls_pubkey_t *key);
int gnutls_pubkey_import(gnutls_pubkey_t key, const gnutls_datum_t *data, unsigned int format);
int gnutls_pubkey_verify_data2(gnutls_pubkey_t key, unsigned int algo, unsigned int flags, const gnutls_datum_t *data, const gnutls_datum_t *signature);
void gnutls_pubkey_deinit(gnutls_pubkey_t key);
void json_decref(json_t *json);
json_t *json_object_get(const json_t *json, const char *key);
const char *json_string_value(const json_t *json);
size_t json_string_length(const json_t *json);
int json_is_string(const json_t *json);
json_t *json_loads(const char *input, size_t flags, void *error);
long long json_integer_value(const json_t *json);
json_t *json_pack(const char *fmt, ...);