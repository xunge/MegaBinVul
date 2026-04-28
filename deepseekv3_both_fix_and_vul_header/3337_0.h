#include <stdint.h>

typedef enum {
    srtp_profile_aes128_cm_sha1_80,
    srtp_profile_aes128_cm_sha1_32,
    srtp_profile_null_sha1_80,
    srtp_profile_aes256_cm_sha1_80,
    srtp_profile_aes256_cm_sha1_32,
    srtp_profile_null_sha1_32
} srtp_profile_t;

typedef struct {
    uint8_t dummy;
} crypto_policy_t;

typedef enum {
    err_status_ok,
    err_status_bad_param
} err_status_t;

void crypto_policy_set_aes_cm_128_hmac_sha1_80(crypto_policy_t *policy);
void crypto_policy_set_aes_cm_256_hmac_sha1_80(crypto_policy_t *policy);
void crypto_policy_set_null_cipher_hmac_sha1_80(crypto_policy_t *policy);