#include <stddef.h>
#include <sys/types.h>
#include <stdint.h>

typedef int32_t key_serial_t;
typedef void *key_ref_t;

struct rw_semaphore {
    // Minimal definition to make it compile
    int dummy;
};

struct key_type {
    long (*read)(struct key *, char *, size_t);
};

struct key {
    unsigned long flags;
    struct key_type *type;
    struct rw_semaphore sem;
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define KEY_FLAG_NEGATIVE 0
#define KEY_NEED_READ 1
#define ENOKEY 126
#define EACCES 13
#define EOPNOTSUPP 95

extern key_ref_t lookup_user_key(key_serial_t, int, int);
extern struct key *key_ref_to_ptr(key_ref_t);
extern int test_bit(int, const volatile unsigned long *);
extern long key_permission(key_ref_t, int);
extern int is_key_possessed(key_ref_t);
extern void key_put(struct key *);
extern long key_validate(struct key *);
extern void down_read(struct rw_semaphore *);
extern void up_read(struct rw_semaphore *);

#define __user