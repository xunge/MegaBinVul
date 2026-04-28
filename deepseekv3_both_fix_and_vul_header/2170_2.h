#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ECRYPTFS_MAX_CIPHER_NAME_SIZE 32
#define ECRYPTFS_SIG_SIZE_HEX 32
#define ECRYPTFS_DEFAULT_CIPHER "aes"
#define MAX_OPT_ARGS 2

#define ECRYPTFS_PLAINTEXT_PASSTHROUGH_ENABLED 0x00000001
#define ECRYPTFS_XATTR_METADATA_ENABLED 0x00000002
#define ECRYPTFS_ENCRYPTED_VIEW_ENABLED 0x00000004
#define ECRYPTFS_GLOBAL_ENCRYPT_FILENAMES 0x00000008
#define ECRYPTFS_GLOBAL_ENCFN_USE_MOUNT_FNEK 0x00000010
#define ECRYPTFS_UNLINK_SIGS 0x00000020
#define ECRYPTFS_GLOBAL_MOUNT_AUTH_TOK_ONLY 0x00000040

#define ECRYPTFS_AUTH_TOK_FNEK 0x00000001

#define EINVAL 22
#define KERN_ERR ""
#define KERN_WARNING ""

struct ecryptfs_mount_crypt_stat {
    unsigned int flags;
    char global_default_cipher_name[ECRYPTFS_MAX_CIPHER_NAME_SIZE + 1];
    size_t global_default_cipher_key_size;
    char global_default_fn_cipher_name[ECRYPTFS_MAX_CIPHER_NAME_SIZE + 1];
    size_t global_default_fn_cipher_key_bytes;
    char global_default_fnek_sig[ECRYPTFS_SIG_SIZE_HEX + 1];
};

struct ecryptfs_sb_info {
    struct ecryptfs_mount_crypt_stat mount_crypt_stat;
};

enum {
    ecryptfs_opt_sig,
    ecryptfs_opt_ecryptfs_sig,
    ecryptfs_opt_cipher,
    ecryptfs_opt_ecryptfs_cipher,
    ecryptfs_opt_ecryptfs_key_bytes,
    ecryptfs_opt_passthrough,
    ecryptfs_opt_xattr_metadata,
    ecryptfs_opt_encrypted_view,
    ecryptfs_opt_fnek_sig,
    ecryptfs_opt_fn_cipher,
    ecryptfs_opt_fn_cipher_key_bytes,
    ecryptfs_opt_unlink_sigs,
    ecryptfs_opt_mount_auth_tok_only,
    ecryptfs_opt_check_dev_ruid,
    ecryptfs_opt_err
};

typedef struct {
    char *from;
    char *to;
} substring_t;

struct match_token {
    int token;
    const char *pattern;
};

static struct match_token tokens[] = {
    {ecryptfs_opt_sig, "sig=%s"},
    {ecryptfs_opt_ecryptfs_sig, "ecryptfs_sig=%s"},
    {ecryptfs_opt_cipher, "cipher=%s"},
    {ecryptfs_opt_ecryptfs_cipher, "ecryptfs_cipher=%s"},
    {ecryptfs_opt_ecryptfs_key_bytes, "ecryptfs_key_bytes=%u"},
    {ecryptfs_opt_passthrough, "ecryptfs_passthrough"},
    {ecryptfs_opt_xattr_metadata, "ecryptfs_xattr_metadata"},
    {ecryptfs_opt_encrypted_view, "ecryptfs_encrypted_view"},
    {ecryptfs_opt_fnek_sig, "ecryptfs_fnek_sig=%s"},
    {ecryptfs_opt_fn_cipher, "ecryptfs_fn_cipher=%s"},
    {ecryptfs_opt_fn_cipher_key_bytes, "ecryptfs_fn_key_bytes=%u"},
    {ecryptfs_opt_unlink_sigs, "ecryptfs_unlink_sigs"},
    {ecryptfs_opt_mount_auth_tok_only, "ecryptfs_mount_auth_tok_only"},
    {ecryptfs_opt_check_dev_ruid, "ecryptfs_check_dev_ruid"},
    {ecryptfs_opt_err, NULL}
};

static int key_tfm_list_mutex;

static int match_token(char *s, struct match_token *tokens, substring_t *args) {
    return 0;
}

static void printk(const char *fmt, ...) {
}

static long simple_strtol(const char *nptr, char **endptr, int base) {
    return 0;
}

static void BUG_ON(int condition) {
}

static void mutex_lock(int *mutex) {
}

static void mutex_unlock(int *mutex) {
}

extern int ecryptfs_add_global_auth_tok(struct ecryptfs_mount_crypt_stat *mount_crypt_stat,
                                      char *sig_src, int flags);
extern void ecryptfs_init_mount_crypt_stat(struct ecryptfs_mount_crypt_stat *mount_crypt_stat);
extern int ecryptfs_tfm_exists(char *cipher_name, void **tfm);
extern int ecryptfs_add_new_key_tfm(void **tfm, char *cipher_name, size_t key_size);
extern int ecryptfs_init_global_auth_toks(struct ecryptfs_mount_crypt_stat *mount_crypt_stat);
extern void ecryptfs_printk(int priority, const char *fmt, ...);