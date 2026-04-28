#include <stdbool.h>
#include <string.h>

typedef int MatchDomainNameFlags;
#define mdnRejectSubsubDomains 1
#define mdnHonorWildcards 2

static inline int xtolower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}