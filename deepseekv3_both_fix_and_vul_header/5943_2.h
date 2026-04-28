#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DNS_ERRORNO_OPTION "dnserror"
#define GFP_KERNEL 0
#define KERN_WARNING
#define EINVAL (-22)
#define ENOMEM (-12)

struct key {
    int serial;
    char *description;
    union {
        long x[1];
    } type_data;
    struct {
        void *data;
    } payload;
};

struct user_key_payload {
    size_t datalen;
    char data[];
};

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *p) { free(p); }
static inline int strict_strtoul(const char *s, unsigned int base, unsigned long *res) { 
    char *end; 
    *res = strtoul(s, &end, base); 
    return (s == end) ? -EINVAL : 0; 
}

#define kenter(fmt, ...)
#define kdebug(fmt, ...)
#define kleave(fmt, ...)
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define rcu_assign_pointer(ptr, val) ((ptr) = (val))
static inline int key_payload_reserve(struct key *key, size_t datalen) { return 0; }