#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef int32_t key_serial_t;
typedef struct key *key_ref_t;

struct rw_semaphore {
    int dummy;
};

struct key_type {
    long (*read)(struct key *, char *, size_t);
};

struct key {
    struct key_type *type;
    struct rw_semaphore sem;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define ENOKEY 126
#define EACCES 13
#define EOPNOTSUPP 95
#define KEY_NEED_READ 1

key_ref_t lookup_user_key(key_serial_t keyid, int flags, int permissions);
struct key *key_ref_to_ptr(key_ref_t key_ref);
long key_permission(key_ref_t key_ref, unsigned perm);
bool is_key_possessed(key_ref_t key_ref);
int key_validate(struct key *key);
void key_put(struct key *key);
void down_read(struct rw_semaphore *sem);
void up_read(struct rw_semaphore *sem);

#define __user