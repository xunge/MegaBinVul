#include <stddef.h>
#include <string.h>
#include <errno.h>

#define ENOKEY ENOENT
#define GFP_KERNEL 0
#define KEY_FLAG_NEGATIVE 0

struct key {
    unsigned long flags;
    union {
        void *data[2];
    } payload;
};

struct key_preparsed_payload {
    const void *data;
    size_t datalen;
};

struct encrypted_key_payload {
    char *master_desc;
    char *format;
    size_t datalen;
    size_t payload_datalen;
    char *payload_data;
    char iv[16];
    struct rcu_head {
        struct rcu_head *next;
        void (*func)(struct rcu_head *head);
    } rcu;
};

static size_t ivsize = 16;

static inline int test_bit(int nr, const volatile unsigned long *addr) {
    return (*addr >> nr) & 1;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))

extern int datablob_parse(char *buf, const char **format, char **master_desc, char **decrypted_data, size_t *decrypted_datalen);
extern int valid_master_desc(const char *new_desc, const char *orig_desc);
extern struct encrypted_key_payload *encrypted_key_alloc(struct key *key, const char *format, const char *master_desc, size_t datalen);
extern void __ekey_init(struct encrypted_key_payload *epayload, const char *format, const char *master_desc, size_t datalen);
extern void rcu_assign_keypointer(struct key *key, struct encrypted_key_payload *epayload);
extern void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head));
extern void encrypted_rcu_free(struct rcu_head *head);