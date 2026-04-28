#include <stdlib.h>

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
        unsigned int len;
    } c;
};

#define CAST(t, v) ((t)(v))
#define protected static
#define COND_NONE 0

void file_oomem(struct magic_set *ms, size_t len);