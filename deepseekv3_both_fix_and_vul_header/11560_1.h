#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MD5_SIGNATURE_SIZE 16
#define MAX_CHAP_N_SIZE 256
#define MAX_RESPONSE_LENGTH 1024
#define CHAP_CHALLENGE_STR_LEN 1024
#define CHAP_CHALLENGE_LENGTH 16
#define HEX 1
#define GFP_KERNEL 0

struct iscsi_conn {
    void *auth_protocol;
};
struct iscsi_node_auth {
    char *userid;
    char *password;
    char *userid_mutual;
    char *password_mutual;
    int authenticate_target;
};
struct iscsi_chap {
    unsigned char id;
    unsigned char challenge[CHAP_CHALLENGE_LENGTH];
};

struct crypto_shash;
struct shash_desc {
    struct crypto_shash *tfm;
    unsigned int flags;
};

#define IS_ERR(x) ((x) == NULL)
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define pr_debug(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)