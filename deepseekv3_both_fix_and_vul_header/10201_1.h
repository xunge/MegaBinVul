#include <stddef.h>
#include <string.h>
#include <limits.h>

typedef struct key *key_ref_t;
typedef unsigned int key_perm_t;

struct keyring_index_key {
    const struct key_type *type;
    const char *description;
    size_t desc_len;
};

struct key_preparsed_payload {
    const void *data;
    size_t datalen;
    size_t quotalen;
    int trusted;
    long expiry;
    const char *description;
};

struct key_type {
    int (*match)(const struct key *key, const void *desc);
    int (*instantiate)(struct key *key, struct key_preparsed_payload *prep);
    int (*preparse)(struct key_preparsed_payload *prep);
    void (*free_preparse)(struct key_preparsed_payload *prep);
    int (*update)(struct key *key, const void *data, size_t datalen);
    size_t def_datalen;
    int (*read)(void);
};

struct key {
    struct key_type *type;
    unsigned long flags;
    key_perm_t perm;
};

struct cred {
    unsigned int fsuid;
    unsigned int fsgid;
};

struct assoc_array_edit;

#define KEY_ALLOC_TRUSTED 0x0008
#define KEY_FLAG_TRUSTED_ONLY 0x0004
#define KEY_NEED_WRITE 0x0002
#define KEY_PERM_UNDEF 0x0000
#define KEY_POS_VIEW 0x0001
#define KEY_POS_READ 0x0002
#define KEY_POS_WRITE 0x0004
#define KEY_POS_SEARCH 0x0008
#define KEY_POS_LINK 0x0010
#define KEY_POS_SETATTR 0x0020
#define KEY_USR_VIEW 0x0040
#define TIME_T_MAX LONG_MAX

#define ENODEV 19
#define EINVAL 22
#define ENOTDIR 20
#define EPERM 1

static inline struct key *key_ref_to_ptr(key_ref_t key_ref) { return key_ref; }
static inline key_ref_t make_key_ref(struct key *key, int possessed) { return key; }
static inline int is_key_possessed(key_ref_t key_ref) { return 0; }
static inline const struct cred *current_cred(void) { static struct cred c; return &c; }
static inline void key_check(struct key *key) {}
static inline void key_put(struct key *key) {}
static inline int key_permission(key_ref_t key_ref, int perm) { return 0; }
static inline struct key_type *key_type_lookup(const char *type) { return NULL; }
static inline void key_type_put(struct key_type *type) {}
static inline int __key_link_begin(struct key *keyring, struct keyring_index_key *index_key, struct assoc_array_edit **edit) { return 0; }
static inline void __key_link_end(struct key *keyring, struct keyring_index_key *index_key, struct assoc_array_edit *edit) {}
static inline key_ref_t find_key_to_update(key_ref_t keyring_ref, struct keyring_index_key *index_key) { return NULL; }
static inline struct key *key_alloc(struct key_type *type, const char *desc, unsigned int uid, unsigned int gid, const struct cred *cred, key_perm_t perm, unsigned long flags) { return NULL; }
static inline int __key_instantiate_and_link(struct key *key, struct key_preparsed_payload *prep, struct key *keyring, struct key *authkey, struct assoc_array_edit **edit) { return 0; }
static inline key_ref_t __key_update(key_ref_t key_ref, struct key_preparsed_payload *prep) { return NULL; }

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define ERR_PTR(x) ((void *)(long)(x))
#define ERR_CAST(x) ((void *)(x))
#define PTR_ERR(x) ((long)(x))

extern struct key_type key_type_keyring;