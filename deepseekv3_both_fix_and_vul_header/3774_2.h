#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define IKED_ID_SIZE 256
#define PATH_MAX 4096
#define LOG_DEBUG 7
#define LOG_INFO 6

struct iked;
struct ibuf;

struct iked_static_id {
    int id_type;
    void *id_data;
    size_t id_length;
    size_t id_offset;
};

struct iked_id {
    int id_type;
    size_t id_offset;
    struct ibuf *id_buf;
};

struct ibuf *ibuf_new(void *, size_t);
void ibuf_release(struct ibuf *);

int ikev2_print_id(struct iked_id *, char *, size_t);
const char *print_map(int, const void *);
void lc_idtype(char *);
size_t strlcpy(char *, const char *, size_t);
size_t strlcat(char *, const char *, size_t);
void log_debug(const char *, ...);
void logit(int, const char *, ...);
void ca_sslerror(const char *);
int ca_pubkey_serialize(void *, struct iked_id *);

#define IKEV2_ID_IPV4 1
#define IKEV2_ID_FQDN 2
#define IKEV2_ID_UFQDN 3
#define IKEV2_ID_IPV6 4

extern const void *ikev2_id_map;
#define IKED_PUBKEY_DIR "/path/to/pubkey/dir/"

typedef void BIO;
typedef void RSA;
typedef void EC_KEY;
typedef void EVP_PKEY;

BIO *BIO_new_mem_buf(void *, int);
int BIO_reset(BIO *);
void BIO_free(BIO *);

EVP_PKEY *EVP_PKEY_new(void);
void EVP_PKEY_free(EVP_PKEY *);
int EVP_PKEY_set1_RSA(EVP_PKEY *, RSA *);
int EVP_PKEY_set1_EC_KEY(EVP_PKEY *, EC_KEY *);
int EVP_PKEY_cmp(EVP_PKEY *, EVP_PKEY *);

RSA *d2i_RSAPublicKey_bio(BIO *, RSA **);
void RSA_free(RSA *);

EC_KEY *d2i_EC_PUBKEY_bio(BIO *, EC_KEY **);
void EC_KEY_free(EC_KEY *);

EVP_PKEY *PEM_read_PUBKEY(FILE *, EVP_PKEY **, void *, void *);
RSA *PEM_read_RSAPublicKey(FILE *, RSA **, void *, void *);