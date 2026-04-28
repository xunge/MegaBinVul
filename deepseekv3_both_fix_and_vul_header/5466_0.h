#include <stddef.h>
#include <limits.h>

#define _GL_ATTRIBUTE_PURE __attribute__ ((__pure__))
#define U(c) ((unsigned char) (c))

typedef struct kwset *kwset_t;
struct kwset {
    int mind;
    char const *trans;
    unsigned char const *delta;
    char const *target;
    char gc1;
    char gc2;
};

extern char *memchr_kwset(char const *, size_t, kwset_t);
extern int bm_delta2_search(char const **, char const *, char const *, int, char const *, char, char, unsigned char const *, kwset_t);