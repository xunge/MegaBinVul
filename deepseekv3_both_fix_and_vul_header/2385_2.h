#include <stddef.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

typedef struct key *key_ref_t;

struct key_preparsed_payload {
    const void *data;
    size_t datalen;
    size_t quotalen;
    time_t expiry;
};

struct rw_semaphore {
    int dummy;
};

struct key_type {
    size_t def_datalen;
    int (*preparse)(struct key_preparsed_payload *prep);
    void (*free_preparse)(struct key_preparsed_payload *prep);
    int (*update)(struct key *key, struct key_preparsed_payload *prep);
};

struct key {
    struct key_type *type;
    unsigned long flags;
    struct rw_semaphore sem;
};

#define KEY_NEED_WRITE 0x00000001
#define KEY_FLAG_NEGATIVE 0
#define TIME_T_MAX INT64_MAX
#define EOPNOTSUPP 95

void key_check(const struct key *key);
int key_permission(key_ref_t key_ref, unsigned int perm);
struct key *key_ref_to_ptr(key_ref_t key_ref);
void down_write(struct rw_semaphore *sem);
void up_write(struct rw_semaphore *sem);
void clear_bit(int nr, volatile unsigned long *addr);