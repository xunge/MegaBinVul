#include <stddef.h>

typedef void *key_ref_t;

struct key_preparsed_payload;
struct key {
    struct {
        int (*update)(struct key *, struct key_preparsed_payload *);
    } *type;
    unsigned long flags;
    int sem;
};

#define KEY_NEED_WRITE 0x20
#define KEY_FLAG_NEGATIVE 1
#define EEXIST 17

static inline void down_write(int *sem) {}
static inline void up_write(int *sem) {}
static inline void clear_bit(int nr, unsigned long *addr) {}
static inline key_ref_t ERR_PTR(int err) { return NULL; }
static inline int key_permission(key_ref_t key_ref, unsigned perm) { return 0; }
static inline void key_put(struct key *key) {}
static inline struct key *key_ref_to_ptr(key_ref_t key_ref) { return NULL; }