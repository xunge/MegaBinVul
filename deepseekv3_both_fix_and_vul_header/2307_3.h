#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef int32_t key_serial_t;
typedef void* key_ref_t;
#define __user

#define KEY_FLAG_NEGATIVE 0
#define KEY_NEED_READ 0
#define ENOKEY 0
#define EACCES 0
#define EOPNOTSUPP 0
#define IS_ERR(x) (0)

struct key {
    unsigned long flags;
    struct key_type *type;
    void *sem;
};

struct key_type {
    long (*read)(struct key *, char *, size_t);
};

key_ref_t lookup_user_key(key_serial_t, int, int);
struct key *key_ref_to_ptr(key_ref_t);
int test_bit(int, const volatile unsigned long *);
long key_permission(key_ref_t, int);
bool is_key_possessed(key_ref_t);
int key_validate(struct key *);
void key_put(struct key *);
void down_read(void *);
void up_read(void *);