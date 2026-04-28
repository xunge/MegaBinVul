#include <stddef.h>
#include <string.h>
#include <stdbool.h>

struct key {
    unsigned long flags;
    union {
        void *data[1];
    } payload;
    long expiry;
};

struct key_preparsed_payload {
    const void *data;
    size_t datalen;
};

struct user_key_payload {
    size_t datalen;
    char data[];
};

#define KEY_FLAG_NEGATIVE 0
#define EINVAL 22
#define ENOMEM 12
#define GFP_KERNEL 0

void *malloc(size_t size);
void free(void *ptr);
void *memcpy(void *dest, const void *src, size_t n);
int key_payload_reserve(struct key *key, size_t datalen);
void rcu_assign_keypointer(struct key *key, struct user_key_payload *payload);
bool test_bit(int nr, const volatile unsigned long *addr);

#define kmalloc(size, flags) malloc(size)
#define kfree_rcu(ptr, rcu) free(ptr)