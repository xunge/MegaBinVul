#include <stddef.h>
#include <stdint.h>

struct key;
typedef int (*key_match_func_t)(const void *, const void *);

struct key_type {
    const char *name;
    key_match_func_t match;
    int (*match_preparse)(void *);
    void (*match_free)(void *);
};

struct keyring_index_key {
    struct key_type *type;
    const char *description;
};

struct keyring_search_context {
    struct keyring_index_key index_key;
    struct cred *cred;
    struct {
        key_match_func_t cmp;
        const void *raw_data;
        unsigned int lookup_type;
    } match_data;
};

typedef void *key_ref_t;

#define KEYRING_SEARCH_LOOKUP_DIRECT 0
#define EAGAIN 11
#define ENOKEY 126

#define IS_ERR(x) ((uintptr_t)(x) >= (uintptr_t)-4095)
#define PTR_ERR(x) ((intptr_t)(x))
#define ERR_PTR(x) ((void *)(intptr_t)(x))
#define ERR_CAST(x) ((void *)(x))

struct cred {
    // minimal stub
};

struct cred *current_cred(void);
void kenter(const char *fmt, ...);
void kleave(const char *fmt, ...);
key_ref_t search_process_keyrings(struct keyring_search_context *ctx);
struct key *key_ref_to_ptr(key_ref_t key_ref);
void construct_get_dest_keyring(struct key **dest_keyring);
int key_link(struct key *keyring, struct key *key);
void key_put(struct key *key);
struct key *construct_key_and_link(struct keyring_search_context *ctx,
                                  const void *callout_info,
                                  size_t callout_len,
                                  void *aux,
                                  struct key *dest_keyring,
                                  unsigned long flags);
int key_default_cmp(const void *a, const void *b);