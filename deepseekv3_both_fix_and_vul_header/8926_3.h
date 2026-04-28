#include <errno.h>
#include <stddef.h>

struct key {
    int serial;
};

struct key_user;

struct key_type {
    const char *name;
};

struct keyring_search_context {
    struct {
        struct key_type *type;
    } index_key;
};

#define EPERM 1
#define ENOMEM 12
#define EINPROGRESS 115

#define ERR_PTR(err) ((void *)(long)(err))

static void kenter(const char *s) {}
static void kleave(const char *fmt, ...) {}
static void kdebug(const char *s) {}

static int current_fsuid(void) { return 0; }
static struct key_user *key_user_lookup(int uid) { return NULL; }
static void key_user_put(struct key_user *user) {}
static void construct_get_dest_keyring(struct key **keyring) {}
static int construct_alloc_key(struct keyring_search_context *ctx, struct key *keyring, unsigned long flags, struct key_user *user, struct key **key) { return 0; }
static int construct_key(struct key *key, const char *info, size_t len, void *aux, struct key *keyring) { return 0; }
static void key_put(struct key *key) {}
static int key_serial(struct key *key) { return 0; }
static void key_negate_and_link(struct key *key, unsigned timeout, void *a, void *b) {}

static struct key_type key_type_keyring = {0};
static unsigned key_negative_timeout = 0;