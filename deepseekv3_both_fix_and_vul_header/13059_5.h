#include <stddef.h>
#include <string.h>
#include <errno.h>

#define EFAULT 14
#define EINVAL 22
#define EBUSY 16

#define TLS_CIPHER_AES_GCM_128 0
#define TLS_CIPHER_AES_GCM_256 1
#define TLS_CIPHER_AES_CCM_128 2
#define TLS_CIPHER_CHACHA20_POLY1305 3
#define TLS_CIPHER_SM4_GCM 4
#define TLS_CIPHER_SM4_CCM 5
#define TLS_CIPHER_ARIA_GCM_128 6
#define TLS_CIPHER_ARIA_GCM_256 7

#define TLS_CIPHER_AES_GCM_128_SALT_SIZE 4
#define TLS_CIPHER_AES_GCM_128_IV_SIZE 8
#define TLS_CIPHER_AES_GCM_128_REC_SEQ_SIZE 8
#define TLS_CIPHER_AES_GCM_256_SALT_SIZE 4
#define TLS_CIPHER_AES_GCM_256_IV_SIZE 8
#define TLS_CIPHER_AES_GCM_256_REC_SEQ_SIZE 8
#define TLS_CIPHER_AES_CCM_128_SALT_SIZE 4
#define TLS_CIPHER_AES_CCM_128_IV_SIZE 8
#define TLS_CIPHER_AES_CCM_128_REC_SEQ_SIZE 8
#define TLS_CIPHER_CHACHA20_POLY1305_SALT_SIZE 4
#define TLS_CIPHER_CHACHA20_POLY1305_IV_SIZE 12
#define TLS_CIPHER_CHACHA20_POLY1305_REC_SEQ_SIZE 8
#define TLS_CIPHER_SM4_GCM_SALT_SIZE 4
#define TLS_CIPHER_SM4_GCM_IV_SIZE 8
#define TLS_CIPHER_SM4_GCM_REC_SEQ_SIZE 8
#define TLS_CIPHER_SM4_CCM_SALT_SIZE 4
#define TLS_CIPHER_SM4_CCM_IV_SIZE 8
#define TLS_CIPHER_SM4_CCM_REC_SEQ_SIZE 8
#define TLS_CIPHER_ARIA_GCM_128_SALT_SIZE 4
#define TLS_CIPHER_ARIA_GCM_128_IV_SIZE 8
#define TLS_CIPHER_ARIA_GCM_128_REC_SEQ_SIZE 8
#define TLS_CIPHER_ARIA_GCM_256_SALT_SIZE 4
#define TLS_CIPHER_ARIA_GCM_256_IV_SIZE 8
#define TLS_CIPHER_ARIA_GCM_256_REC_SEQ_SIZE 8

struct tls_crypto_info {
    unsigned short cipher_type;
};

struct cipher_context {
    unsigned char iv[32];
    unsigned char rec_seq[32];
};

struct tls_context {
    struct {
        struct tls_crypto_info info;
    } crypto_send, crypto_recv;
    struct cipher_context tx, rx;
};

struct tls12_crypto_info_aes_gcm_128 {
    struct tls_crypto_info info;
    unsigned char iv[8];
    unsigned char rec_seq[8];
};

struct tls12_crypto_info_aes_gcm_256 {
    struct tls_crypto_info info;
    unsigned char iv[8];
    unsigned char rec_seq[8];
};

struct tls12_crypto_info_aes_ccm_128 {
    struct tls_crypto_info info;
    unsigned char iv[8];
    unsigned char rec_seq[8];
};

struct tls12_crypto_info_chacha20_poly1305 {
    struct tls_crypto_info info;
    unsigned char iv[12];
    unsigned char rec_seq[8];
};

struct tls12_crypto_info_sm4_gcm {
    struct tls_crypto_info info;
    unsigned char iv[8];
    unsigned char rec_seq[8];
};

struct tls12_crypto_info_sm4_ccm {
    struct tls_crypto_info info;
    unsigned char iv[8];
    unsigned char rec_seq[8];
};

struct tls12_crypto_info_aria_gcm_128 {
    struct tls_crypto_info info;
    unsigned char iv[8];
    unsigned char rec_seq[8];
};

struct tls12_crypto_info_aria_gcm_256 {
    struct tls_crypto_info info;
    unsigned char iv[8];
    unsigned char rec_seq[8];
};

#define TLS_CRYPTO_INFO_READY(crypto_info) ((crypto_info)->cipher_type)

static inline struct tls_context *tls_get_ctx(struct sock *sk) {
    return (struct tls_context *)0;
}

static inline int get_user(int *val, int *addr) {
    *val = *addr;
    return 0;
}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}

#define container_of(ptr, type, member) ({ \
    const typeof(((type *)0)->member) *__mptr = (ptr); \
    (type *)((char *)__mptr - offsetof(type, member)); })

#define __user