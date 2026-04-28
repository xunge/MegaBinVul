#include <stdint.h>
#include <string.h>
#include <errno.h>

#define TPM_DIGEST_SIZE 20
#define MAX_BLOB_SIZE 2048
#define TPM2_ST_SESSIONS 0x8001
#define TPM2_CC_CREATE 0x00000153
#define TPM2_RS_PW 0x40000009
#define TPM_ALG_KEYEDHASH 0x0008
#define TPM_ALG_NULL 0x0010
#define TPM2_OA_USER_WITH_AUTH 0x0000000B
#define TPM2_RC_HASH 0x00000143
#define TPM_BUF_OVERFLOW (1 << 0)
#define TPM_HEADER_SIZE 10
#define EINVAL 22
#define E2BIG 7
#define EFAULT 14
#define EPERM 1

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint32_t __be32;

struct tpm_chip;
struct tpm_buf {
    unsigned int flags;
    u8 *data;
};

struct trusted_key_payload {
    u8 *key;
    u32 key_len;
    u8 migratable;
    u8 *blob;
    u32 blob_len;
};

struct trusted_key_options {
    u32 hash;
    u32 keyhandle;
    u8 *keyauth;
    u8 *blobauth;
    u32 policydigest_len;
    u8 *policydigest;
};

struct tpm2_hash {
    u16 crypto_id;
    u16 tpm_id;
};

extern struct tpm2_hash tpm2_hash_map[];
extern size_t ARRAY_SIZE(struct tpm2_hash *);

int tpm_buf_init(struct tpm_buf *buf, u16 tag, u32 ord);
void tpm_buf_destroy(struct tpm_buf *buf);
void tpm_buf_append(struct tpm_buf *buf, const u8 *data, u16 len);
void tpm_buf_append_u8(struct tpm_buf *buf, u8 value);
void tpm_buf_append_u16(struct tpm_buf *buf, u16 value);
void tpm_buf_append_u32(struct tpm_buf *buf, u32 value);
void tpm2_buf_append_auth(struct tpm_buf *buf, u32 handle, const u8 *nonce, u16 nonce_len, u8 attributes, const u8 *hmac, u16 hmac_len);
int tpm_transmit_cmd(struct tpm_chip *chip, struct tpm_buf *buf, u32 min_rsp_body_len, const char *desc);
u32 tpm2_rc_value(u32 rc);
void tpm_put_ops(struct tpm_chip *chip);
u16 tpm_buf_length(struct tpm_buf *buf);
u32 be32_to_cpup(const __be32 *p);