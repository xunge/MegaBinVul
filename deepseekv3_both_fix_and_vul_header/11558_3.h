#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MD5_SIGNATURE_SIZE 16
#define MAX_CHAP_N_SIZE 256
#define MAX_RESPONSE_LENGTH 1024
#define CHAP_CHALLENGE_STR_LEN 1024
#define CHAP_CHALLENGE_LENGTH 16
#define GFP_KERNEL 0

typedef uint32_t u32;

struct iscsi_conn;
struct iscsi_node_auth;
struct iscsi_chap {
    unsigned char id;
    unsigned char challenge[CHAP_CHALLENGE_LENGTH];
};

enum {
    HEX,
};

struct iscsi_conn {
    struct iscsi_chap *auth_protocol;
};

struct iscsi_node_auth {
    char *userid;
    char *password;
    char *userid_mutual;
    char *password_mutual;
    int authenticate_target;
};

struct crypto_shash;
struct shash_desc {
    struct crypto_shash *tfm;
    unsigned int flags;
};

#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define kzalloc(size, flags) calloc(1, size)
#define kmalloc(size, flags) malloc(size)
#define kzfree(ptr) free(ptr)
#define kfree(ptr) free(ptr)
#define IS_ERR(ptr) (ptr == NULL)
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

static inline int hex2bin(unsigned char *dst, const char *src, size_t count) {
    return 0;
}

static inline int extract_param(const char *src, const char *name, size_t max, 
                              char *dest, unsigned char *type) {
    return 0;
}

static inline void chap_binaryhex_to_asciihex(char *ascii, const unsigned char *binary, size_t len) {
}

static inline struct crypto_shash *crypto_alloc_shash(const char *name, u32 type, u32 mask) {
    return NULL;
}

static inline int crypto_shash_init(struct shash_desc *desc) {
    return 0;
}

static inline int crypto_shash_update(struct shash_desc *desc, const void *data, unsigned int len) {
    return 0;
}

static inline int crypto_shash_finup(struct shash_desc *desc, const void *data,
                                   unsigned int len, void *out) {
    return 0;
}

static inline void crypto_free_shash(struct crypto_shash *tfm) {
}

static inline size_t crypto_shash_descsize(struct crypto_shash *tfm) {
    return 0;
}

static inline int kstrtoul(const char *s, unsigned int base, unsigned long *res) {
    *res = strtoul(s, NULL, base);
    return 0;
}