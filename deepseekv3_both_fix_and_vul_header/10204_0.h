#include <stddef.h>
#include <errno.h>

typedef void *key_ref_t;

struct key_type {
    int (*match_preparse)(void *);
    int (*match_free)(void *);
    int (*match)(void *, const void *);
};

struct keyring_search_context {
    struct {
        struct key_type *type;
        const char *description;
    } index_key;
    void *cred;
    struct {
        int (*cmp)(void *, const void *);
        const void *raw_data;
        int lookup_type;
    } match_data;
    int flags;
};

#define ERR_PTR(x) ((void *)(long)(x))
#define ENOKEY 126
#define KEYRING_SEARCH_LOOKUP_DIRECT 0
#define KEYRING_SEARCH_DO_STATE_CHECK 0

static inline void *current_cred(void) { return NULL; }
static int key_default_cmp(void *a, const void *b) { return 0; }
key_ref_t keyring_search_aux(key_ref_t keyring, struct keyring_search_context *ctx);