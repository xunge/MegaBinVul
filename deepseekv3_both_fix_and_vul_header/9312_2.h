#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

struct rcu_head {
    struct rcu_head *next;
    void (*func)(struct rcu_head *head);
};

struct trusted_key_payload {
    unsigned char migratable;
    unsigned int key_len;
    struct rcu_head rcu;
    unsigned char key[];
};

struct trusted_key_options {
    unsigned int keyhandle;
    unsigned char *pcrlock;
};

struct key {
    unsigned long flags;
    union {
        void *data[0];
    } payload;
};

struct key_preparsed_payload {
    size_t datalen;
    void *data;
};

enum {
    Opt_update
};

#define KEY_FLAG_NEGATIVE    0x00000001
#define GFP_KERNEL           0
#define ENOKEY               126
#define EPERM                1
#define EINVAL               22
#define ENOMEM               12

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int test_bit(int nr, const volatile unsigned long *addr) { return (*addr >> nr) & 1; }
static inline void pr_info(const char *fmt, ...) { 
    va_list args; 
    va_start(args, fmt); 
    vprintf(fmt, args); 
    va_end(args); 
}

extern struct trusted_key_payload *trusted_payload_alloc(struct key *key);
extern struct trusted_key_options *trusted_options_alloc(void);
extern int datablob_parse(char *datablob, struct trusted_key_payload *p, struct trusted_key_options *o);
extern int key_seal(struct trusted_key_payload *p, struct trusted_key_options *o);
extern int pcrlock(unsigned char *pcrlock);
extern void dump_payload(struct trusted_key_payload *p);
extern void trusted_rcu_free(struct rcu_head *rcu);
extern void rcu_assign_keypointer(struct key *key, struct trusted_key_payload *p);
extern void call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *head));