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
    // Define crypto_policy_t structure members here
} crypto_policy_t;

typedef int32_t err_status_t;
#define err_status_ok 0
#define err_status_bad_param -1

void crypto_policy_set_aes_cm_128_hmac_sha1_80(crypto_policy_t *policy);
void crypto_policy_set_aes_cm_128_hmac_sha1_32(crypto_policy_t *policy);
void crypto_policy_set_null_cipher_hmac_sha1_80(crypto_policy_t *policy);
void crypto_policy_set_aes_cm_256_hmac_sha1_80(crypto_policy_t *policy);
void crypto_policy_set_aes_cm_256_hmac_sha1_32(crypto_policy_t *policy);