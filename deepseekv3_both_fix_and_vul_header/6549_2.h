#include <stddef.h>
#include <stdbool.h>

struct key {
    int serial;
};

struct key_user {
};

struct key_type {
};

struct keyring_search_context {
    struct {
        struct key_type *type;
    } index_key;
};

#define EPERM 1
#define ENOMEM 12
#define EINPROGRESS 115

typedef unsigned int uid_t;

static inline struct key *ERR_PTR(long error) { return (struct key *)((void *)error); }
static inline long PTR_ERR(const struct key *ptr) { return (long)((void *)ptr); }
static inline bool IS_ERR(const struct key *ptr) { return (unsigned long)ptr > (unsigned long)-4096UL; }

struct key_type key_type_keyring;
int key_negative_timeout;

#define kenter(fmt, ...) 
#define kleave(fmt, ...) 
#define kdebug(fmt, ...) 

static void key_put(struct key *key) {}
static void key_user_put(struct key_user *user) {}
static int construct_get_dest_keyring(struct key **dest_keyring) { return 0; }
static int construct_alloc_key(struct keyring_search_context *ctx, struct key *dest_keyring, unsigned long flags, struct key_user *user, struct key **key) { return 0; }
static int construct_key(struct key *key, const char *callout_info, size_t callout_len, void *aux, struct key *dest_keyring) { return 0; }
static void key_negate_and_link(struct key *key, unsigned timeout, struct key *keyring, struct key *instkey) {}
static struct key_user *key_user_lookup(uid_t uid) { return NULL; }
static uid_t current_fsuid(void) { return 0; }
static int key_serial(const struct key *key) { return key ? key->serial : 0; }