#include <stddef.h>

struct level_info {
    int got_match;
#ifdef ENABLE_CONDITIONALS
    int last_match;
    int last_cond;
#endif
};

struct magic_set {
    struct {
        struct level_info *li;
        size_t len;
    } c;
};

#define CAST(type, value) ((type)(value))
#define protected static

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern void file_oomem(struct magic_set *, size_t);

#ifdef ENABLE_CONDITIONALS
#define COND_NONE 0
#endif