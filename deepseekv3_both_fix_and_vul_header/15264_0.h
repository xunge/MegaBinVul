#include <stddef.h>
#include <errno.h>

typedef int key_serial_t;
typedef void* key_ref_t;

struct request_key_auth {
    struct key *dest_keyring;
};

struct key {
    // key structure members
};

#define KEY_LOOKUP_CREATE 0
#define KEY_WRITE 0
#define KEY_SPEC_REQKEY_AUTH_KEY (-1)
#define KEY_SPEC_REQUESTOR_KEYRING (-2)

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))

static key_ref_t lookup_user_key(key_serial_t id, int lookup_flags, int perm) {
    return ERR_PTR(-ENOENT);
}

static struct key *key_ref_to_ptr(key_ref_t ref) {
    return NULL;
}