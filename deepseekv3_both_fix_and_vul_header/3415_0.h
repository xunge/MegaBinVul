#include <string.h>
#include <stdlib.h>

typedef unsigned int u32;
typedef unsigned int gfp_t;

#define SECINITSID_NUM 32
#define SECINITSID_KERNEL 1
#define SECSID_NULL 0
#define EINVAL 22
#define ENOMEM 12

struct context {
    char *str;
    u32 len;
};

struct sidtab;
struct policydb;

extern int ss_initialized;
extern char *initial_sid_to_string[];
extern struct sidtab sidtab;
extern struct policydb policydb;
extern struct rwlock policy_rwlock;

void context_destroy(struct context *c);
int string_to_context_struct(struct policydb *p, struct sidtab *s, char *str, u32 len, struct context *ctx, u32 def_sid);
int sidtab_context_to_sid(struct sidtab *s, struct context *ctx, u32 *sid);
void read_lock(struct rwlock *lock);
void read_unlock(struct rwlock *lock);
void *kmalloc(size_t size, gfp_t flags);
void kfree(const void *objp);
char *kstrdup(const char *s, gfp_t gfp);