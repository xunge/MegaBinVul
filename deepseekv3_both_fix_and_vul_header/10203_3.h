#include <stdio.h>
#include <errno.h>
#include <stddef.h>

typedef int key_serial_t;
typedef void *key_ref_t;

struct key {
    unsigned long flags;
};

struct key_type;
struct cred;

#define KEY_FLAG_REVOKED 0
#define KEYRING_SEARCH_LOOKUP_DIRECT 1

struct key_match_data {
    int (*cmp)(const struct key *, const struct key_match_data *);
    const void *raw_data;
    unsigned int lookup_type;
};

struct key_index_key {
    struct key_type *type;
    const char *description;
};

struct keyring_search_context {
    struct key_index_key index_key;
    struct cred *cred;
    struct key_match_data match_data;
};

extern struct key_type key_type_request_key_auth;

struct key *ERR_PTR(long error);
long IS_ERR(const void *ptr);
struct key *ERR_CAST(key_ref_t ref);
struct cred *current_cred(void);
int test_bit(int nr, const volatile unsigned long *addr);
void key_put(struct key *key);
key_ref_t search_process_keyrings(struct keyring_search_context *ctx);
struct key *key_ref_to_ptr(key_ref_t ref);
int key_default_cmp(const struct key *key, const struct key_match_data *match_data);
int user_match(const struct key *key, const struct key_match_data *match_data);